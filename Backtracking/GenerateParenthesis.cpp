/*
Problem Statement
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
*/

#include<iostream>
using namespace std;

//This is our helper backtracking function
void backtracking(int n,int rightCount,int leftCount,string& answer,vector<int>& result){
	if(n==rightCount and n==leftCount){
		result.push_back(answer);
		return;
	}

	//if we have the leftCount less than given integer n, we will append the opening bracket '('
	if(leftCount<n){
		//recursively call the backtracking function to explore further options
		backtracking(n,rightCount,leftCount+1,answer+'(',result);
	}
	//we have to appended from the leftSide,we need to make sure that we append from the rightSide
	if(rightCount<leftCount){
		backtracking(n,rightCount+1,leftCount,answer+')',result);
	}
}

 vector<string> generateParenthesis(int n) {
    vector<string> result;
    helper_backtracking(n, 0, 0, "", result);
    return result;
}