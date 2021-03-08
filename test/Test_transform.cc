#include "gmock/gmock.h"
#include "transform.hh"
#include "common.hh"
#include <type_traits>
using namespace RayTracer::transform; 
using namespace RayTracer::transform::internals;
using namespace std;
using testing::Eq;

TEST(func_initializer_list_to_array_helper, initializer_list_to_array_helper)
{
	constexpr int N = 5;
    auto arr = initializer_list_to_array_helper<int, N>({1,2,3,4,5}, std::make_index_sequence<N>{});
    bool res = std::is_same_v<int, std::decay_t<decltype(arr[0])>>;
    ASSERT_TRUE(res);
    ASSERT_THAT(arr.size(), Eq(N));
    int k = 1;
    for (auto it = std::begin(arr); it != std::end(arr); ++it){
        ASSERT_THAT(*it, Eq(k));
        k++;
    }
}

