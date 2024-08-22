#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

/* Defining equation to be solved. Change this equation to solve another problem. */

#define f(x) (3*x - cos(x) -1)

/*Define derivative of g(x). As you change f(x), change this function also.*/
#define g(x) (3+sin(x))

using namespace std;

int main(){

    float x0,x1,f0,f1,g0,e;
    int step = 1,N;

    /*Setting precision and writing floating point values in fixed-point notation.*/
    cout << setprecision(6) << fixed;

    /*Inputs*/
    cout << "Enter initial guess: ";
    cin >> x0;
    cout << "\nEnter tolerable error: ";
    cin >> e;
    cout << "\nEnter number of iterations (recommended value is around 50): ";
    cin >> N;

    /* Implementing Newton Raphson Method */
    cout << endl << "************************" << endl;
    cout << "Newton Raphson Method" << endl;
    cout << "************************" << endl;

    do {
        g0 = g(x0);
        f0 = f(x0);;

        if(g0 == 0.0){
            cout << "Mathematical Error.";
            exit(0);
        }

        x1 = x0 - (f0/g0);

        cout<<"Iteration-"<<step << ":\t x = " << setw(10) << x1 << "and f(x) = " << setw(10) << f(x1) << endl;
        x0 = x1;

        step = step + 1;

        if(step > N){
            cout << "Not Convergent.";
            exit(0);
        }

        f1 = f(x1);

    } while(fabs(f1)>e);

    cout << endl << "Root is: " << x1;
    return 0;
}