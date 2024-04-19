#include<iostream>
using namespace std;
//calculate the no of ways to reach to thew destination from the square grid if you can only travel right or down

//using four parameters
int maze(int startrow,int startcol,int endrow, int endcol){
    if(startrow>endrow|| startcol>endcol) return 0;
    if(startrow == endrow && startcol==endcol) return 1;
    int rightWays = maze( startrow, startcol+1, endrow, endcol);
    int downways=maze(startrow+1, startcol, endrow, endcol);
    int totalways= rightWays+downways;
    return totalways;

}
//printing the path for maze1
void printPath(int startrow,int startcol,int endrow, int endcol,string s){
    if(startrow>endrow|| startcol>endcol) return;
    if(startrow == endrow && startcol==endcol) {//destination reached
    cout<<s<<endl;
    return;
    }
    printPath ( startrow, startcol+1, endrow, endcol,s+'R'); //right
    printPath(startrow+1, startcol, endrow, endcol,s+'D');//down
    
}


//using just two parametres only!
//isme destination se hi start krenge and coz (1,1) to sbke liye hia ayega na

int maze2(int row,int col){
    if(row<1||col<1) return 0;
    if(row==1 &&col==1) return 1;
    int rightways= maze2(row,col-1);
    //right jaane pe colooumn ghat rha ahia na
    int downways=maze2(row-1,col); //dowm jaane pe row ghatega
    int toatalways=rightways+downways;
    return toatalways;

}
//printing the path for maze 2
void printPath2(int row, int col, string s){
    if(row<1|| col<1) return;
    if(row == 1 && col==1) {
    //destination reached
    cout<<s<<endl;
    return;
    }
    printPath2(row, col-1,s+'R'); //right
    printPath2(row-1, col,s+'D'); //down
    
}
int main(){
    // cout<<maze(1,1,4,3)<<endl;
    // printPath(1,1,5,5,"");
    cout<<maze2(5,5)<<endl;
    printPath2(5,5,"");
    return 0;
}