#include<iostream>
#include<math.h>

#define S 50

using namespace std;

int main()
{
 int n, i;
 float x[S], y[S], sumX=0, sumX2=0, sumY=0, sumXY=0, a, b, A, B;

 /* Input */
 std::cout<<"How many data points? " << endl;
 cin >> n;

 for(i=1;i<=n;i++)
 {
  std::cout << "x["<< i <<"] = ";
  cin >> x[i];
  std::cout << "y["<< i <<"] = ";
  cin >> y[i];
 }

 /* Calculating Required Sum */
 for(i=1;i<=n;i++)
 {
  sumX = sumX + x[i];
  sumX2 = sumX2 + x[i]*x[i];
  sumY = sumY + log(y[i]);
  sumXY = sumXY + x[i]*log(y[i]);
 }

 /* Calculating A and B */
 B = (n*sumXY-sumX*sumY)/(n*sumX2-sumX*sumX);
 A = (sumY - B*sumX)/n;

 /* Transformation of A to a and B to b */
 a = exp(A);
 b = exp(B);

 /* Displaying value of a and b */
 std::cout << "Values are: a = " << a << " and b = " << b;

 return(0);
}