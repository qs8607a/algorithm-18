#if !defined( CPP_RANGE_BEGIN_HPP )
#define CPP_RANGE_BEGIN_HPP

#include <cpp/range/range_iterator.hpp>

namespace cpp {

namespace detail {

template<class T>
inline typename cpp::range_iterator<T>::type range_begin(T& t)
{
    return t.begin();
}

template<typename T, std::size_t Size>
inline T* range_begin(T (&array)[Size])
{
    return array;
}
}

template<typename T>
inline typename range_iterator<T>::type begin(T& r)
{
    return detail::range_begin( r );
}
template<class T>
inline typename range_iterator<const T>::type begin(T const& r)
{
    return detail::range_begin( r );
}

}

#endif /* CPP_RANGE_BEGIN_HPP */
