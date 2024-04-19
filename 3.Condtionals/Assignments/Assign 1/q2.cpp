#include<iostream>
/*2.
Given the radius of the circle, predict whether numerically the area of this circle is larger than the circumference or not.
Input 1: radius = 4
Output 1: Area is greater than circumference.
Explanation: area = 3.14 * 4 * 4 = 50.24 unit2
Perimeter = 2 * 3.14 * 4 = 25.12 unit
Therefore area > perimeter.*/
using namespace std;
int main(){
    int r,area,peri;

    cout<<"Enter the  radius of the circle\n";cin>> r;

    area=2*3.14*r*r;
    peri=2*3.14*r;
    if (area>peri)
    {
        cout<<"Area="<<area<<endl<<"Perimeter="<<peri<<endl;
        cout<<"Therefore the area > perimeter";
    }else
    {
        cout<<"Area="<<area<<endl<<"Perimeter="<<peri<<endl;
        cout<<"Therefore the area < perimeter";
    }
    
    
    return 0;
}