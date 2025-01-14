/*
You are given an array nums of positive integers and a positive integer k.

A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.

Return the number of non-empty beautiful subsets of the array nums.

A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums.
Two subsets are different if and only if the chosen indices to delete are different.

Example 1:

Input: nums = [2,4,6], k = 2
Output: 4
Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
It can be proved that there are only 4 beautiful subsets in the array [2,4,6].

*/
#include<bits/stdc++.h>
using namespace std;


void countBeautifulSubsets(vector<int>& nums, int k, vector<int>& result,
                               int index, int& count){

	if(!result.empty()){
		count++;
		return;
	}
	/*now what we can do is,we can check for each number by iterating over nums array*/
	for(int i=index;i<nums.size();i++){
		for(int j=0;j<result.size();j++){
			/*check if we can accomodate the new num[i]*/
			if(abs(result[j]-num[i])){
				isValid = false;
				break;
			}
		}
		if(isValid){
			/*if the result can be accomodated,we will move add the result and move to next recursion call.*/
			result.push_back(nums[i]);
			countBeautifulSubsets(nums,k,result,i+1,count);
			result.pop_back();
		}
	}
}

/*This wont work since
when we add a number inside the result array we need to prior check if we accomadate in result array since no 2 numbers can have difference of k*/
// void getBeautifulSubsets(vector<int>& nums, int k, vector<int>& result,int index,vector<vector<int>> answer){
// 	if(index==nums.size()){
// 		answer.push_back(result);
// 		return;
// 	}
// 	/*Now we can traverse over the nums array and find out the difference*/
// 	for(int i=index;i<nums.size();i++){
// 		if(abs(nums[index]-nums[i])!=k){
// 			result.push_back(nums[i]);
// 			getBeautifulSubsets(nums,k,result,i+1,answer);
// 			result.pop_back();
// 		}
// 	}
// }