/*
Problem Statement
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
*/

#include<iostream>
using namespace std;

//declaring a function for backtracking

void backtracking(vector<int>& candidates,int target,vector<vector<int>>& result,vector<int>& answer,int index){
	//Base case : when the target becomes 0,then we can add the answer sub array in answer
	if(target==0){
		result.push_back(answer);
		return;
	}

	//loop over the candidates array
	for(int i=index;i<candidates.size();i++){
		if(candidates[i]==candidates[i-1] and i>index and nums[i]>target){
			continue;
		}
		ans.push_back(candidates[i]);
		backtracking(candidates,target-nums[i],result,answer,i+1);
		ans.pop_back();
	}

}


vector<vector<int>> combinationSum2(vector<int>& candidates,int target){
	vector<vector<int>> result;
	vector<int> answer;
	int index = 0;
	backtracking(candidates,target,result,answer,index);
	return result;
}