#include <vector>
#include <cmath>
#include <iostream>

inline double PercentChange(double initial, double final)
{
    return ((final - initial)/(fabs(initial)))*100;
}

class indicator
{
    public:
        //rsi calculations
        static double RSI(std::vector<double> arr,int period)
        {   
            double value = -1;
            if(arr.size() >= period){

                double PreviousDay = arr[0];
                double up = 0;
                double down = 0;
                //calculate first perod's rsi
                for(int i = 1;i != period;i++)
                {
                    //calculate diference of today with n-1 day
                    double difference =  PercentChange(PreviousDay,arr[i]);

                    if(difference >= 0){
                        up = (up+difference)/2;
                        difference = 0;
                        down = (fabs(difference)+down)/2;
                    }
                    else
                    {
                        down = (fabs(difference)+down)/2;
                        difference = 0;
                        up = (up+difference)/2; 

                    }
                }
                //calculate first step rsi
                value = 100-(100/(1+(up/down)));
                std::cout<<value<<std::endl;

                //calculate remaing days
                for(int i = period; i != arr.size();i++)
                {
                    //calculate diference of today with n-1 day
                    double difference =  PercentChange(PreviousDay,arr[i]);

                    double cup = 0;
                    double cdown = 0;

                    if(difference >= 0){
                        up = (up+difference)/2;
                        cup = difference;
                        difference = 0;
                        down = (fabs(difference)+down)/2;
                    }
                    else
                    {
                        down = (fabs(difference)+down)/2;
                        cdown = fabs(difference);
                        difference = 0;
                        up = (up+difference)/2;

                    }

                    value = 100-(100/(((up*13)+cup)/((down*13)+cdown)));
                }


            }
            return value;
        }
};