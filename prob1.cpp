//Ava Chong
//7/7/2025
//Problem 1: Two Sum
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.
// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:
// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:
// Input: nums = [3,3], target = 6
// Output: [0,1]
 
// Constraints:
// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.
// Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

#include <iostream>
#include <vector>

// solution first run through 

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        //create vector
        vector<int> sol = {};
        //go through array number
        for(int i = 0; i < nums.size(); i++){
            //check if next number in array aside from current number added up = target. if it does, add these indexes to solution vector and return.
            for(int j = i + 1; j < nums.size(); j++){
               if(nums[i] + nums[j] == target){
                    sol.push_back(i);
                    sol.push_back(j);
                    return sol;
               }
            }
        }
        return sol;
    }
};

//solution run through 2 --> trying to lower time complexity