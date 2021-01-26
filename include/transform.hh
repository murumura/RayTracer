#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <array>
#include <functional>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <utility>
namespace raytracer::transform {
    namespace internals {
        template <typename T, size_t N, size_t... Indices>
        constexpr std::array<T, N> initializer_list_to_array_helper(const std::initializer_list<T> list, std::index_sequence<Indices...>)
        {
            return {{list.begin()[Indices]...}};
        }
} //namespace internals
    template <typename T, size_t N>
    constexpr std::array<T, N> initializer_list_to_array(const std::initializer_list<T> list)
    {
        return internals::initializer_list_to_array_helper<T, N>(list, std::make_index_sequence<N>{});
    }
} // namespace raytracer::transform
#endif