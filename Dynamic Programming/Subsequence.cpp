/*
Understanding the take or not take concept in recursion and how it is helpful

Assume an array
[3 1 2] is the collection of elements.
Assume we get a subsequence
[3 2] //This is a sub sequence from the initial array.

[P] [N.P] [P] - We will be taking elements or not take the elements.

Pseudo Pattern
Assume array to be [3  1  2]
func(index){
	if(index >= n){
	print <array>
	return;
	}
	//add the elements in the list
	[].push_back(arr[i]); // push the elements
	//call the dfs again
	func(index+1,[]);// case of take the element
	[].pop_back(arr[i]); //pop elements
	func(index+1,[]);// case of not take the element
}
*/
#include <iostream>
#include <vector>
using namespace std;
//METHOD - 1 to generate the subsequence
void generateSubsequences(int index, vector<int>& current, vector<int>& nums, vector<vector<int>>& result) {
    if(index==nums.size()){
    	result.push_back(current);
    	return;
    }
    //I need to write a recursive function to generate the subsequence
    current.push_back(nums[index]);
    generateSubsequences(index+1,current,nums,result);//pick element
    current.pop_back();//remove the element
    generateSubsequences(index+1,current,nums,result); //dont pick the element
}

//This is the second method ti generate subsequence
void generateSubsequencesSecondMethod(int index, vector<int>& current, vector<int>& nums, vector<vector<int>>& result){

		result.push_back(current);
	
	//now we can iterate over and keep traversing till the end of all possible branches
	for(int i=index;i<nums.size();i++){
		current.push_back(nums[i]);
		generateSubsequencesSecondMethod(i+1,current,nums,result);
		current.pop_back();
	}
}

int main() {
    vector<int> nums = {1, 2, 3}; // Input array
    vector<vector<int>> result;  // To store all subsequences
    vector<int> current;         // Current subsequence

    // Call the function
    // generateSubsequences(0, current, nums, result);
    generateSubsequencesSecondMethod(0, current, nums, result);
    // Print the subsequences
    for (auto& subseq : result) {
        cout << "[";
        for (int num : subseq) {
            cout << num << ",";
        }
        cout << "]\n";
    }

    return 0;
}
