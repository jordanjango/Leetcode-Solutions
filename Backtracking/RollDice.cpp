/*
This is the backtracking approach authored by Anshuman Nehru for calculating the result.
Count all the ways to roll the dice k times so that the total number of nodes equals N

Input Format

1 line contains 2 intergers (k and N)
Constraints

k > 0 N > 0
Output Format
1 number of ways to roll the dice

Sample Input 0
2 10
Sample Output 0
3
*/

#include <bits/stdc++.h>
using namespace std;

/* Roll number of dice is a variation of combination sum with subset size as 'numberOfRolls' */
void getNumberOfDiceRoll(vector<vector<int>>& result, vector<int>& answer, int numberOfRolls, int targetApproach, vector<int>& numbersOnDice) {
    // Base case: If we have used the required number of rolls
    if (answer.size() == numberOfRolls) {
        // Check if the target is achieved
        if (targetApproach == 0) {
            result.push_back(answer);
        }
        return;
    }

    // Explore all options for dice rolls (from 1 to 6)
    for (int i = 0; i < numbersOnDice.size(); i++) {
        if (targetApproach >= numbersOnDice[i]) { // Only proceed if the current number doesn't exceed the target
            answer.push_back(numbersOnDice[i]);   // Choose the current number
            getNumberOfDiceRoll(result, answer, numberOfRolls, targetApproach - numbersOnDice[i], numbersOnDice);
            answer.pop_back(); // Backtrack
        }
    }
}

int main() {
    vector<vector<int>> result; // To store all valid combinations
    vector<int> answer;         // Current combination
    int numberOfRolls = 9;      // Number of dice rolls
    int targetApproach = 44;    // Target sum
    vector<int> numbersOnDice;

    // Populate the dice faces (1 to 6)
    for (int i = 1; i <= 6; i++) {
        numbersOnDice.push_back(i);
    }

    // Call the recursive function
    getNumberOfDiceRoll(result, answer, numberOfRolls, targetApproach, numbersOnDice);

    // Print the number of valid combinations
    cout << "The number of ways to get the target is: " << result.size() << endl;

    return 0;
}
