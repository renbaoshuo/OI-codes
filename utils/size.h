#include <cstddef>

/**
 * Get size of the given array.
 *
 * @param array An array
 * @return Size of the array
 */
template <class T, std::size_t N>
constexpr std::size_t size(const T (&array)[N]) noexcept {
    return N;
}

/**
 * Get size of the given container.
 *
 * @param c An container
 * @return Size of the container
 */
template <class C>
constexpr auto size(const C& c) -> decltype(c.size()) {
    return c.size();
}
