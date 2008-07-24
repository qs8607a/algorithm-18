#include <cassert>
#include <list>
#include <functional>

#include <cpp/algorithm.hpp>

int main(int argc, char* argv[])
{
    typedef std::list<int> list;

    list::value_type const a1[] = { 0, 1, 6, 5, 3, 2, 2, 6, 5, 7 };
    list::value_type const a2[] = { 6, 5, 0, 0 };

    list const l1( a1, a1 + sizeof a1 / sizeof *a1 );
    list const l2( a2, a2 + 2 );

    list::const_iterator it1 = cpp::find_end( l1, l2 );

    list::const_iterator it2 = cpp::find_end( l1, l2, std::equal_to<list::value_type>() );

    assert( *it1 == 6 );
    assert( *it2 == 6 );

    return 0;
}

