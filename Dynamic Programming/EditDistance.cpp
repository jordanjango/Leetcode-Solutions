/*
Problem Statement

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

*/

#include<iostream>
using namespace std;


/*
Let's Code The Recursive Approach.
*/

int convertWord1ToWord2(string word1,string word2,int index1,int index2){
	/*Let's write 2 logics
	1. If the word matched then we don't have to perform any operation.
	2. If the word doesn't match then we need to perform an operation.
	*/
	/*Now here we have to analyse the base case
	What if we traversed all over the word1 and we didnt find any match 
	//3 operations have to be performed
	so what we do is since at -1 the string is empty we will insert all values of the word2 "" <- "ros"  
	*/
	if(index1<0)
		return index2+1;
	if(index2<0)
		return index1+1;
	/*If the string charachter doesn't match*/
	if(word1[index1]==word2[index2]){
		/*we won't perform any operation and move on to the other string*/
		return 0+convertWord1ToWord2(word1,word2,index1-1,index2-1);
	}
	/*if it doesnt match then we need to perform 3 tasks to make sure it's transformed into other string*/
	int insertionOpertaions =  1+convertWord1ToWord2(word1,word2,index1,index2-1);
	int deletionOperations  =  1+convertWord1ToWord2(word1,word2,index1-1,index2);
	int replaceOperations   =  1+convertWord1ToWord2(word1,word2,index1-1,index2-1);

	/*Take minimum values from all 3 operations to see how many were used to convert the word1 to word2*/
	int minOperations = min(insertionOpertaions,min(deletionOperations,replaceOperations));
	return minOperations;
}
/*
Let's convert the recursion approach to a top down approach

we will be create a memo table for the string
since we are matching 2 strings we need to store the result index wise just the same way we did palindromic substring


memo table will be having the number of operations for [i comp with j]

	 0 	 1   2  [0 comp to 0] [0 comp to 1] [0 comp to 2] -> compared answer will be stored in dp table.
0	-1  -1  -1  [1 comp to 0] [1 comp tp 1] [1 comp to 2] -> compared answer will be stored in dp table.
1   -1  -1  -1	[2 comp to 0] [2 comp to 1] [2 comp to 2] -> compared answer will be stored in dp table.
2   -1  -1  -1
3   -1  -1  -1
4   -1  -1  -1

so the memo table will be like
vector<vetcor<int>>(word1.size()+1,vector<int>(-1,word2.size()+1))
*/
int convertWord1ToWord2(string word1,string word2,int index1,int index2,vector<vector<int>>& memo){
	if(memo[word1][word2]!=-1)
		return memo[word1][word2];
	/*Now will normally check the base cases*/
	if(index1<0)
		return index2+1;
	if(index2<0)
		return index1+1;
	/*Now we will be checking if the words are equal or not*/
	if(word1[index1]==word2[index2]){
		/*we won't perform any operation and move on to the other string*/
		return 0+convertWord1ToWord2(word1,word2,index1-1,index2-1,memo);
	}
	/*Now perform the operations*/
	int insertionOpertaions =  1+convertWord1ToWord2(word1,word2,index1,index2-1,dp);
	int deletionOperations  =  1+convertWord1ToWord2(word1,word2,index1-1,index2,dp);
	int replaceOperations   =  1+convertWord1ToWord2(word1,word2,index1-1,index2-1,dp);

	return dp[word1][word2] = min(insertionOpertaions,min(deletionOperations,replaceOperations));
}
/*Now let's convert this into a bottom up approach*/
int convertWord1ToWord2(string word1,string word2,int i,int j,vector<vector<int>>& dp){
	///what to write in place of the memo case
	for(int ind1=0;ind1<word1.size();ind1++)
		dp[0][i] = j;
	for(int ind2=0;ind2<word2.size();ind2++)
		dp[j][0] = i;
	//let's compare the words
	for(int i=1;i<word1.size();i++){
		for(int j=1;j<word2.size();j++){
			if(word1[i-1]==word2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else{
				int insertionOpertaions =  1+dp[i][j-1];
				int deletionOperations  =  1+dp[i-1][j];
				int replaceOperations   =  1+dp[i-1][j-1];
				dp[i][j]=min(insertion,min(deletion,replacement));
			}
		}
	}
	/*Since results will be stored in the last array*/
	return dp[word1.size()][word2.size()];
}