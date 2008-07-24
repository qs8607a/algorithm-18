#if !defined( CPP_RANGE_RANGE_ITERATOR_HPP )
#define CPP_RANGE_RANGE_ITERATOR_HPP

#include <cpp/range/eval_if.hpp>
#include <cpp/range/range_const_iterator.hpp>
#include <cpp/range/range_mutable_iterator.hpp>
#include <cpp/range/is_const.hpp>
#include <cpp/range/remove_const.hpp>

namespace cpp {

template<typename T>
struct range_iterator
{
    typedef typename 
        eval_if< is_const<T>::value
                        , typename range_const_iterator<typename remove_const<T>::type>::type
                        , typename range_mutable_iterator<T>::type
        >::type type;

};
    
}

#endif /* CPP_RANGE_RANGE_ITERATOR_HPP */
