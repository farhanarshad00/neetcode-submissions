class Solution {
public:
    int findMin(vector<int> &nums) {
        int k = 0;
        int low = 0;
        int high = nums.size()-1;

        while(nums[low]>nums[high]){
            low++;
            k++;
        }
        return nums[k];
    }
};

/*
* What is known:
* Rotating k times moves the last k elements to the front of the array.
* For example in nums = {1,2,3,4,5,6} and k=1, nums with 1 rotation becomes nums={6,1,2,3,4,5}.
* When k = nums.size() then the number of rotations brings nums back to its original state.
* There can only be [1,n] rotations.
* nums will always be at least one element long and each element ranges from [-1000,1000].
* If nums[0] > nums[nums.size()-1] then the array has been rotated.
* The first nums[i]<=nums[nums.size()-1] marks the beginning of the original array.
* It can be determined how many times the array was rotated by counting i's till nums[i]<=nums[nums.size()-1].
*
* Trivial Solution: Loop through nums and keep a running minimum, then return that. TC = O(n).
*
* Approach:
* Need to find out how many times the array was rotated in order to determine what high and low should be set to.
* Initialize low = 0, high = nums.size()-1, and k=0.
* While nums[low]>nums[high]: increment k to track the number of rotations.
* Afterwards acknowledge that max(nums) = nums[k-1] (to account for the arrays 0 index) and min(nums)=nums[k].
* return nums[k]
*
*/