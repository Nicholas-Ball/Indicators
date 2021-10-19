#include <iostream>
#include "../indicators.hpp" 

int main()
{
    auto r = indicator::RSI({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,10,3,1,5,2},14);

    std::cout<<r<<std::endl;

    return 0;
}