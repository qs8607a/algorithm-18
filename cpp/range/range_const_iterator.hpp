#if !defined( CPP_RANGE_RANGE_CONST_ITERATOR_HPP )
#define CPP_RANGE_RANGE_CONST_ITERATOR_HPP

#include <cstddef>

namespace cpp {

template<typename T>
struct range_const_iterator
{
    typedef typename T::const_iterator      type;
};
template<typename T, std::size_t sz>
struct range_const_iterator<T[sz]>
{
    typedef T const*      type;
};

}

#endif /* CPP_RANGE_RANGE_CONST_ITERATOR_HPP */
