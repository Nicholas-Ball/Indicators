#include <vector>
#include <cmath>
#include <iostream>

inline double PercentChange(double initial, double final)
{
    return ((final - initial)/(fabs(initial)))*100.0;
}

//invert vector array
std::vector<double> InvertArray(std::vector<double> arr)
{
    std::vector<double> out;
    for(int i = arr.size()-1;i != -1;i--)
    {
        arr.push_back(arr[i]);
    }
    return arr;
}

class indicator
{
    public:
        //simple moving average (index 0 = current day)
        static std::vector<double> SMA(std::vector<double> arr)
        {
            std::vector <double> sma = {arr[0]};
            for(int i = 0; i != arr.size();i++)
            {
                sma.push_back((sma[i-1]+arr[i])/2);
            }
            return sma;
        }
        //rsi calculations (index 0 = current day)
        static double RSI(std::vector<double> arr,int period)
        {   
            double value = -1;
            if(arr.size() >= period){

                //invert array
                arr = InvertArray(arr);

                double PreviousDay = arr[0];
                double up = 0;
                double down = 0;

                //calculate first perod's rsi
                for(int i = 0;i != period;i++)
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
                    PreviousDay = arr[i];
                }
                //calculate first step rsi
                value = 100-(100/(1+(up/down)));

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

                    PreviousDay = arr[i];

                    value = 100-(100/(((up*13)+cup)/((down*13)+cdown)));
                }


            }
            return value;
        }
};