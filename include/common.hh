#ifndef COMMON_H
#define COMMON_H
#include <numeric>
#include <type_traits>
#include <utility>
#include "constmath.hh"
#define EPSILON 1e-4

namespace RayTracer{
    
    template<typename S, typename T>
    constexpr typename std::enable_if_t<std::is_floating_point_v<S> || std::is_floating_point_v<T>, bool>
    almost_equal(S x, T y) {
        // We need special treatment for infinities here.
        if (x == std::numeric_limits<double>::infinity() && y == std::numeric_limits<double>::infinity())
            return true;
        if (x == -std::numeric_limits<double>::infinity() && y == -std::numeric_limits<double>::infinity())
            return true;
        return (math_details::constexpr_absd(x - y) < EPSILON);
    }
 
}
#endif