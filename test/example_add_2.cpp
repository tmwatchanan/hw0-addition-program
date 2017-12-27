#include "gtest/gtest.h"
#include "studentCode.h"

TEST(studentCode, add_2)
{
    double res;
    res = AdditionFunctionStudent(-8, 77);
    ASSERT_NEAR(res, 69, 1.0e-11);
}
