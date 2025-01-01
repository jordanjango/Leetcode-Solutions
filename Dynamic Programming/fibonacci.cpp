//We will be implementing fibonaccis series using Dynamic Programming

/*
Why do we want to implement it using DP?
The major reason behind why do we need to use DP is 
- on every recursion,in the tree we will be having repeated computation of functions.
- now because of that we will be increasing the computation time.
- to reduce it we will be memoizing the repeated computations.
*/
#include<bits/std++>
using namespace std;

//Declare the functions where we need to 
int fib (int n){
//declare a DP 1D array to store the initial values
	vector<int> dp(-1,n);
//if the dp[n] already has a value,dont recompute,return that current value
if(dp[n]!=-1){
	return dp[n];
}
//now we need to make sure we will be storing the sum of previous numbers
return dp[n] = fib(n-1)+fib(n-2);

}
