#include <cassert>
#include <vector>
#include <functional>

#include <cpp/algorithm.hpp>

int main(int argc, char* argv[])
{
    typedef std::vector<int> vector;

    vector::value_type const arr[] = { 0, 1, 2, 2, 3, 4, 2, 2, 6, 7 };

    vector const v1( arr, arr + sizeof arr / sizeof *arr );

    vector::const_iterator it = cpp::adjacent_find( v1 );

    assert( *it == 2 );
    
    it = cpp::adjacent_find( v1, std::equal_to<vector::value_type>() );

    assert( *it == 2 );


    return 0;
}

