#pragma once

#define ASSERT_INTEROP(From, To) \
    static_assert(std::is_assignable_v<From, To>, #From " must be assignable from " #To); \
    static_assert(std::is_constructible_v<From, To>, #From " must be constructible from " #To); \
    static_assert(std::is_convertible_v<To, From>, #To " must be convertible to " #From);

#define ASSERT_NO_INTEROP(From, To) \
    static_assert(!std::is_assignable_v<From, To>, #From " must NOT be assignable from " #To); \
    static_assert(!std::is_constructible_v<From, To>, #From " must NOT be constructible from " #To); \
    static_assert(!std::is_convertible_v<To, From>, #To " must NOT be convertible to " #From);
