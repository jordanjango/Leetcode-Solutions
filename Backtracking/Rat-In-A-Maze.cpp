/*
Problem Statement
Consider a rat placed at (0, 0) in a square matrix m[ ][ ] of order n and has to reach the destination at (n-1, n-1). 
The task is to find a sorted array of strings denoting all the possible directions which the rat can take to reach the destination at (n-1, n-1).
The directions in which the rat can move are ‘U'(up), ‘D'(down), ‘L’ (left), ‘R’ (right)
*/
#include<iostream>
#define MAX 5
using namespace std;

/*In the given problem statement we will be having 4 directions
1. Up
2. Down
3. Right
4. Left
*/

void getAllPath(int matrix[MAX][MAX],int n,int row,int col,vector<string>& answer,string current){
	/*let's check all path*/
	if(row>=n or col>=n or row<0 or col<0 or matrix[row][col]==0)
		return;
	/*now we will define the base case from where we shall return the answers*/
	if(row==n-1 and col==n-1){
		answer.push_back(current);
		return;
	}
	//mark the travelled path as 0 
	matrix[row][col] = 0;
	getAllPath(matrix,n,row-1,col,answer,current+'U');
	getAllPath(matrix,n,row+1,col,answer,current+'D');
	getAllPath(matrix,n,row,col-1,answer,current+'L');
	getAllPath(matrix,n,row,col+1,answer,current+'R');
	//mark it back as 1 for next recursive call
	matrix[row][col] = 1;

	return;

}