#if !defined( CPP_RANGE_IS_REFERENCE_HPP )
#define CPP_RANGE_IS_REFERENCE_HPP

#include <cpp/range/config.hpp>
#include <cpp/range/yes_no_type.hpp>
#include <cpp/range/wrap.hpp>

namespace cpp {

namespace detail {

using ::cpp::yes_type;
using ::cpp::no_type;
using ::cpp::wrap;

template<class T> T&(* is_reference_helper1(wrap<T>) )(wrap<T>);
char is_reference_helper1(...);

template<class T> no_type is_reference_helper2(T&(*)(wrap<T>));
yes_type is_reference_helper2(...);

template<typename T>
struct is_reference_impl
{
    STATIC_CONSTANT(
        bool, value = sizeof(
            ::cpp::detail::is_reference_helper2(
                ::cpp::detail::is_reference_helper1( ::cpp::wrap<T>() )
            )
        ) == 1
    );
};

}

template<typename T>
struct is_reference
{
    STATIC_CONSTANT( bool, value = ::cpp::detail::is_reference_impl<T>::value );
};

template<>
struct is_reference<void>
{
    STATIC_CONSTANT( bool, value = false );
};

}

#endif /* CPP_RANGE_IS_REFERENCE_HPP */
