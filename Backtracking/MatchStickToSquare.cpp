/*
You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. 
You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and 
each matchstick must be used exactly one time.

Return true if you can make this square and false otherwise.



Logic and approach
Our logic or intution to do this was to find what can be the max side we can have for one square
we will try putting that side in a seperate array.
why?
so we have 4 side 
0 | 0 | 0 | 0
now we will be adding each side in the array and checking if the each side we added is equal to the max size.
*/

#include<bits/stdc++.h>
using namespace std;


//this will be placing the matchsticks placement functions
bool placeMatchStick(vector<int>& matchsticks, vector<int>& sides, int index, int sideOfSquare){
	//In this base case we will be stopping after we have iterated all the sides and check if each side which we have placed is equal to sideOfSquare
	if(index==matchsticks.size()){
		return sides[0]==sideOfSquare and sides[1]==sideOfSquare and side[2]==sideOfSquare and side[3]==sideOfSquare;
	}
	//now we can find all the possibility by placing matchsticks inside the side array
	for(int i=index;i<4;i++){
		side+=matchsticks[i];//add the current matchsticks.
		if(placeMatchStick(matchsticks,sides,i+1,sideOfSquare))
				return true;
		side-=matchsticks[i];//remove the matchsticks when going to previous calls.
	}
}