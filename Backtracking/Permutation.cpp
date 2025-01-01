/*
Problem Statement
Given an array nums of distinct integers, return all the possible
permutations.
You can return the answer in any order.

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

In this question we are dealing with the arrangemnent of the elements.
Now after that we need to make sure we mark the elements visited
since the elements must not be repeated wile fprming the 
arrangement.

Finding the recurrance relation.

1. let's first check if the element isnt visited
2. now mark it visited 
3. push the element 
4. now just move to another element
5. backtrack to previous element by marking the visited as false and popping the element.

Another way to find the permutations
Ordering matters in permutations.
so we need to make sure that we are including all elements and dealing with the index.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> answer;
        int count = 0;
        int n = nums.size();
        backtracking(nums,result,answercount,n)
        return result;
    }
    void backtracking(vector<int>& nums,vector<int>& result,vector<int>& answer,int count,int n){
    	if(count==n){
    		result.push_back(answer);
    		return;
    	}
    	//find the permutation logic
    	for(int i=0;i<n;i++){
    		if(!visited[i]){
    			visited[i] = true;
    			answer.push_back(visited[i]);
    			backtracking(nums,result,answer,count+1,n);
    			answer.pop_back();
    			visited[i]=false;
    		}
    	}
    }
};

//Logic - 2 to find the permutations
class Solution {
public:
	 vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> answer;
        int index = 0;
        int n = nums.size();
        backtracking(nums,result,answer,index,n)
        return result;
    }
    void backtrackingLogic2(vector<int>& nums,vector<vector<int>>& result,vector<int>& answer,int index,int n){
    	if(index==n){
    		result.push_back(answer);
    		return;
    	}
  
    	for(int i=index;i<n;i++){
    		swap(nums[index],nums[i]);
    		backtrackingLogic2(nums,result,answer,index+1,n);
    		swap(nums[i],nums[index]);
    	}
    }

}