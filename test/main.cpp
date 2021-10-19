#include <iostream>
#include "../indicators.hpp" 

int main()
{
    auto r = indicator::MACD({100,200,30,40,50,60,70,80,90,10,11,12,130,14,15,16,10,30,10,50,20,100,32,73,22,23,46,50,51,34});

    for(int i = 0;i != r.size();i++)
    {
        std::cout<<r[i]<<" ";
    }

    std::cout<<r[0]<<std::endl;

    return 0;
}