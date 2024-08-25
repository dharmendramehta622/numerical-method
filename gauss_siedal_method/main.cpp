#include <iostream>
#include <iomanip>
#include <math.h>


/* Arrange systems of linear
   equations to be solved in
   diagonally dominant form
   and form equation for each
   unknown and define here
*/
/* In this example we are solving
   3x + 20y - z = -18
   2x - 3y + 20z = 25
   20x + y - 2z = 17
*/
/* Arranging given system of linear
   equations in diagonally dominant
   form:
   20x + y - 2z = 17
   3x + 20y -z = -18
   2x - 3y + 20z = 25
*/
/* Equations:
   x = (17-y+2z)/20
   y = (-18-3x+z)/20
   z = (25-2x+3y)/20
*/

/* Defining function */
#define f1(x,y,z) (17-y+z*2)/20
#define f2(x,y,z) (-18-3*x+z)/20
#define f3(x,y,z) (25-2*x+3*y)/20


using namespace std;
 
int main(){

    float x0=0,y0=0,z0=0,x1,y1,z1,e1,e2,e3,e;
    int step = 1;

    std::cout << setprecision(6) << fixed << std::endl;

    std::cout << "Enter tolerable error: " << std::endl;
    cin >> e;

    std::cout << "Count\tx\t\ty\t\tz" << std::endl;

    do
    {
     x1 = f1(x0,y0,z0);
     y1 = f1(x1,y0,z0);
     z1 = f3(x1,y1,z0);

     std::cout << step << "\t" << x1 << "\t" << y1 << "\t" << z1 << std::endl;
     
     e1 = fabs(x0-x1);
     e2 = fabs(y0-y1);
     e3 = fabs(z0-z1);

    step++;
    
     x0 = x1;
     y0 = y1;
     z0 = z1;


    } while (e1<e && e2 < e && e3 < e);
    
    std::cout << "Solution: x = " << x1 << ", y = " << y1 << " and z = " << z1 << std::endl;
    return 0;
}