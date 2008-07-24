#if !defined( CPP_ALGORITHM_FOR_EACH_HPP )
#define CPP_ALGORITHM_FOR_EACH_HPP

#include <algorithm>
#include <cpp/range.hpp>

namespace cpp {

/**
 *  @breif Apply a function to every element of a sequence.
 *  @param container    An input container.
 *  @param function     A unary function object.
 *  @return @p function
 *
 *  Applies the function object @p function to each element in the 
 *  container. @p function must not modify the order of the sequence.
 *  If @p function has a return value it is ignored.
 */
template<typename InputContainer, typename Function>
inline Function
for_each(InputContainer& container, Function function)
{
    return std::for_each( cpp::begin( container ), cpp::end( container ), function );
}

}

#endif /* CPP_ALGORITHM_FOR_EACH_HPP */
