/*
You have n  tiles, where each tile has one letter tiles[i] printed on it.
Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
*/
#include<bits/stdc++.h>
using namespace std;
//here also we wont have a base case 
//in subset we wont have any base cases.
//this won't be a subset but rather it will be a permutation since AB and BA are different.
void getLetterTilePossibilities(string tiles,set<string>& answer,string path,unordered_map<int,bool>& visited){
//when we are purely finding possibilities we dont have to think of any base case 
//naturally you keep recursively moving once the approach is done. unless we have any condition we dont need base case
	answer.insert(path);
	for(int i=0;i<nums.size();i++){
		if(visited[i]==true)
			continue;
		visited[i] = true;
		path.push_back(s[i]);
		getLetterTilePossibilities(tiles,answer,path,visited);
		visited[i] = false;
		path.pop_back();
	}
}