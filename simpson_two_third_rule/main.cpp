#include <iostream>
#include <math.h>

#define f(x) 1/(1+pow(x,2))


using namespace std;

int main(){
    
    float lower,upper,integration= 0.0, stepSize,k;
    int i,subInterval;

    std::cout << "Enter lower limit of integration: " << std::endl;
    cin >> lower;
    std::cout << "Enter upper limit of integration: " << std::endl;
    cin >> upper;
    std::cout << "Enter number of sub intervals: " << std::endl;
    cin >> subInterval;

    stepSize = (upper-lower)/subInterval;

    for (int i = 1; i < subInterval - 1; i++)
    {
        k = lower + i * stepSize;

        if(i%3==0.0){
            integration = integration + 2 * (f(k));
        }else{
         integration = integration + 3 * (f(k));
        }

    }

    integration = integration * stepSize * 3.0/8.0;

    std::cout << "Required value of integration is: " << integration << std::endl;
  
  return 0;  
}