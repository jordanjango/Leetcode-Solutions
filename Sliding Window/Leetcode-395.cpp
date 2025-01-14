//this will use divide and conquer approach to solve the problem,we will be implementing and understanding it now and the pattern
#include <iostream>
#include <unordered_map>

using namespace std;

bool isValidWindow(unordered_map<char, int>& freq, int k) {
    int unique = 0;
    for (auto& entry : freq) {
        if (entry.second > 0 && entry.second < k) { // This condition was missing
            return false; 
        }
        if (entry.second > 0) {
            unique++;
        }
    }
    return unique >= k;
}

int longestSubstring(string s, int k) {
    if (s.length() < k) {
        return 0;
    }

    unordered_map<char, int> freq;
    int start = 0, end = 0, max_len = 0;

    while (end < s.length()) {
        freq[s[end]]++;

        // Contract the window if necessary
        while (start <= end && !isValidWindow(freq, k)) { 
            freq[s[start]]--;
            start++;
        }

        // Update max_len
        max_len = max(max_len, end - start + 1); 

        end++;
    }

    return max_len;
}


int main() {
    string s = "aaabb";
    int k = 3;
    int longest_len = longestSubstring(s, k);
    cout << "Longest substring length: " << longest_len << endl;
    return 0;
}