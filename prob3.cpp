// Given a string s, find the length of the longest substring without duplicate characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //set up initial solution value
        int sol = 0;
        //create vector as long as ascii table
        vector<int> charCounter(128);
        //secondary index counter
        int j = 0;
        for(int i = 0; i < s.length(); i++){
            //add character to character counter vector
            charCounter[s[i]]++;
            //while that character in index is counted, move to next position and subtract count of character there until you encounter same character again
            while(charCounter[s[i]] > 1){
                charCounter[s[j++]]--;
            }
            //find the max between current solution number and the number of numbers gone through - index of how last longest substring, + 1 for offset and set to new solution
            sol = max(sol, i - j + 1);
        }
        return sol;
    }

};