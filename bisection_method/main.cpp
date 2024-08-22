#include <iostream>
#include <iomanip>
#include <math.h>

/*
Defining equation to be solved.
Change this equation to solve another problem.
*/

#define f(x) cos(x) - x *exp(x)

using namespace std;

int main()
{
    std::cout << "/* Declaring required variables */" << std::endl;
    float x0, x1, x, f0, f1, f, e;
    int step = 1;

    std::cout << "/* Setting precision and writing floating point values in fixed-point notation. */" << std::endl;
    std::cout << setprecision(6) << std::endl;

up:
    std::cout << "Enter first guess: " << std::endl;
    cin >> x0;
    std::cout << "Enter second guess: " << std::endl;
    cin >> x1;
    std::cout << "Enter tolerable error: " << std::endl;
    cin >> e;

    f0 = f(x0);
    f1 = f(x1);

    if (f0 * f1 < 0.0)
    {
        std::cout << "Incorrect initial guess." << std::endl;
        goto up;
    }

    std::cout << "********************" << std::endl;
    std::cout << "Bisection Method" << std::endl;
    std::cout << "********************" << std::endl;

    do
    {
        x = (x0 + x1) / 2;
        f = f(x);

        std::cout << "Iteration- " << step << ":\t x = " << setw(10) << x << " and f(x) = " << setw(10) << f(x) << std::endl;

        if (f0 * f < 0)
        {
            x1 = x;
        }
        else
        {
            x0 = x;
        }

        step = step + 1;

    } while (fabs(f) > e);

    std::cout << "Root is: " << x << std::endl;

    return 0;
}
