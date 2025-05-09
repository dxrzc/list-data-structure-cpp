#pragma once

#define ASSERT_INTEROP(From, To)							\
    static_assert(std::is_assignable_v<From, To>);			\
    static_assert(std::is_constructible_v<From, To>);		\
	static_assert(std::is_convertible_v<To, From>);

#define ASSERT_NO_INTEROP(From, To)                         \
    static_assert(!std::is_assignable_v<From, To>);			\
    static_assert(!std::is_constructible_v<From, To>);		\
	static_assert(!std::is_convertible_v<To, From>);
