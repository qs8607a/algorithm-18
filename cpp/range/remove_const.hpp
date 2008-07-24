#if !defined( CPP_RANGE_REMOVE_CONST_HPP )
#define CPP_RANGE_REMOVE_CONST_HPP

#include <cpp/range/config.hpp>

namespace cpp { 

namespace detail {

    template<typename T> struct cv_traits_impl { };

    template<typename T>
    struct cv_traits_impl<T*>
    {
        STATIC_CONSTANT(bool, is_const = false);
        STATIC_CONSTANT(bool, is_volatile = false);

        typedef T   unqualified_type;
    };

    template<typename T>
    struct cv_traits_impl<T const*>
    {
        STATIC_CONSTANT(bool, is_const = true);
        STATIC_CONSTANT(bool, is_volatile = false);

        typedef T   unqualified_type;
    };

    template<typename T>
    struct cv_traits_impl<T volatile*>
    {
        STATIC_CONSTANT(bool, is_const = false);
        STATIC_CONSTANT(bool, is_volatile = true);

        typedef T   unqualified_type;
    };

    template<typename T>
    struct cv_traits_impl<T const volatile*>
    {
        STATIC_CONSTANT(bool, is_const = true);
        STATIC_CONSTANT(bool, is_volatile = true);

        typedef T   unqualified_type;
    };

    template<typename T, bool Is_volatile>
    struct remove_const_helper
    {
        typedef T   type;
    };

    template<typename T>
    struct remove_const_helper<T, true>
    {
        typedef T volatile  type;
    };

    template<typename T>
    struct remove_const_impl
    {
        typedef typename remove_const_helper<
                typename cv_traits_impl<T*>::unqualified_type
            ,   cv_traits_impl<T*>::is_volatile
        >::type type;
    };
} 

template<typename T>
struct remove_const
{
    typedef typename detail::remove_const_impl<T>::type     type;
};

}

#endif /* CPP_RANGE_REMOVE_CONST_HPP */
