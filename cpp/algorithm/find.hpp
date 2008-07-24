#if !defined( CPP_ALGORITHM_FIND_HPP )
#define CPP_ALGORITHM_FIND_HPP

#include <algorithm>
#include <cpp/range.hpp>

/**
 * @defgroup find find
 * @ingroup algorithm
 */

namespace cpp {


// ----------------------------------------------------------------------------

/**
 * @ingroup find
 * @brief Find the first occurrence of a value in a sequence.
 * @param range     Input range.
 * @param value     The value to find.
 * @return The first iterator @c i in the range @p range
 * such that @c  *i == @p value, or @c cpp::end( @p range )if no such
 * iterator exists.
 */
template<typename InputRange, typename T>
inline typename cpp::range_iterator<InputRange>::type 
find(InputRange& range, T const& value)
{
    return std::find( cpp::begin( range ), cpp::end( range ), value );
}

template<typename InputRange, typename T>
inline typename cpp::range_const_iterator<InputRange>::type 
find(InputRange const& range, T const& value)
{
    return std::find( cpp::begin( range ), cpp::end( range ), value );
}

// ----------------------------------------------------------------------------

/**
 * @ingroup find
 * @brief Find the first element in a sequence for which a predicate is true.
 * @param range     Input range.
 * @param p         A predicate.
  * @return The first iterator @c i in the range @p range
  * such that @p  p( *i ) is true, or @c cpp::end( @p range )if no such
  * iterator exists.
  */
template<typename InputRange, typename Predicate>
inline typename cpp::range_iterator<InputRange>::type 
find_if(InputRange& range, Predicate p)
{
    return std::find_if( cpp::begin( range ), cpp::end( range ), p );
}

template<typename InputRange, typename Predicate>
inline typename cpp::range_const_iterator<InputRange>::type 
find_if(InputRange const& range, Predicate p)
{
    return std::find_if( cpp::begin( range ), cpp::end( range ), p );
}

// ----------------------------------------------------------------------------

/**
 * @ingroup find
 * @brief Find last matching subsequence in a sequence.
 * @param range     Range to search.
 * @param sequence  Sequence to match.
 * @return  The last iterator @c i.
 *
 * Searches the range @p range for a sub-sequence that compares equal
 * value-by-value with the sequence given by @p sequence and returns an
 * iterator to the first element of the sub-sequence or @c cpp::end( range )
 * if the sub-sequence is not found.  The sub-sequence will be the last such
 * subsequence contained in @p range.
 *
 */
template<typename ForwardRange>
inline typename cpp::range_iterator<ForwardRange>::type
find_end(ForwardRange& range, ForwardRange const& sequence)
{
    return std::find_end( cpp::begin( range ), cpp::end( range )
                        , cpp::begin( sequence ), cpp::end( sequence ) );
}

template<typename ForwardRange>
inline typename cpp::range_const_iterator<ForwardRange>::type
find_end(ForwardRange const& range, ForwardRange const& sequence)
{
    return std::find_end( cpp::begin( range ), cpp::end( range )
                        , cpp::begin( sequence ), cpp::end( sequence ) );
}

// ----------------------------------------------------------------------------

// TODO (fen) : Make a comment for this find_end
template<typename ForwardRange, typename BinaryPredicate>
inline typename cpp::range_iterator<ForwardRange>::type
find_end(ForwardRange& range, ForwardRange const& sequence, BinaryPredicate comp)
{
    return std::find_end( cpp::begin( range ), cpp::end( range )
                        , cpp::begin( sequence ), cpp::end( sequence ) 
                        , comp );
}

template<typename ForwardRange, typename BinaryPredicate>
inline typename cpp::range_const_iterator<ForwardRange>::type
find_end(ForwardRange const& range, ForwardRange const& sequence, BinaryPredicate comp)
{
    return std::find_end( cpp::begin( range ), cpp::end( range )
                        , cpp::begin( sequence ), cpp::end( sequence ) 
                        , comp );
}

// ----------------------------------------------------------------------------

/**
 * @ingroup find
 * @brief Find two adjacent values in a sequence that are equal.
 * @param   range   A range.
 * @return  The first iterator @c i such that @c i and @c i+1 are both valid
 * iterators in @p range and such that @c *i == @c *(i+1), or @c cpp::end(
 * range ) if no such iterator exists.
 */
template<typename ForwardRange>
inline typename cpp::range_iterator<ForwardRange>::type
adjacent_find(ForwardRange& range)
{
    return std::adjacent_find( cpp::begin( range ), cpp::end( range ) );
}

template<typename ForwardRange>
inline typename cpp::range_const_iterator<ForwardRange>::type
adjacent_find(ForwardRange const& range)
{
    return std::adjacent_find( cpp::begin( range ), cpp::end( range ) );
}

// ----------------------------------------------------------------------------

template<typename ForwardRange, typename BinaryPredicate>
inline typename cpp::range_iterator<ForwardRange>::type
adjacent_find(ForwardRange& range, BinaryPredicate predicate)
{
    return std::adjacent_find( cpp::begin( range ), cpp::end( range ), predicate );
}

template<typename ForwardRange, typename BinaryPredicate>
inline typename cpp::range_const_iterator<ForwardRange>::type
adjacent_find(ForwardRange const& range, BinaryPredicate predicate)
{
    return std::adjacent_find( cpp::begin( range ), cpp::end( range ), predicate );
}

// ----------------------------------------------------------------------------

/**
 * @ingroup find
 * @brief   Find element from a set in a sequence.
 * @param   range1  Range to search.
 * @param   range2  Candidates to match.
 * @return  The first iterator @c i in @p range1 such that @c *i == @c *(i2)
 * such that i2 is an iterator in @p range2, or @c cpp::end( range1 ) if no
 * such iteratir exists.
 */
template<typename InputRange, typename ForwardRange>
inline typename cpp::range_iterator<InputRange>::type
find_first_of(InputRange& range1, ForwardRange const& range2)
{
    return std::find_first_of( cpp::begin( range1 ), cpp::end( range1 )
                             , cpp::begin( range2 ), cpp::end( range2 ) );
}

template<typename InputRange, typename ForwardRange>
inline typename cpp::range_const_iterator<InputRange>::type
find_first_of(InputRange const& range1, ForwardRange const& range2)
{
    return std::find_first_of( cpp::begin( range1 ), cpp::end( range1 )
                             , cpp::begin( range2 ), cpp::end( range2 ) );
}

// ----------------------------------------------------------------------------

template<typename InputRange, typename ForwardRange, typename BinaryPredicate>
inline typename cpp::range_iterator<InputRange>::type
find_first_of(InputRange& range1, ForwardRange const& range2, BinaryPredicate predicate)
{
    return std::find_first_of( cpp::begin( range1 ), cpp::end( range1 )
                             , cpp::begin( range2 ), cpp::end( range2 )
                             , predicate );
}

template<typename InputRange, typename ForwardRange, typename BinaryPredicate>
inline typename cpp::range_const_iterator<InputRange>::type
find_first_of(InputRange const& range1, ForwardRange const& range2, BinaryPredicate predicate)
{
    return std::find_first_of( cpp::begin( range1 ), cpp::end( range1 )
                             , cpp::begin( range2 ), cpp::end( range2 ) 
                             , predicate );
}

}

#endif /* CPP_ALGORITHM_FIND_HPP */
