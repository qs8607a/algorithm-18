#include <cassert>
#include <list>
#include <functional>

#include <cpp/algorithm.hpp>

int main(int argc, char* argv[])
{
    std::list<int> L;

    L.push_back( -3 );
    L.push_back( 0 );
    L.push_back( 3 );
    L.push_back( -2 );

    std::list<int>::iterator result = cpp::find_if( L, std::bind2nd( std::greater<int>(), 0 ) );

    assert( result == L.end() || *result > 0 );
}

