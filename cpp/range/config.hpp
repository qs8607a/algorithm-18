#if !defined( CPP_RANGE_CONFIG_HPP )
#define CPP_RANGE_CONFIG_HPP

// From boost BOOST_STATIC_CONSTANT
// On compilers which don't allow in-class initialization of static integral
// constant members, we must use enums as a workaround if we want the constants
// to be available at compile-time. This macro gives us a convenient way to
// declare such constants.

#  ifdef BOOST_NO_INCLASS_MEMBER_INITIALIZATION
#       define STATIC_CONSTANT(type, assignment) enum { assignment }
#  else
#     define STATIC_CONSTANT(type, assignment) static const type assignment
#  endif

#endif /* CPP_RANGE_CONFIG_HPP */
