#if !defined( CPP_RANGE_EVAL_IF_HPP )
#define CPP_RANGE_EVAL_IF_HPP

namespace cpp {

template<bool B>
struct if_impl
{
    template<typename T1, typename T2>
    struct result_
    {
        typedef T1      type;
    };
};
template<>
struct if_impl<false>
{
    template<typename T1, typename T2>
    struct result_
    {
        typedef T2      type;
    };
};

template<bool B, typename T1, typename T2>
struct if_c
{
    typedef typename if_impl<B>::template result_<T1, T2>::type      type;
};


template<bool B, typename T1, typename T2>
struct eval_if
{
    typedef typename if_c<B, T1, T2>::type   type;
};


}

#endif /* CPP_RANGE_EVAL_IF_HPP */
