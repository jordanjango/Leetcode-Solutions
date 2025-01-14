/*
Problem Statement 
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
*/

#include<bits/stdc++.h>
using namespace std;
/*
Pick/Not Pick or mark it as visited !
also we can swap the elements!
*/

/*Code Snippet*/
void backtracking(vector<int>& nums, int index, vector<int>& ans,vector<vector<int>>& result){
	if(index==nums.size()){
		result.insert(ans);
		return;
	}
	/*let's do by take or not take method*/
	for(int i=index;i<nums.size();i++){
		/*we have to add a condition for skipping the duplicates*/
		if(i!=index and nums[i]==nums[index])
			continue;
		swap(nums[index],nums[i]);
		backtracking(nums,i+1,ans,result);
		swap(nums[i],nums[index]);
	}
}