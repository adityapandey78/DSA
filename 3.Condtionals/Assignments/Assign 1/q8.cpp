#include <iostream>
/*
8.)
Given three points (x1, y1), (x2, y2) and
(x3, y3), write a program to check if all the three points fall on one straight line.
Input 1: x1  = 1 , y1 = 2 , x2 = 2 , y2 = 3 , x3 = 3 , y3 = 4
Output 1: All 3 points lie on the same line.*/
using namespace std;
int main()
{
    int x1, x2, x3, y1, y2, y3;
    float m1, m2, m3;
    cout << "Enter the points(x,y)" << endl;
    cin >> x1>> y1>> x2>> y2>> x3>> y3;
    m1 = (y1 - y2) / (x1 - x2);
    m2 = (y2 - y3) / (x2 - x3);
    m3 = (y3 - y1) / (x3 - x1);

    cout<<"The slopes are \n"<<m1 <<endl << m2<< endl<< m3 << endl;

    if (m1==m2||m2==m3||m3==m1)
    {
        cout << "All points are on the same line";
    }
    else
    {
        cout << "These points are on the same line";
    }

    return 0;
}