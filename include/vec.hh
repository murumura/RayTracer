#ifndef VEC_H
#define VEC_H
/*
Take a look at: Making std::vector constexpr
http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p1004r0.pdf
*/
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
class Vector final : private tuple_constants, private colour_constants {
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

	constexpr Vector(std::initializer_list<T> lst) : contents{initializer_list_to_array<T, N>(lst)} {}

	~Vector() = default;
	constexpr Vector &operator=(const Vector &other) = default;
	constexpr Vector &operator=(Vector &&other) noexcept = default;
	constexpr const T operator[](size_t index) const noexcept{
		return contents[index];
	}
	constexpr Vector operator+(const Vector &other) const noexcept{
		return Vector {contents + other.contents};
	}
	constexpr Vector operator+(const Type scalar) const noexcept;
	constexpr Vector operator-(const Vector &other) const noexcept;
	constexpr Vector operator-(const Type scalar) const noexcept;
	constexpr Vector operator*(const Vector &other) const noexcept;
	constexpr Vector operator*(const Type scalar) const noexcept;
	constexpr Vector operator/(const Vector &other) const noexcept;
	constexpr Vector operator/(const Type scalar) const noexcept;
	constexpr Vector operator+() const noexcept;
	constexpr Vector operator-() const noexcept;
	constexpr Vector operator==(const Vector &other) const noexcept{
		for (auto it1 = contents.cbegin(), it2 = other.contents.cbegin(); it1 != contents.cend(); ++it1, ++it2)
                if (!almost_equal(*it1, *it2))
                    return false;
        return true;
	}
	
}; //class Vector
} // namespace RayTracer
#endif