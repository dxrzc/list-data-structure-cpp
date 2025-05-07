#pragma once

#include <iostream>
#include <utility>
#include <functional>

template <typename List, typename It>
concept IteratorLike = std::same_as<It, typename List::iterator>
|| std::same_as<It, typename List::const_iterator>
|| std::same_as<It, typename List::reverse_iterator>
|| std::same_as<It, typename List::const_reverse_iterator>;

template<class T>
class list
{
private:
	struct link;
	struct node;

public:
	class iterator;
	class const_iterator;
	class reverse_iterator;
	class const_reverse_iterator;

private:
	link head;
	std::size_t nelms;

	// Allows to create the head cell if the type "T" does not have a default constructor	
	struct link
	{
		link* previous;
		link* next;

		link() : previous(nullptr), next(nullptr) {}

		link(link* prev, link* nxt)
			: previous(prev), next(nxt) {}

		link(const link& link)
		{
			previous = link.previous;
			next = link.next;
		}

		link& operator=(const link& link)
		{
			if (this != &link)
			{
				previous = link.previous;
				next = link.next;
			}
			return *this;
		}

		virtual ~link() {}
	};

	struct node : public link
	{
		T value;

		node() = delete;

		node(const T& value_, link* prev, link* nxt)
			: value(value_), link(prev, nxt) {}

		template<typename... Args>
		node(link* prev, link* nxt, Args&&...args)
			: link(prev, nxt), value(std::forward<Args>(args)...) {}
	};

	void deep_copy(const list& list)
	{
		link* cell = list.head.next;

		while (cell != &list.head)
		{
			node* full_cell = dynamic_cast<node*>(cell);

			if (!full_cell)
				throw std::logic_error("Unable to casting to node");

			push_back(full_cell->value);
			cell = cell->next;
		}
	}

	// pimpl technique
	class iterator_impl
	{
	private:
		link* linker;

	public:
		iterator_impl(link* linker_) : linker(linker_) {}
		iterator_impl(const iterator_impl& itImpl) : linker(itImpl.linker) {}

		iterator_impl& operator=(const iterator_impl& itImpl)
		{
			if (this != &itImpl)
				linker = itImpl.linker;
			return *this;
		}

		void advance()
		{
			linker = linker->next;
		}

		void go_back()
		{
			linker = linker->previous;
		}

		T& get_value()
		{
			node* node_ptr = dynamic_cast<node*>(linker);

			if (!node_ptr)
				throw std::runtime_error("Invalid pointer: Cannot dereference non-node object.");

			return node_ptr->value;
		}

		link* get_linker() const noexcept
		{
			return linker;
		}

		bool operator==(const iterator_impl& itImpl) const noexcept { return linker == itImpl.linker; }
	};

	// internal function to pop an element using an iterator
	template<class It>
	link* pop_position(It it)
	{
		if (empty())
			throw std::length_error("pop called on empty list");

		node* target = dynamic_cast<node*>(it.get_internal_linker());
		if (!target)
			throw std::runtime_error("pop called on head");

		link* it_linker = it.get_internal_linker();
		link* it_previous_linker = it_linker->previous;
		link* it_next_linker = it_linker->next;

		it_previous_linker->next = it_next_linker;
		it_next_linker->previous = it_previous_linker;

		delete target;
		--nelms;

		return it_next_linker;
	}

	// internal function to create an element using an iterator
	template<typename It, typename ...Args>
	link* emplace_at(It it, Args&& ...args)
	{
		link* it_linker = it.get_internal_linker();
		link* it_previous_linker = it_linker->previous;

		link* new_node = new node(it_previous_linker, it_linker, std::forward<Args>(args)...);
		it_previous_linker->next = new_node;
		it_linker->previous = new_node;

		++nelms;

		return new_node;
	}

	void swap_elements(link* first, link* second)
	{
		if (first == second)
			return;

		if (first == &head || second == &head)
			throw std::invalid_argument("You cant swap head");

		link* first_previous_linker = first->previous;
		link* first_next_linker = first->next;

		link* second_previous_linker = second->previous;
		link* second_next_linker = second->next;

		// assuming "--[a]--[b]--"
		auto swap_contiguos_cells = [](link* a, link* b) -> void
		{
			link* prev_a = a->previous;
			link* next_b = b->next;

			prev_a->next = b;
			next_b->previous = a;

			b->next = a;
			b->previous = prev_a;
			a->previous = b;
			a->next = next_b;
		};

		if (first->next == second)
		{
			swap_contiguos_cells(first, second);
		}
		else if (second->next == first)
		{
			swap_contiguos_cells(second, first);
		}
		else
		{
			first_previous_linker->next = second;
			first_next_linker->previous = second;
			second->next = first_next_linker;
			second->previous = first_previous_linker;

			second_previous_linker->next = first;
			second_next_linker->previous = first;

			first->next = second_next_linker;
			first->previous = second_previous_linker;
		}
	}

	link* find_value(const T& value)
	{
		link* current_cell = head.next;

		while (current_cell != &head)
		{
			if (static_cast<node*>(current_cell)->value == value)
				return current_cell;
			else
				current_cell = current_cell->next;
		}

		return nullptr;
	}

public:
	template<class NoReverseIt>
		requires std::same_as<NoReverseIt, iterator> || std::same_as<NoReverseIt, const_iterator>
	list(NoReverseIt begin, NoReverseIt end) : list()
	{
		while (begin != end)
		{
			push_back(*begin);
			++begin;
		}
	}

	list()
	{
		head.next = &head;
		head.previous = &head;
		nelms = 0;
	}

	list(const std::initializer_list<T>& list) : list()
	{
		for (const T& e : list)
			push_back(e);
	}

	list(const list& list) : list()
	{
		deep_copy(list);
	}

	list& operator=(const list& list)
	{
		if (this != &list)
		{
			clear();
			deep_copy(list);
		}

		return *this;
	}

	bool operator==(const list& list) const noexcept
	{
		link* thislist = head.next;
		link* arglist = list.head.next;

		if (size() != list.size())
			return false;

		if (empty() && list.empty())
			return true;

		while (thislist != &head && arglist != &list.head)
		{
			if ((static_cast<node*>(thislist)->value) != (static_cast<node*>(arglist)->value))
				return false;
			thislist = thislist->next;
			arglist = arglist->next;
		}

		return true;
	}

	list(list&& list) noexcept
	{
		nelms = list.nelms;
		head.next = list.head.next;
		head.previous = list.head.previous;
		list.head.previous->next = &head;
		list.head.next->previous = &head;
		list.head.next = &list.head;
		list.head.previous = &list.head;
		list.nelms = 0;
	}

	/*
	* @brief Constructs the type and inserts it at the end of the list.
	* @param args The arguments to forward to the constructor of the new element.
	*/
	template <typename... Args>
	void emplace_back(Args &&...args)
	{
		node* new_node = new node(head.previous, &head, std::forward<Args>(args)...);
		head.previous->next = new_node;
		head.previous = new_node;
		++nelms;
	}

	/*
	* @brief Inserts a new element at the end of the list
	*/
	void push_back(const T& new_value)
	{
		emplace_back(new_value);
	}

	void push_back(T&& newvalue)
	{
		emplace_back(std::move(newvalue));
	}

	/*
	* @brief Constructs the type and inserts it at the front of the list.
	* @param args The arguments to forward to the constructor of the new element.
	*/
	template<typename... Args>
	void emplace_front(Args&& ...args)
	{
		node* new_node = new node(&head, head.next, std::forward<Args>(args)...);
		head.next->previous = new_node;
		head.next = new_node;
		++nelms;
	}

	/*
	* @brief Inserts a new element at the front of the list.
	*/
	void push_front(const T& new_value)
	{
		emplace_front(new_value);
	}

	void push_front(T&& newvalue)
	{
		emplace_front(std::move(newvalue));
	}

	/*
	* @brief Deletes the last element.
	*/
	void pop_back()
	{
		if (empty())
			throw std::length_error("pop called on empty list");
		link* last = head.previous;
		last->previous->next = &head;
		head.previous = last->previous;
		delete last;
		--nelms;
	}

	/*
	* @brief Deletes the first element.
	*/
	void pop_front()
	{
		if (empty())
			throw std::length_error("pop called on empty list");
		link* front = head.next;
		head.next = front->next;
		front->next->previous = &head;
		delete front;
		--nelms;
	}

	[[nodiscard]] std::size_t size() const noexcept
	{
		return nelms;
	}

	[[nodiscard]] bool empty() const noexcept
	{
		return head.next == &head;
	}

	T& front()
	{
		if (empty())
			throw std::length_error("front called on empty list");
		return static_cast<node*>(head.next)->value;
	}

	T& back()
	{
		if (empty())
			throw std::length_error("back called on empty list");
		return static_cast<node*>(head.previous)->value;
	}

	const T& front() const
	{
		if (empty())
			throw std::length_error("front called on empty list");
		return static_cast<node*>(head.next)->value;
	}

	const T& back() const
	{
		if (empty())
			throw std::length_error("back called on empty list");
		return static_cast<node*>(head.previous)->value;
	}

	/*
	* @brief Deletes every element in the list.
	*/
	void clear()
	{
		link* aux = head.next;
		while (aux != &head)
		{
			node* target = static_cast<node*>(aux);
			aux = aux->next;
			delete target;
		}

		nelms = 0;
		head.next = &head;
		head.previous = &head;
	}

	class iterator
	{
	private:
		std::unique_ptr<iterator_impl> pimpl;

		link* get_internal_linker() const noexcept
		{
			return pimpl.get()->get_linker();
		}

	public:
		friend class list;
		using iterator_category = std::bidirectional_iterator_tag;
		using value_type = T;
		using difference_type = std::ptrdiff_t;
		using pointer = T*;
		using reference = T&;

		iterator() : pimpl(nullptr) {}
		iterator(link* linker) : pimpl(std::make_unique<iterator_impl>(linker)) {}
		iterator(const iterator& it) : pimpl(std::make_unique<iterator_impl>(*it.pimpl.get())) {}
		iterator(const reverse_iterator& revit) : pimpl(std::make_unique<iterator_impl>(*revit.pimpl.get())) {}

		iterator& operator=(const iterator& it)
		{
			if (this != &it)
			{
				if (!pimpl)
					pimpl = std::make_unique<iterator_impl>(*it.pimpl);
				else
					*pimpl.get() = *it.pimpl.get();
			}
			return *this;
		}

		iterator& operator++()
		{
			pimpl.get()->advance();
			return *this;
		}

		iterator operator++(int)
		{
			auto aux = *this;
			pimpl.get()->advance();
			return aux;
		}

		iterator& operator--()
		{
			pimpl.get()->go_back();
			return *this;
		}

		iterator operator--(int)
		{
			auto aux = *this;
			pimpl.get()->go_back();
			return aux;
		}

		T& operator*()
		{
			return pimpl.get()->get_value();
		}

		bool operator==(const iterator& it) const noexcept { return *(pimpl.get()) == *(it.pimpl.get()); }
	};

	[[nodiscard]] iterator begin()
	{
		return head.next;
	}

	[[nodiscard]] iterator end()
	{
		return &head;
	}

	class const_iterator
	{
	private:
		std::unique_ptr<iterator_impl> pimpl;

		link* get_internal_linker() const noexcept
		{
			return pimpl.get()->get_linker();
		}

	public:
		friend class list;
		using iterator_category = std::bidirectional_iterator_tag;
		using value_type = T;
		using difference_type = std::ptrdiff_t;
		using pointer = const T*;
		using reference = const T&;

		const_iterator() : pimpl(nullptr) {}
		const_iterator(const link* linker) :pimpl(std::make_unique<iterator_impl>(const_cast<link*>(linker))) {}
		const_iterator(const const_iterator& cit) : pimpl(std::make_unique<iterator_impl>(*(cit.pimpl.get()))) {}
		const_iterator(const reverse_iterator& revit) : pimpl(std::make_unique<iterator_impl>(*(revit.pimpl.get()))) {}
		const_iterator(const const_reverse_iterator& crevit) : pimpl(std::make_unique<iterator_impl>(*(crevit.pimpl.get()))) {}
		const_iterator(const iterator& it) :pimpl(std::make_unique<iterator_impl>(*(it.pimpl.get()))) {}

		const_iterator& operator=(const const_iterator& cit)
		{
			if (this != &cit)
			{
				if (!pimpl)
					pimpl = std::make_unique<iterator_impl>(*cit.pimpl);
				else
					*pimpl.get() = *cit.pimpl.get();
			}
			return *this;
		}

		const_iterator& operator++()
		{
			pimpl.get()->advance();
			return *this;
		}

		const_iterator operator++(int)
		{
			auto aux = *this;
			pimpl.get()->advance();
			return aux;
		}

		const_iterator& operator--()
		{
			pimpl.get()->go_back();
			return *this;
		}

		const_iterator operator--(int)
		{
			auto aux = *this;
			pimpl.get()->go_back();
			return aux;
		}

		const T& operator*() const
		{
			return pimpl.get()->get_value();
		}

		bool operator==(const const_iterator& cit) const noexcept { return *(pimpl.get()) == *(cit.pimpl.get()); }
	};

	[[nodiscard]] const_iterator cbegin() const
	{
		return head.next;
	}

	[[nodiscard]] const_iterator cend() const
	{
		return &head;
	}

	[[nodiscard]] const_iterator begin() const
	{
		return head.next;
	}

	[[nodiscard]] const_iterator end() const
	{
		return &head;
	}

	class reverse_iterator
	{
	private:
		std::unique_ptr<iterator_impl> pimpl;

		link* get_internal_linker() const noexcept
		{
			return pimpl.get()->get_linker();
		}

	public:
		friend class list;
		using iterator_category = std::bidirectional_iterator_tag;
		using value_type = T;
		using difference_type = std::ptrdiff_t;
		using pointer = T*;
		using reference = T&;

		reverse_iterator() : pimpl(nullptr) {}
		reverse_iterator(link* linker) :pimpl(std::make_unique<iterator_impl>(const_cast<link*>(linker))) {}
		reverse_iterator(const iterator& it) :pimpl(std::make_unique<iterator_impl>(*(it.pimpl.get()))) {}
		reverse_iterator(const reverse_iterator& revit) : pimpl(std::make_unique<iterator_impl>(*(revit.pimpl.get()))) {}

		reverse_iterator& operator=(const reverse_iterator& revit)
		{
			if (this != &revit)
			{
				if (!pimpl)
					pimpl = std::make_unique<iterator_impl>(*revit.pimpl);
				else
					*pimpl.get() = *revit.pimpl.get();
			}
			return *this;
		}

		reverse_iterator& operator++()
		{
			pimpl.get()->go_back();
			return *this;
		}

		reverse_iterator operator++(int)
		{
			auto aux = *this;
			pimpl.get()->go_back();
			return aux;
		}

		reverse_iterator& operator--()
		{
			pimpl.get()->advance();
			return *this;
		}

		reverse_iterator operator--(int)
		{
			auto aux = *this;
			pimpl.get()->advance();
			return aux;
		}

		T& operator*() const
		{
			return pimpl.get()->get_value();
		}

		bool operator==(const reverse_iterator& revit) const noexcept { return *(pimpl.get()) == *(revit.pimpl.get()); }
		bool operator==(const iterator& it) const noexcept { return *(pimpl.get()) == *(it.pimpl.get()); }
		bool operator==(const const_iterator& cit) const noexcept { return  *(pimpl.get()) == *(cit.pimpl.get()); }
	};

	[[nodiscard]] reverse_iterator rbegin()
	{
		return head.previous;
	}

	[[nodiscard]] reverse_iterator rend()
	{
		return &head;
	}

	class const_reverse_iterator
	{
	private:
		std::unique_ptr<iterator_impl> pimpl;

		link* get_internal_linker() const noexcept
		{
			return pimpl.get()->get_linker();
		}

	public:
		friend class list;
		using iterator_category = std::bidirectional_iterator_tag;
		using value_type = T;
		using difference_type = std::ptrdiff_t;
		using pointer = const T*;
		using reference = const T&;

		const_reverse_iterator() : pimpl(nullptr) {}
		const_reverse_iterator(const link* linker) :pimpl(std::make_unique<iterator_impl>(const_cast<link*>(linker))) {}
		const_reverse_iterator(const iterator& it) :pimpl(std::make_unique<iterator_impl>(*(it.pimpl.get()))) {}
		const_reverse_iterator(const const_iterator& cit) :pimpl(std::make_unique<iterator_impl>(*(cit.pimpl.get()))) {}
		const_reverse_iterator(const reverse_iterator& revit) : pimpl(std::make_unique<iterator_impl>(*(revit.pimpl.get()))) {}
		const_reverse_iterator(const const_reverse_iterator& crevit) : pimpl(std::make_unique<iterator_impl>(*(crevit.pimpl.get()))) {}

		const_reverse_iterator& operator=(const const_reverse_iterator& crevit)
		{
			if (this != &crevit)
			{
				if (!pimpl)
					pimpl = std::make_unique<iterator_impl>(*crevit.pimpl);
				else
					*pimpl.get() = *crevit.pimpl.get();
			}
			return *this;
		}

		const_reverse_iterator& operator++()
		{
			pimpl.get()->go_back();
			return *this;
		}

		const_reverse_iterator operator++(int)
		{
			auto aux = *this;
			pimpl.get()->go_back();
			return aux;
		}

		const_reverse_iterator& operator--()
		{
			pimpl.get()->advance();
			return *this;
		}

		const_reverse_iterator operator--(int)
		{
			auto aux = *this;
			pimpl.get()->advance();
			return aux;
		}

		const T& operator*() const
		{
			return pimpl.get()->get_value();
		}

		bool operator==(const const_reverse_iterator& crevit) const noexcept { return *(pimpl.get()) == *(crevit.pimpl.get()); }
		bool operator==(const reverse_iterator& revit) const noexcept { return *(pimpl.get()) == *(revit.pimpl.get()); }
		bool operator==(const iterator& it) const noexcept { return *(pimpl.get()) == *(it.pimpl.get()); }
		bool operator==(const const_iterator& cit) const noexcept { return  *(pimpl.get()) == *(cit.pimpl.get()); }
	};

	[[nodiscard]] const_reverse_iterator crbegin() const
	{
		return head.previous;
	}

	[[nodiscard]] const_reverse_iterator crend() const
	{
		return &head;
	}

	/*
	* @brief Constructs and inserts a new element at the specified position.
	* @param it The iterator position where the new element will be created and inserted.
	* @param args The arguments to forward to the constructor of the new element.
	* @return An iterator pointing to the newly constructed element.
	*/
	template<typename It, typename ...Args>
		requires IteratorLike<list, It>
	It emplace(It it, Args&& ... args)
	{
		return emplace_at<It>(it, std::forward<Args>(args)...);
	}

	/*
	* @brief Removes the element at the specified position.
	* @param it The iterator pointing to the element to be removed.
	* @return An iterator pointing to the element following the removed element.
	*/
	template<typename It>
		requires IteratorLike<list, It>
	It pop(It it)
	{
		return pop_position<It>(it);
	}

	/*
	* @brief Inserts a new element at the specified position in the list.
	* @param it The iterator position where the new element will be inserted
	* @param new_value The value to insert into the list.
	* @return An iterator pointing to the newly inserted element.
	*/
	template<typename It>
		requires IteratorLike<list, It>
	It insert(It it, const T& newvalue)
	{
		return emplace<It>(it, newvalue);
	}

	template<typename It>
		requires IteratorLike<list, It>
	It insert(It it, T&& new_value)
	{
		return emplace<It>(it, std::move(new_value));
	}

	/*
	* @brief Removes elements from the list that satisfy a specified condition.
	* @param condition The condition used to determine which elements to remove.
	* @returns The number of elements removed.
	*/
	template<class Condition>
	std::size_t remove_if(Condition condition)
	{
		std::size_t total_removed = 0;
		auto it = cbegin();

		while (it != cend())
		{
			if (condition(*it))
			{
				it = pop(it);
				++total_removed;
			}
			else
				++it;
		}

		return total_removed;
	}

	/*
	* @brief Splices another list into this list at a specified position.
	* @param where where The position iterator in this list where the elements of `rightlist` will be inserted.
	* @param rightlist The list to be spliced into this list. It will be empty after this operation.
	*/
	template<typename It>
		requires IteratorLike<list, It>
	void splice(It where, list& rightlist)
	{
		link* lnk = where.get_internal_linker();
		link* nextE = lnk->next;

		lnk->next = rightlist.head.next;
		rightlist.head.next->previous = lnk;

		nextE->previous = rightlist.head.previous;
		rightlist.head.previous->next = nextE;

		nelms += rightlist.size();
		rightlist.head.next = &rightlist.head;
		rightlist.head.previous = &rightlist.head;
		rightlist.nelms = 0;
	}

	void sort()
	{
		if (empty() || nelms == 1)
			return;

		auto get_linker_at = [&](std::size_t pos)-> link*
		{
			const_iterator it = cbegin();
			std::advance(it, pos);
			return it.get_internal_linker();
		};

		auto median_of_three = [&](std::size_t a, std::size_t b, std::size_t c)
		{
			if ((a <= b && b <= c) || (c <= b && b <= a))
				return b;
			else if ((b <= a && a <= c) || (c <= a && a <= b))
				return a;
			else
				return c;
		};

		std::function<void(std::size_t, std::size_t)> quick_sort = [&](std::size_t begin, std::size_t last)
		{
			if (begin < last)
			{
				const std::size_t pivotIndex = median_of_three(begin, (begin + last) / 2, last);
				link* pivotlinker = get_linker_at(pivotIndex);
				const auto& pivotValue = static_cast<node*>(pivotlinker)->value;

				link* lastlinker = get_linker_at(last);

				swap_elements(pivotlinker, lastlinker);

				std::size_t tracker = begin;

				for (std::size_t i = begin; i < last; i++)
				{
					if (static_cast<node*>(get_linker_at(i))->value < pivotValue)
					{
						swap_elements(get_linker_at(i), get_linker_at(tracker));
						++tracker;
					}
				}

				swap_elements(get_linker_at(tracker), get_linker_at(last));
				if (tracker != 0)
					quick_sort(begin, tracker - 1);
				quick_sort(tracker + 1, last);
			}
		};

		quick_sort(0, std::size_t(nelms - 1));
	}

	/**
	* @brief Finds the first occurrence of an element with the specified value in the list.
	* @param value The value to search for within the list.
	* @return iterator An iterator to the first node containing the specified value,
	* or an iterator to the end of the list if the value is not found.
	*/
	iterator find(const T& value)
	{
		link* cell = find_value(value);
		if (cell)
			return cell;
		else
			return end();
	}

	const_iterator find(const T& value) const
	{
		link* cell = find_value(value);
		if (cell)
			return cell;
		else
			return cend();
	}

	/*
	* @brief Checks if the list contains an element with the specified value.
	* @param value The value to search for within the list.
	* @return bool `true` if the value is found in the list; `false` otherwise.
	*/
	bool contains(const T& value) const
	{
		link* current_cell = head.next;

		while (current_cell != &head)
		{
			if (static_cast<node*>(current_cell)->value == value)
				return true;
			else
				current_cell = current_cell->next;
		}

		return false;
	}

	void reverse()
	{
		link* first_node = head.next;

		while (first_node != &head)
		{
			link* previous = first_node->previous;
			first_node->previous = first_node->next;
			first_node->next = previous;
			// the next one is now the "previous"
			first_node = first_node->previous;
		}

		link* head_prev = head.previous;
		head.previous = head.next;
		head.next = head_prev;
	}
};
