#include <iostream>
#include <iomanip>
#include <math.h>



// Define equation to be solved.
#define f(x) (3 * x - cos(x) - 1)

/* Defining the derivative of g(x).
   As you change f(x), change this function accordingly. */
#define g(x) (3 + sin(x))


using namespace std;

int main() {

    float x0, x1, f0, f1, g0, e;
    int step = 1, N;
     
    std::cout << "/* Setting precision and writing floating point values in fixed-point notation. */" << std::endl;
    std::cout << setprecision(6) << fixed << std::endl;
    
 
    /*Inputs */
    std::cout << "Enter initial guess: " << std::endl;
    cin >> x0;
    std::cout << "Enter tolerable error: " << std::endl;
    cin >> e;
    std::cout << "Enter maximum iteration: " << std::endl;
    cin >> N;

    /* Implementing Bisection Method*/
    std::cout << "******************" << std::endl;
    std::cout << "Newton Raphson Method" << std::endl;
    std::cout << "*******************" << std::endl;

    do
    {
      g0 = g(x0);
      f0 = f(x0);

      if(g0 == 0.0){
        std::cout << "Mathematical Error." << std::endl;
        exit(0);
      }

      x1 = x0 - (f0/g0);

      std::cout << "Iteration- "<< step << ":\t x = " << setw(10)  << x1 << " and f(x) = " << setw(10) << f(x1) << std::endl;
      x0 = x1;

      step = step + 1;

      if(step > N){
        std::cout << "Non Convergent." << std::endl;
        exit(0);
      }

      f1 = f(x1);

    } while (fabs(f1) > e);
    
  std::cout << "Root is: " << x1 << std::endl;
  return 0;
}


/* 
The condition `fabs(f1) > e` in the `do-while` loop is used to check whether the absolute value
of `f1` is greater than the specified tolerance `e`. The loop continues until this condition is
no longer satisfied, which means that the absolute value of `f1` has become smaller than or equal 
to the specified tolerance, indicating that a root has been found.

Here's a clarification of the condition:
   - `fabs(f1)` calculates the absolute value of `f1`.
   - `e` is the specified tolerance or the acceptable error.
      The loop continues until the absolute value of `f1` is less than or equal to `e`, 
      indicating that the solution is sufficiently close to a root.

This condition is part of the convergence criterion for the Newton-Raphson method. 
It ensures that the algorithm stops when the estimated root is within the desired level of accuracy.
*/