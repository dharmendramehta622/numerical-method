#include <iostream>
#include <math.h>

// Define function here
#define f(x) 1 / (1 + pow(x, 2))

using namespace std;

int main()
{

    float lower, upper, integration = 0.0, stepSize, k;
    int i, subInterval;

    // Input
    std::cout << "Enter lower limit of integration: " << std::endl;
    cin >> lower;
    std::cout << "Enter upper limit of integration: " << std::endl;
    cin >> upper;
    std::cout << "Enter the number of sub intervals: " << std::endl;
    cin >> subInterval;

    // Calculation

    // Finding step size
    stepSize = (upper - lower) / subInterval;

    // Finding Integration Value
    integration = f(lower) + f(upper);

    for (int i = 0; i < subInterval - 1; i++)
    {
        k = lower + i * stepSize;
        integration = integration + 2 * (f(k));
    }

    integration = integration * stepSize / 2;

    std::cout << "Required value of integration is: " << integration << std::endl;
    return 0;
}