/*
Ninja Training
A ninja trains for N days and each day ninja can perform 3 activities
Now each day they will have 3 activities and we need to find out how much points it can get in a day.
*/
#include<bits/stdc++.h>
using namespace std;

/*
Recursive approach : This will be checking all the possibilities and giving us the solution!
*/
int NinjaTraining(int day,int last,vector<vector<int>>& points){
	//now we will be first having our base case
	if(day==0){
		//we will be returning the max value of that day
		int maxi = 0;
		for(int i=0;i<points.size();i++){
			if(i!=last)
				maxi = max(maxi,points[0][i]);//take the maximum point of day 1 (in here day 0)
		}
		return maxi;
	}
	//now lets explore options on other days
	maxi = 0;
	int maximumPoints = 0;
	for(int i=0;i<points.size();i++){
		if(i!=last){
			maximumPoints = maximumPoints + NinjaTraining(day-1,i,points);
			maxi = max(maxi,maximumPoints);
		}
	}
	return maxi;
}
/*
Let's use the dynamic programming approach by declaring a 2D DP memo table
*/


int NinjaTrainingDP(int day,int last,vector<vector<int>>& points,vector<vector<int>> dp(n, vector<int>(3, 0));){

}