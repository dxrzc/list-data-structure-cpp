
#define ASSERT_ITERATOR_STL_COMPAT(It)                            \
    static_assert(std::bidirectional_iterator<It>, #It " must satisfy std::bidirectional_iterator");   \
    static_assert(std::is_copy_constructible_v<It>, #It " must be copy constructible");                \
    static_assert(std::is_copy_assignable_v<It>, #It " must be copy assignable");                      \
    static_assert(std::equality_comparable<It>, #It " must be equality comparable");                   \
    static_assert(std::is_destructible_v<It>, #It " must be destructible");                            \
    static_assert(std::is_move_constructible_v<It>, #It " must be move constructible");