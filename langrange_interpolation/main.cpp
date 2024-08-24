#include <iostream>
// #include <conio.h>

using namespace std;


int main(){

    float x[100],y[100],xp,yp=0,p;
    int i,j,n;

    // Input Section
    std::cout << "Enter the number of data: " << std::endl;
    cin>> n;
    std::cout << "Enter data: " << std::endl;

    for (i=1;i<=n;i++){
        std::cout << "x[" << i << "] =" << std::endl;
        cin >> x[i];
        std::cout << "y[" << i << "] = " << std::endl;
        cin >> y[i];
    }

    std::cout << "Enter interpolation point: " << std::endl;
    cin >> xp;

    // Implementing Langrange Interpolation
    for(i=1;i<=n;i++){

        p=1;

        for(j=1;j<=n;j++){
            if(i!=j){
                p = p * (xp-x[j])/(x[i] - x[j]);
            }
         yp = yp + p * y[i];
        }


        std::cout << "Interpolated value at " << xp << " is " << yp << std::endl;

        return 0;

    }

}