//find-the-duplicate-number

/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.*/

/*class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;
        int count = 0;
        for(int i = 0;i<nums.size();i++){
            for(int j = i+1;j<nums.size();j++){
                if(nums[i] == nums[j]){
                ans = nums[i];
                }
            }
        }
        return ans;
    }
};*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Initialize the tortoise and hare
        int tortoise = nums[0];
        int hare = nums[0];
        
        // First phase: finding the intersection point of the two runners
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);
        
        // Second phase: finding the entrance to the cycle
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        
        return hare;
    }
};
