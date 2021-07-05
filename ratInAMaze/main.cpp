#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 5
using namespace std;
using intVector = vector<int>;
using boolVector = vector<vector<bool>>;
using stringVector = vector<string>;

bool isSafe( int row, int col, boolVector &visited,
int m[MAX][MAX], int &n){
    if (row < 0 || col < 0 ||row>=n ||col>=n ||  visited[row][col] || m[row][col] == 0)
    return false;
    
    return true;
    
};

void printPathHelper(int row,int col,
boolVector &visited,int m[MAX][MAX],int n,string str,
stringVector &result)
{
    if (!isSafe(row,col,visited,m,n)){
        return;
    };
    
    if (row == n-1 && col == n-1){
        result.push_back(str);
        return;
    };
    visited[row][col] = true;
      //DOWN
    if (isSafe(row + 1,col,visited,m,n)){
        str += 'D';
        printPathHelper(row + 1,col,visited,m,n,str,result);
        str.pop_back();
    };
       //RIGHT
    if (isSafe(row  ,col +1,visited,m,n)){
        str += 'R';
        printPathHelper(row  ,col + 1,visited,m,n,str,result);
        str.pop_back();
    };
    
      
     //LEFT
    if (isSafe(row ,col - 1,visited,m,n)){
        str += 'L';
        printPathHelper(row  ,col - 1,visited,m,n,str,result);
        str.pop_back();
    };
    
    //UP
    if (isSafe(row - 1,col,visited,m,n)){
        str += 'U';
        printPathHelper(row -1,col,visited,m,n,str,result);
        str.pop_back();
    };
    
   
  
    
    
  
    
    visited[row][col] = false;
    
    
    
    

    
    
}






stringVector printPath(int m[MAX][MAX], int n) {
    // Your code goes here
    stringVector result;
    boolVector visited(n,vector<bool>(n,0));
    string s;
    printPathHelper(0,0,visited,m,n,s,result);
    sort(result.begin(),result.end());
    return result;
    
    
    
    
    
})





