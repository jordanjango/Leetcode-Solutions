#include<bits/stdc++.h>
using namespace std;

int minMinSubArrayLength(int target, vector<int>& nums) {
    // Create 2 pointers
    int leftPtr = 0;
    int rightPtr = 0;
    // Declare a min flag
    int minFlag = INT_MAX;
    int sum = 0;
    // Loop over the nums array
    for (int i = rightPtr; i < nums.size(); i++) {
        sum += nums[i];
        // Adjust the window to find the minimum subarray length
        while (sum >= target) {
            minFlag = min(minFlag, i - leftPtr + 1);
            sum -= nums[leftPtr];
            leftPtr++;
        }
    }
    return (minFlag == INT_MAX) ? 0 : minFlag;
}

int main() {
    int target, n;
    cout << "Enter the target sum: ";
    cin >> target;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = minMinSubArrayLength(target, nums);
    if (result == 0) {
        cout << "No subarray meets the target sum." << endl;
    } else {
        cout << "The minimum length of a subarray with the target sum is: " << result << endl;
    }

    return 0;
}
