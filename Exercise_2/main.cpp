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
    cout<<"Insert X and Y :"<<endl;
    cin>>x>>y;//x and  y should not be 0
    if (x!=0 && y!=0){

    result=1/sqrt(2*pi*x)*pow(e,pow(x,2))*cos(2*pi*x+y);
    cout<<"Your result is:"<<result<<endl;}
    else{
        cout<<"The numbers that you entered is 0! "<<endl;

    }
   return 0;
}

