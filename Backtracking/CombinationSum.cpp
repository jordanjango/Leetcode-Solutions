//Backtracking revision
/*
!Combination Sum
TODO :Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the
frequency of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that 
sum up to target is less than 150 combinations for the given input.
*/
/*
Example test cases
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
*/
/*
We can use one number from candidates multiple number of times
*/
#include <iostream>
#include <vector>
using namespace std;

// Function to find all combinations that sum up to the target
// Input: candidates (vector<int>), target (int)
// Output: vector<vector<int>> containing all the valid combinations
vector<vector<int>> combinationSum(vector<int>& candidates, int target,int index,vector<int>& answer) {
    vector<vector<int>> result;
    //Writting the base case
    if(target==0){
    	result.push_back(answer);
    	return result;
    }
    //now we will be looping over the candidates array and finding the sum
    for(int i=index;i<candidates.size();i++){
    	//because element should not become negative
    	if(nums[i]>target)
    		continue;
    	answer.push_back(candidates[i]);
    	combinationSum(candidates,target-nums[i],i+1;answer);
    	//backtrack if we dont have any answer
    	answer.pop_back();
    } 
}

int main() {
    // Sample Input
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    int index = 0;
    vector<int> answer;
    // Sample function call to test
    vector<vector<int>> result = combinationSum(candidates, target,index,answer);

    // Output the result
    for (auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
