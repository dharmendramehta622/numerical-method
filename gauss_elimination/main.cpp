#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>

#define SIZE 10

using namespace std;

int main(){
    float a[SIZE][SIZE],x[SIZE],ratio;
    int i,j,k,n;
    
    // 1. Reading number of unknowns.
    std::cout << "Enter the number of unknowns: " << endl;
    cin >> n;

    //2. Reading augmented matrix
    for (i =1;i<=n;i++){
        for(j=1;j<=n+1;j++){
          std::cout << "a[" << i << "]" << "[" << j << "]" << endl;
          cin >> a[i][j];
        }
    }

    // 3. Applying Gauss Elimination
    for (i=1;i<=n;i++){
        if(a[i][j] == 0.0){
            std::cout << "Mathematical Error!" << endl;
            exit(0);
        }
        for (j=i+1;j<=n;j++){
            ratio = a[j][i] / a[i][i];
            for(k=1;k<=n+1;k++){
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }

    // 4. Obtaining solution by Backward Substitutions
    x[n] = a[n][n+1] / a[n][n];

    for(i=n-1;i>=1;i--){
        x[i] = a[i][n+1];
        for(j=i+1;j<=n;j++){
            x[i] = x[i] - a[i][j] * x[j];
        } 
        x[i] = x[i] / a[i][i];
    }

    // Displaying Solution
    for(i=1;i<=n;i++){
        std::cout << "x[" << i << "]: " << x[i] << endl; 
    }

    return 0; 
}