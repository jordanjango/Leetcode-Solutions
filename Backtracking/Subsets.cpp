/*
Given an integer array nums of unique elements, return all possible
subsets
(the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Solution must not contain duplicates so we need to make sure we are keeping track if index of previous recursion call.
also if order doesnt matter then we need to find combinations
*/

#include<bits/stdc++.h>
using namespace std;

void backtracking(vector<vector<int>>& result,vector<int> answer,int index,vector<int>& nums){
	//let's write the base case
	//we wont do this since we want to get all size of sub arrays
	//if you feel ever why we removed , just uncomment it and try getting the result.
	// if(index==nums.size()){
	// 	result.push_back(answer);
	// 	return;
	// }
	//we will be looping over the nums array and pushing the values
	result.push_back(answer);//since we have to push an empty answer
	for(int i=index;i<nums.size();i++){
		answer.push_back(nums[i]);
		backtracking(result,answer,i+1,nums);
		amswer.pop_back()//remove the item and go to next iteration
	}
}