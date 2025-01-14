/*
Given a string s, partition s such that every
substring
of the partition is a
palindrome
Return all possible palindrome partitioning of s.

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

*/
/*
We need to find all possible substring (all possible substring means we have to use recursions)
*/
#include<bits/stdc++.h>
using namespace std;

/*we will be checking if the substring is a palindrome or not*/
bool isPalindrome(int i,int j,string s){
	int start = i;
	int end = j;
	while(start<end){
		if(s[i]==s[j]){
			return true;
		}
	}
	return false;
}
/*Now lets find all possible sub string*/
void allPossibleSubString(vector<vector<int>>& answer,vector<int>& result,string s,int index)
{
	if(index==s.size()){
		answer.push_back(result);
		return;
	}
	/*Now lets loop on the string*/
	for(int i=index;i<s.size();i++){
		//check if the given window is a palindrome or not
		if(isPalindrome(i,index,s)){
			answer.push_back(s.subString(index,i-index+1))
			allPossibleSubString(answer,result,s,i+1);
			result.pop_back();
		}
	}
}