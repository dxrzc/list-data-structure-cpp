#pragma once

#include <type_traits>

template<typename It>
using dereference_returns_const_reference = std::conjunction<
	std::is_reference<decltype(*std::declval<It>())>,
	std::is_const<std::remove_reference_t<decltype(*std::declval<It>())>>
>;

template<typename It>
using dereference_returns_nonconst_reference = std::conjunction<
	std::is_reference<decltype(*std::declval<It>())>,
	std::negation<std::is_const<std::remove_reference_t<decltype(*std::declval<It>())>>>
>;

#define ASSERT_DEREFERENCE_RETURNS_CONST_REFERENCE(It) \
    static_assert(dereference_returns_const_reference<It>::value, #It " must return const T& on dereference");

#define ASSERT_DEREFERENCE_RETURNS_NONCONST_REFERENCE(It) \
    static_assert(dereference_returns_nonconst_reference<It>::value, #It " must return T& on dereference");