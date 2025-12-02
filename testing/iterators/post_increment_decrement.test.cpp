#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"

// Tests for post-increment/decrement operators
// These test that the return value is the original value before modification

TEST(post_increment_operator, iterator_should_return_original_value)
{
    intlist list{1, 2, 3};
    auto it = list.begin();
    
    auto original_value = *it;
    auto returned_it = it++;
    
    EXPECT_EQ(*returned_it, original_value);
    EXPECT_EQ(*returned_it, 1);
    EXPECT_EQ(*it, 2);
}

TEST(post_increment_operator, const_iterator_should_return_original_value)
{
    intlist list{1, 2, 3};
    auto it = list.cbegin();
    
    auto original_value = *it;
    auto returned_it = it++;
    
    EXPECT_EQ(*returned_it, original_value);
    EXPECT_EQ(*returned_it, 1);
    EXPECT_EQ(*it, 2);
}

TEST(post_increment_operator, reverse_iterator_should_return_original_value)
{
    intlist list{1, 2, 3};
    auto it = list.rbegin();
    
    auto original_value = *it;
    auto returned_it = it++;
    
    EXPECT_EQ(*returned_it, original_value);
    EXPECT_EQ(*returned_it, 3);
    EXPECT_EQ(*it, 2);
}

TEST(post_increment_operator, const_reverse_iterator_should_return_original_value)
{
    intlist list{1, 2, 3};
    auto it = list.crbegin();
    
    auto original_value = *it;
    auto returned_it = it++;
    
    EXPECT_EQ(*returned_it, original_value);
    EXPECT_EQ(*returned_it, 3);
    EXPECT_EQ(*it, 2);
}

TEST(post_decrement_operator, iterator_should_return_original_value)
{
    intlist list{1, 2, 3};
    auto it = list.end();
    --it;  // now at 3
    
    auto original_value = *it;
    auto returned_it = it--;
    
    EXPECT_EQ(*returned_it, original_value);
    EXPECT_EQ(*returned_it, 3);
    EXPECT_EQ(*it, 2);
}

TEST(post_decrement_operator, const_iterator_should_return_original_value)
{
    intlist list{1, 2, 3};
    auto it = list.cend();
    --it;  // now at 3
    
    auto original_value = *it;
    auto returned_it = it--;
    
    EXPECT_EQ(*returned_it, original_value);
    EXPECT_EQ(*returned_it, 3);
    EXPECT_EQ(*it, 2);
}

TEST(post_decrement_operator, reverse_iterator_should_return_original_value)
{
    intlist list{1, 2, 3};
    auto it = list.rend();
    --it;  // now at 1
    
    auto original_value = *it;
    auto returned_it = it--;
    
    EXPECT_EQ(*returned_it, original_value);
    EXPECT_EQ(*returned_it, 1);
    EXPECT_EQ(*it, 2);
}

TEST(post_decrement_operator, const_reverse_iterator_should_return_original_value)
{
    intlist list{1, 2, 3};
    auto it = list.crend();
    --it;  // now at 1
    
    auto original_value = *it;
    auto returned_it = it--;
    
    EXPECT_EQ(*returned_it, original_value);
    EXPECT_EQ(*returned_it, 1);
    EXPECT_EQ(*it, 2);
}
