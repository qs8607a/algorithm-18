#if !defined( CPP_RANGE_IS_CONST_HPP )
#define CPP_RANGE_IS_CONST_HPP

#include <cpp/range/config.hpp>
#include <cpp/range/yes_no_type.hpp>
#include <cpp/range/wrap.hpp>
#include <cpp/range/is_reference.hpp>
#include <cpp/range/is_array.hpp>

namespace cpp {

namespace detail {

using ::cpp::yes_type;
using ::cpp::no_type;
using ::cpp::wrap;

yes_type is_const_helper1(const volatile void*);
no_type is_const_helper1(volatile void*);

template<bool is_ref, bool array>
struct is_const_helper2
{
    template<typename T>
    struct result_
    {
        STATIC_CONSTANT( bool, value = false );
    };
};

template<>
struct is_const_helper2<false, false>
{
    template<typename T> 
    struct result_
    {
        static T* t;
        STATIC_CONSTANT( bool
            , value = ( sizeof( yes_type ) == sizeof( detail::is_const_helper1( t ) ) )
        );
    };
};

template<>
struct is_const_helper2<false, true>
{
    template<typename T> 
    struct result_
    {
        static T t;
        STATIC_CONSTANT( bool
            , value = ( sizeof( yes_type ) == sizeof( detail::is_const_helper1( &t ) ) )
        );

    };
};

template<typename T>
struct is_const_impl
    : is_const_helper2<
            is_reference<T>::value
        ,   is_array<T>::value
    >::template result_<T>
{
};
    
} // namespace detail

template<typename T>
struct is_const
{
    STATIC_CONSTANT( bool, value = ::cpp::detail::is_const_impl<T>::value );
};
template<>
struct is_const<void>
{
    STATIC_CONSTANT( bool, value = false );
};

}

#endif /* CPP_RANGE_IS_CONST_HPP */
