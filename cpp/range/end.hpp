#if !defined( CPP_RANGE_END_HPP )
#define CPP_RANGE_END_HPP

#include <cpp/range/range_iterator.hpp>

namespace cpp {

namespace detail {

template<typename T>
inline typename cpp::range_iterator<T>::type
range_end(T& c)
{
    return c.end();
}
template<typename T, std::size_t Size>
inline T* range_end(T (&array)[Size])
{
    return array + Size;
}
template<typename T, std::size_t Size>
inline T const* range_end(const T (&array)[Size])
{
    return array + Size;
}

}

template<typename T>
inline typename cpp::range_iterator<T>::type
end(T& r)
{
    return detail::range_end( r );
}
template<typename T>
inline typename cpp::range_iterator<const T>::type
end(T const& r)
{
    return detail::range_end( r );
}
    
} // namespace cpp


#endif /* CPP_RANGE_END_HPP */
