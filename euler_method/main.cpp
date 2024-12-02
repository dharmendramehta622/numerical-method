#include<iostream>

/* defining ordinary differential equation to be solved */
/* In this example we are solving dy/dx = x + y */

#define f(x,y) x+y

using namespace std;

int main(){
    
    float x0, y0, xn, h, yn, slope;
    int i, n;

    std::cout << "Enter initial condition" << endl;
    std::cout << "x0 = ";
    cin >> x0;
    std::cout << "y0 = ";
    cin >> y0;
    std::cout << "Enter calculation point xn = ";
    cin >> xn;
    std::cout << "Enter number of steps: ";
    cin >> n;

    /* Calculating step size(h) */
    h = (xn - x0) / n;

    /* Euler's Method */
    std::cout << "\nx0\ty0\tslope\tyn\n";
    std::cout << "-----------------------\n";
    
    for (i = 0; i < n;i++){
        slope = f(x0, y0);
        yn = y0 + h * slope;
        std::cout << x0 << "\t" << y0 << "\t" << slope << "\t" << yn << endl;
        y0 = yn;
        x0 = x0 + h;
    }

    /* Displaying result */
    std::cout << "\nValue of y at x = " << xn << " is " << yn;

    return 0;
}