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


int NinjaTrainingDP(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {
    // If already calculated, return the cached result
    if (dp[day][last] != -1) {
        return dp[day][last];
    }

    // Base case: For the first day, return the maximum points except the last task
    if (day == 0) {
        int maxi = 0;
        for (int i = 0; i < 3; i++) { // There are always 3 tasks per day
            if (i != last) {
                maxi = max(maxi, points[0][i]);
            }
        }
        return dp[day][last] = maxi; // Cache the result
    }

    // Recursive case: Try all tasks except the last task
    int maxi = 0;
    for (int i = 0; i < 3; i++) { // Iterate over the 3 tasks
        if (i != last) {
            int pointsForTask = points[day][i] + NinjaTrainingDP(day - 1, i, points, dp);
            maxi = max(maxi, pointsForTask);
        }
    }

    return dp[day][last] = maxi; // Cache the result and return [This will be giving us the current task points by restricting the current iteration by saying we dont have to take the previous task]
}

/*
Need to implement the tabulation or bottom up approach for the ninja training question

Steps to do that

Step 1> Let's declare a 2D table which will store the value and the index
*/
int NinjaTrainingDPTabulation(int day,int last,vector<vector<int>>& points,vector<vector<int>>& dp)
{
	//let's see the base case
	//we will be taking the initial max values from day 0
	dp[0][0] = max(dp[0][1],dp[0][2]);
	dp[0][1] = max(dp[0][0],dp[0][2]);
	dp[0][2] = max(dp[0][0],dp[0][1]);
	dp[0][3] = max(dp[0][0],dp[0][1],dp[0][2]);
	//let's take the max values from other index
	//let's loop over the indexes now
	for(int i=1;i<points.size();i++){
		for(int j=0;j<4;j++){
			//now we will just put the dp logic here
			int maxi = 0;
    		for (int i = 0; i < 3; i++) { // Iterate over the 3 tasks
    			dp[day][last]=0;
        		if (i != last) {
            	int pointsForTask = points[day][i] + dp[day-1][i];
            	dp[day][last] = max(maxi, pointsForTask);
        	}
    	}
	}
	//we will be returning the 
	return dp[n-1][3];//we will include this as n-1
}

//space optimisation for dp solutions


