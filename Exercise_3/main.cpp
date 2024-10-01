#include <iostream>
#include <cmath>

using namespace std;
    int main()
{
    int x =(0);
    int y = (0);
    const double e =(2.718);
    const double pi =(3.14);
    double result =(0);
    cout<<"Enter X and Y :"<<endl;
    cin>>x>>y;

    result=1/sqrt(2*pi*x)*pow(e,pow(x,2))*cos(2*pi*x+y);
    cout<<"Your result is:"<<result<<endl;
   return 0;
}

