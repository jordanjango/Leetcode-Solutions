/*
Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
Return a list of all possible strings we could create. Return the output in any order.
Example 1:

Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

Logic that we can implement is
s = "a1b2"

IMP POINT 
notice one thing
when we have permutations we are always dealing with indexes
so we usually deal with swapping or changing the index value itself.


*/


#include<bits/stdc++.h>
using namespace std;
//notice one thing
//when we have permutations we are always dealing with indexes
//check other permutations once and see 
void generateLetterPermutation(string s,int idx,set<string>& result){
	if(idx==s.size()){
		result.insert(s);//we will modify the same char as capitalisation
		return;
	}
	//let's loop on the string
	for(int i=idx;i<s.size();i++){
		if(isupper(s[i])){
			s[i] = tolower(s[i]);
		}else{
			s[i] = toupper(s[i]);
		}
		generateLetterPermutation(s,idx+1,result);
	}
}


//generate the permutations
//why this wont work?
//this wont work because we have to either convert it into lower case or in upper case 
// void generateLetterPermutation(string s,int idx,set<string>& result){
// 	if(idx==s.size()){
// 		result.insert(s);//we will modify the same char as capitalisation
// 		return;
// 	}
// 	//let's loop on the string
// 	for(int i=idx;i<s.size();i++){
// 		if(isAlpha(s[i])){
// 			s[i] = toUpper(s[i]);
// 			generateLetterPermutation(s,idx+1,result);
// 			s[i] = toLower(s[i]);//backtrack to previous state in this one
// 		}
// 	}
// }