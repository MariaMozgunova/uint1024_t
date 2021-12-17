#include "utils.c"

#include <gtest/gtest.h>

TEST(uint1024tTest, AddOpTest) {
    uint1024_t x;
    uint1024_t y;
    uint1024_t res;

    char str[309];

    x = from_uint(0);
    y = from_uint(0);
    res = add_op(&x, &y);
    num_to_str(&res, str);
    ASSERT_EQ(strcmp(str, "0"), 0) << "0 + 0 is not " << str;

    y = from_uint(245534091);
    res = add_op(&x, &y);
    num_to_str(&res, str);
    ASSERT_EQ(strcmp(str, "245534091"), 0) << "0 + 245534091 is not " << str;

    x = from_uint(8936633);
    res = add_op(&x, &y);
    num_to_str(&res, str);
    ASSERT_EQ(strcmp(str, "254470724"), 0) << "8936633 + 245534091 is not " << str;   
}

TEST(uint1024tTest, MultOpTest) {
    uint1024_t x;
    uint1024_t y;
    uint1024_t res;

    char str[309];

    x = from_uint(0);
    y = from_uint(0);
    res = mult_op(&x, &y);
    num_to_str(&res, str);
    ASSERT_EQ(strcmp(str, "0"), 0) << "0 * 0 is not " << str;

    y = from_uint(245534091);
    res = mult_op(&x, &y);
    num_to_str(&res, str);
    ASSERT_EQ(strcmp(str, "0"), 0) << "0 * 245534091 is not " << str;

    x = from_uint(8936633);
    res = mult_op(&x, &y);
    num_to_str(&res, str);
    ASSERT_EQ(strcmp(str, "2194248060255603"), 0) << "8936633 * 245534091 is not " << str;    
}

TEST(uint1024tTest, SubtrOpTest) {
    uint1024_t x;
    uint1024_t y;
    uint1024_t res;

    char str[309];

    x = from_uint(0);
    y = from_uint(0);
    res = subtr_op(&x, &y);
    num_to_str(&res, str);
    ASSERT_EQ(strcmp(str, "0"), 0) << "0 + 0 is not " << str;

    x = from_uint(245534091);
    res = subtr_op(&x, &y);
    num_to_str(&res, str);
    ASSERT_EQ(strcmp(str, "245534091"), 0) << "245534091 - 0 is not " << str;

    y = from_uint(8936633);
    res = subtr_op(&x, &y);
    num_to_str(&res, str);
    ASSERT_EQ(strcmp(str, "236597458"), 0) << "245534091 - 8936633 is not " << str;    
}

int main(int argc, char **argv) {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}