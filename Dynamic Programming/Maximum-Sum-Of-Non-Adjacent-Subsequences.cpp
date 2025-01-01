/*
Problem Statement

Given an array of ‘N’  positive integers, 
we need to return the maximum sum of the subsequence 
such that no two elements of the subsequence are 
adjacent elements in the array.

A subsequence of an array is a list with elements of 
the array where some elements are deleted ( or not deleted at all) 
and the elements should be in the same order in the subsequence 
as in the array

Input Cases
N = 3
array = [1,2,4]
output 5
*/
/*
Since we have subsequence hence we need to make sure we are
taking the subsequence elements.
*/

#include <iostream>
#include <vector>
using namespace std;

int generateMaxSumNonAdjacent(int index , vector<int>& nums , vector<int>& dp){

//base case if it goes negative
if(index<0){
	return 0;
}
if(dp[index]!=-1){
	return dp[index];
}
int pick = nums[index] + generateMaxSumNonAdjacent(index-2,nums,dp);//i am picking the non adjacent element
int notPick = generateMaxSumNonAdjacent(index-1,nums,dp);//i am not picking the adjacent elements

return dp[index] = max(pick,notPick);

}

// Function to find the maximum sum of non-adjacent subsequences
// void generateMaxSumNonAdjacent(int index, vector<int>& current, vector<int>& nums, int& maxSum) {
//     // Calculate the current sum of the subsequence
//     int currentSum = 0;
//     for (int num : current) {
//         currentSum += num;
//     }
//     // Update the maximum sum
//     maxSum = max(maxSum, currentSum);

//     // Iterate over all elements starting from the current index
//     for (int i = index; i < nums.size(); i++) {
//         current.push_back(nums[i]); // Pick the current element
//         generateMaxSumNonAdjacent(i + 2, current, nums, maxSum); // Skip the adjacent element (move to i + 2)
//         current.pop_back(); // Backtrack to remove the last element and explore other options
//     }
// }


int main() {
    // Input: Modify this vector to test different inputs
    vector<int> nums = {3, 2, 7, 10}; // Example input
	vector<int> dp(nums.size(),-1);//decalre a vector 1D DP Table
    // Call the recursive function starting from the last index
    int maxSum = generateMaxSumNonAdjacent(nums.size() - 1, nums,dp);
    // Print the result
    cout << "Maximum Sum of Non-Adjacent Subsequences: " << maxSum << endl;
    return 0;
}



