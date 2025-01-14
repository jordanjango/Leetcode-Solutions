/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

#include<bits/stdc++.h>
using namespace std;

//Function to calculate the combination of letters based on the key pressed
void backtracking(string digits, string result_combination, vector<string>& ans, int index,
                       string map[]){
	if(index==digits.size()){
		ans.push_back(result_combination);
		return;
	}
	//now lets take the key value to find out the string
	int key = digits[index]-'0';
	//this will give us the string value of the map
	string value = map[key];

	for(int i=0;i<value.size();i++){
		result_combination.push_back(value[i]);
		backtracking(digits,result,result_combination,ans,index+1,map);
		result_combination.pop_back();
	}
}