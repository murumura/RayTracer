#include "gmock/gmock.h"

#include "common.hh"
using namespace RayTracer; 
using namespace std;
using testing::Eq;

TEST(func_almost_equal_test, float_array_equal)
{
	array<float, 3> af = { 1.1, 2.2, 3.1 };
    array<float, 3> bf = { 1.1, 2.2, 3.1 };
    for (auto it1 = af.cbegin(), it2 = bf.cbegin(); it1 != af.cend(); ++it1, ++it2)
    {
        ASSERT_THAT(almost_equal(*it1, *it2), Eq(true));
    }
}

TEST(func_almost_equal_test, double_array_equal)
{
	array<double, 3> af = { 1.1, 2.2, 3.1 };
    array<double, 3> bf = { 1.1, 2.2, 3.1 };
    for (auto it1 = af.cbegin(), it2 = bf.cbegin(); it1 != af.cend(); ++it1, ++it2)
    {
        ASSERT_THAT(almost_equal(*it1, *it2), Eq(true));
    }
}