/*
Problem Statement
187. Repeated DNA Sequences

The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.
Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
*/

//seen.find (or find method in set will be returning a 
//pointer to 
//poisiton if the element or the string is found 
//but if we dont find it we will be returning the end() pointer)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
       unordered_set<string> seen;
       unordered_set<string> repeated;
       vector<string> result;
       cout<<"hello world";
       //This is for loop
       for(int i=0;i+9<s.size();i++){
       	//take the substring
       	string substring = s.substr(i,10);//fetch out the 10 values
       	if(seen.find(substring)!=seen.end()){
       		repeated.insert(substring);
       	}else{
       		seen.insert(substring);
       	}
       }

      for(const string& str : repeated){
      	result.push_back(str);
      }
      return result;
    }
};


//one more solution is 2 keep concatinating the char check if the 
//current char has more than 2 letters pushthe string in the result vector
