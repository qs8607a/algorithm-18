#if !defined( CPP_RANGE_IS_ARRAY_HPP )
#define CPP_RANGE_IS_ARRAY_HPP

#include <cpp/range/config.hpp>
#include <cpp/range/yes_no_type.hpp>
#include <cpp/range/wrap.hpp>

namespace cpp {

namespace detail {

using ::cpp::yes_type;
using ::cpp::no_type;
using ::cpp::wrap;

template<typename T> T( * is_array_helper1( wrap<T> ) )( wrap<T> );
char is_array_helper1(...);

template<typename T> no_type is_array_helper2( T( * ) ( wrap<T> ) );
yes_type is_array_helper2(...);

template<typename T>
struct is_array_impl
{
    STATIC_CONSTANT(
        bool, value = sizeof(
            ::cpp::detail::is_array_helper2(
                    ::cpp::detail::is_array_helper1(
                            ::cpp::wrap<T>()
                    )
            )
        ) == 1
    );
};

} // namespace detail

template<typename T>
struct is_array
{
    STATIC_CONSTANT( bool, value = ::cpp::detail::is_array_impl<T>::value );
};
    
}

#endif /* CPP_RANGE_IS_ARRAY_HPP */
