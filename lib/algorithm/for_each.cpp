#include <iostream>

#include <cpp/algorithm.hpp>

template<typename T>
struct print: public std::unary_function<T, void>
{
    print(std::ostream& out): 
        os( out )
    ,   count( 0 )
    {
    }

    void operator()(T x)
    {
        os << x << ' ';
        ++count;
    }

    std::ostream& os;
    int count;
};

int main(int argc, char* argv[])
{
    int A[] = { 1, 4, 2, 8, 5, 7 };
    print<int> P = cpp::for_each( A, print<int>( std::cout ) );

    std::cout << std::endl << P.count << " objects printed." << std::endl;
    
    return 0;
}

