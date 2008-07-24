#include <cassert>
#include <list>

#include <cpp/algorithm.hpp>

int main(int argc, char* argv[])
{
    std::list<int> L;

    L.push_back( 3 );
    L.push_back( 1 );
    L.push_back( 7 );

    std::list<int>::iterator result = cpp::find( L, 7 );

    assert( result == L.end() || *result == 7 );
}

