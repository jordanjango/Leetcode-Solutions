/*

VVV IMP

Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.

Example 1:

Input: n = 2
Output: 91
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99

so we must remove the elements divisible by 11 and keep adding till it reaches 100
this is what comes to my mind right now.

*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*we will be constructing the numbers till the given range and count the unique numbers*/
/*
The logic that we are implementing here is
we will be using the numbers 1 to 10 because that will help us in constructing the numbers and mark them visited
because once used we cannot use again since we are counting unique digits one.
*/

/*generate the unique digits*/
void generateUniqueDigits(vector<bool>& visited,int& uniqueCounts,string currentValue,int n){
	/*if we reached the size of current string as n then we can return the answer i.e the total count*/
	if(currentValue.size()==n){
		return;
	}
	/*now to construct string what we can do is construct number using 0 to 9*/
	for(int i=0;i<10;i++){
		/*now i need to make sure we are checking if the string isnt empty since first time the string will be empty*/
		if(i==0 and currentValue.size()==0)
			continue;
		/*Check if the value is already visited*/
		if(visited[i]==true)
			continue;
		/*now we can mark the current value as visited*/
		visited[i] = true;
		currentValue+=to_string(i);
		/*count the value*/
		uniqueCounts++;
		/*we will be backtracking now*/
		generateUniqueDigits(visited,uniqueCounts,currentValue,n);
		visited[i] = false;
		currentValue.pop_back();
	}
}


int main(void){
	vector<int> result;
	vector<bool> visited(10,false);
	int n = 2;
	int uniqueCounts = 0;
	generateUniqueDigits(visited,uniqueCounts,"",n);
	cout<<uniqueCounts;
	return 1;
}