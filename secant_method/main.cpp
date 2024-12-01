/**
 * @author [kode-mafia008]
 * @email [dharmendramehta622@mail.com]
 * @create date 2024-08-22 08:10:03
 * @modify date 2024-08-22 08:10:03
 * @desc C++ Program for Secant Method
 */

#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>

#define f(x) x *x *x - 2 * x - 5

using namespace std;

int main()
{

  float x0, x1, x2, f0, f1, f2, e;

  int step = 1, N;

  std::cout << setprecision(6) << fixed << std::endl;

  std::cout << "Enter the initial guess: " << std::endl;
  cin >> x0;
  std::cout << "Enter the second guess: " << std::endl;
  cin >> x1;
  std::cout << "Enter the tolerable error: " << std::endl;
  cin >> e;
  std::cout << "Enter the maximum iteration: " << std::endl;
  cin >> N;

  std::cout << "***********************" << std::endl;
  std::cout << "Secant Method" << std::endl;
  std::cout << "***********************" << std::endl;

  do
  {
    f0 = f(x0);
    f1 = f(x1);
    if (f0 == f1)
    {
      std::cout << "Mathematical Error: " << std::endl;
      exit(0);
    }

    x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
    f2 = f(x2);

    std::cout << "Iteration- " << step << " :\t x2 = " << setw(10) << x2 << "and f(x2)" << setw(10) << f(x2) << std::endl;

    x0 = x1;
    f0 = f1;
    x1 = x2;
    f1 = f2;

    step = step + 1;

    if (step > N)
    {
      std::cout << "Not Convergent: " << std::endl;
      exit(0);
    }

  }while (fabs(f2) > e); 
  std::cout << "Root is: " << x2 << std::endl;
  return 0;
}
