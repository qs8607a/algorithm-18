#if !defined( CPP_RANGE_RANGE_MUTABLE_ITERATOR_HPP )
#define CPP_RANGE_RANGE_MUTABLE_ITERATOR_HPP

#include <cstddef>

namespace cpp {

template<typename T>
struct range_mutable_iterator
{
    typedef typename T::iterator    type;
};
template<typename T, std::size_t Size>
struct range_mutable_iterator<T[Size]>
{
    typedef T*  type;
};
    
}

#endif /* CPP_RANGE_RANGE_MUTABLE_ITERATOR_HPP */
