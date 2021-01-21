#ifndef VEC_H
#define VEC_H
#include <array>
#include <initializer_list>
#include <numeric>
#include <ostream>
#include <type_traits>

#include "constmath.hh"
namespace RayTracer {
struct tuple_constants {
	constexpr static int x = 0;
	constexpr static int y = 1;
	constexpr static int z = 2;
	constexpr static int w = 3;
	/** Here we follow the instructions in the book to regard flag=1 as points and flag=0 as vector */
	constexpr static double point_flag = 1;
	constexpr static double vector_flag = 0;
};

struct colour_constants {
	constexpr static int r = 0;
	constexpr static int g = 1;
	constexpr static int b = 2;
	constexpr static int maxvalue = 255;
};
template <typename T, size_t N,
          typename = typename std::enable_if_t<std::is_arithmetic_v<T>, T>>
class Vector final : private tuple_constants, colour_constants {
   public:
	using type = T;
	using vector_type = std::array<T, N>;
	using Colour = Vector<double, 3>;

   protected:
	vector_type contents;

   public:
	constexpr explicit Vector(const vector_type &contents) noexcept : contents{contents} {}
	constexpr explicit Vector(vector_type &&contents) noexcept : contents{std::move(contents)} {}
	constexpr Vector(const Vector &other) noexcept = default;
	constexpr Vector(Vector &&other) noexcept = default;
	~Vector() = default;
	constexpr Vector &operator=(const Vector &other) = default;
	constexpr Vector &operator=(Vector &&other) noexcept = default;
	constexpr const T operator[](size_t index) const noexcept
	{
		return contents[index];
	}
	/** For economically, implement + in terms of +=  */
	constexpr Vector &operator+=(const Vector &rhs) const noexcept
	{
		contents += rhs.contents;
		return *this;
	}
	constexpr Vector operator+(const Vector &other) const noexcept
	{
		Vector copy{*this};
		copy += other;
		return copy;
	}
	constexpr Vector &operator-=(const Vector &rhs) const noexcept
	{
		contents -= rhs.contents;
		return *this;
	}
	constexpr Vector operator-(const Vector &other) const noexcept
	{
		Vector copy{*this};
		copy -= other;
		return copy;
	}

};  //class Vector
}  // namespace RayTracer
#endif