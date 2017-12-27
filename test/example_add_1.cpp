#include "gtest/gtest.h"
#include "studentCode.h"

TEST(studentCode, add_1)
{
    double res;
    res = AdditionFunctionSolution(1.0, 2.0);
    ASSERT_NEAR(res, 3.0, 1.0e-11);
}
