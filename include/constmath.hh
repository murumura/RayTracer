#ifndef CONST_MATH_H
#define CONST_MATH_H
#include <cmath>
#include <numeric>
#include <limits>
namespace RayTracer {
    namespace math_constants {
        template <typename T = double>
            constexpr T pi = T(3.1415926535897932385L);
        template <typename T = double> 
            constexpr T inf = std::numeric_limits<T>::infinity();
        template <typename T = double> 
            constexpr T ninf = -std::numeric_limits<T>::infinity();
    };
    namespace math_details {
        /* constexpr absolute value of a floating point value. */
        template <typename T>
        constexpr typename std::enable_if_t<std::is_floating_point_v<T>, T>
        constexpr_absd(T val) {
            return val >= 0 ? val : -val;
        }
    }
}; // namespace RayTracer
#endif