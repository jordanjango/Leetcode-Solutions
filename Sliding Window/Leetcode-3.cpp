/*
Problem Statement 
Leetcode - 3
Given a string s, find the length of the longest
substring
without repeating characters.

Input: s = "abcabcbb"
Output: 3
*/
#include<bits/stdc++.h>
using namespace std;

class Solution { 
public : {
	int lengthOfLongestSubstring(string s){ 
		//take 2 pointers left pointer and right pointer
		int leftPtr = 0;
		int rightPtr = 0;
		//we have to find longest length
		int maxLength = INT_MIN;
		//also we need to make sure we are mantaining a windowSize hashmap array
		unordered_map<char,int> ump;
		while(rightPtr<s.size()){
			//now we need to write the shrink logic
			ump[rightPtr]++;
			//chcek if we have the map value greater than 2
			if(ump[rightPtr]>=2){
				ump[leftPtr]--;
				leftPtr++;
			}
			maxLength = max(maxLength,rightPtr-leftPtr+1);
			rightPtr++;
		}
		return maxLength;
	}	
}
}