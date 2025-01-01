/**
Problem Statement Explaination :
We have an array of jobs with their deadlines and profits.
We need to maximize the profit by completing the jobs within their deadlines.
 */

/*
Understanding the algoritm we will be using
Greedy: Greedy algorithm is an algorithmic paradigm that helps in selecting the most optimised solution.
One thing about greedy algorithm is that it doesnt not care about the future, it only cares about the current best solution.
*/

#include <bits/stdc++.h>
using namespace std;

struct Job
{
    char id;    // Job Id
    int dead;   // Deadline of the job
    int profit; // Profit if the job is done before or on the deadline
};

// now we need to have the comparison function to comare the maximum profit
bool comparison(Job a, Job b)
{
    return a.profit > b.profit;
}

#include <iostream>
#include <algorithm>
using namespace std;

// Structure for jobs
struct Job
{
    char id;    // Job ID
    int dead;   // Deadline
    int profit; // Profit
};

// Comparison function to sort jobs by profit in descending order
bool comparison(Job a, Job b)
{
    return a.profit > b.profit;
}

void jobSequencing(Job arr[], int n)
{
    /*sort the jobs in descending order of there profit
     */
    sort(arr, arr + n, comparison);
    // store the visited value of slots
    vector<bool> slots(n, false);
    // store the result of the jobs
    vector<char> result(n);
    // will loop over the array of objects of type Job
    for (int i = 0; i < n; i++)
    {
        // now we need to check the deadline of the job
        // we are finding the next minimum deadline to place the job
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
        {
            if (slots[j] == false)
            {
                // mark the slot as visited
                slots[j] = true;
                result[j] = arr[i].id;
                break;
            }
        }
    }

    // Print the result
    cout << "Selected Jobs: ";
    for (int i = 0; i < n; i++)
    {
        if (slots[i])
        {
            cout << result[i] << " ";
        }
    }
    cout << endl;
}
