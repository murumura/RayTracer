#ifndef VEC_H
#define VEC_H
#include <numeric>
#include "constmath.hh"
namespace RayTracer{
    struct tuple_constants {
        constexpr static int x = 0;
        constexpr static int y = 1;
        constexpr static int z = 2;
        constexpr static int w = 3;
        constexpr static double point_flag = 1;
        constexpr static double vector_flag = 0;
    };

    struct colour_constants {
        static constexpr int r = 0;
        static constexpr int g = 1;
        static constexpr int b = 2;
        static constexpr int maxvalue = 255;
    };
   template<typename T, size_t N,
            typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
        class Vector final: private tuple_constants, colour_constants{
            public:
            protected:
            public:
        };
}
#endif