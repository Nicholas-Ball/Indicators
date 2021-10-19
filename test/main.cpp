#include <iostream>
#include "../indicators.hpp" 

int main()
{
    auto r = indicator::SMA({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,10,3,1,5,2});

    for(int i = 0;i != r.size();i++)
    {
        std::cout<<r[i]<<"	";
    }

    return 0;
}