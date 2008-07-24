#include <cassert>
#include <vector>
#include <functional>

#include <cpp/algorithm.hpp>

int main(int argc, char* argv[])
{
    typedef std::vector<int> vector;

    vector::value_type const a1[] = { 0, 1, 2, 2, 3, 4, 2, 2, 6, 7 };
    vector::value_type const a2[] = { 6, 4 };

    vector v1( a1, a1 + sizeof a1 / sizeof *a1 );
    vector v2( a2, a2 + sizeof a2 / sizeof *a2 );

    vector::const_iterator it = cpp::find_first_of( v1, v2 );

    assert( *it == 4 );

    it = cpp::find_first_of( v1, v2, std::equal_to<vector::value_type>() );

    assert( *it == 4 );

    return 0;
}

