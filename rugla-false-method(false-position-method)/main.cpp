#include<iostream>
#include<iomanip>
#include<math.h>

/*
 Defining equation to be solved.
 Change this equation to solve another problem.
*/

#define f(x) cos(x) - x * exp(x)

using namespace std;

int main()
{
	 /* Declaring required variables */
	 float x0, x1, x, f0, f1, f, e;
	 int step = 1;

	 /* Setting precision and writing floating point values in fixed-point notation. */
        std::cout << setprecision(6) << fixed << std::endl;

	 /* Inputs */
	 up:
	     std::cout << "Enter first guess: " << std::endl;
	     cin >> x0;
	     std::cout <<"Enter second guess: " << std::endl;
	     cin>>x1;
	     std::cout<<"Enter tolerable error: "<< std::endl;
	     cin>>e;

	 /* Calculating Functional Value */
	 f0 = f(x0);
	 f1 = f(x1);

	 /* Checking whether given guesses brackets the root or not. */
	 if( f0 * f1 > 0.0)
	 {
		  std::cout << "Incorrect Initial Guesses." << std::endl;
		  goto up;
	 }
	 /* Implementing False Position Method */
	 std::cout << "*********************" << std::endl;
	 std::cout << "False Position Method" << std::endl;
	 std::cout << "*********************" << std::endl;
	 do
	 {
		  /* Applying False Position Method */
		  /* x is next approximated root using False Position method */
		  x = x0 - (x0-x1) * f0/ (f0-f1);
		  f = f(x);

		  std::cout << "Iteration-" << step << ":\t x = " << setw(10)<< x << " and f(x) = " << setw(10) << f(x) << std::endl;

		  if( f0 * f < 0)
		  {
			   x1 = x;
			   f1 = f;
		  }
		  else
		  {
			   x0 = x;
			   f0 = f;
		  }
		  step = step + 1;
	 }while(fabs(f)>e);

	 std::cout << "Root is: " << x << std::endl;
	 return 0;
}
