#if !defined( CPP_RANGE_YES_NO_TYPE_HPP )
#define CPP_RANGE_YES_NO_TYPE_HPP

namespace cpp {

typedef char yes_type;
struct no_type
{
    char padding[8];
};

}

#endif /* CPP_RANGE_YES_NO_TYPE_HPP */
