class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid = 0;

        while(low < high){
            mid = (high + low) / 2;
            if(nums[mid] > nums[high]){
                low = mid + 1;
            }else{
                high = mid;
            };
        }
        return nums[high];
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
* Approach: Modified Binary Search
* Initialize two variables, low = 0, high = nums.size()-1, and mid = 0.
* While low <= high:
*   Calculate mid = (high + low)/2
*   Check if mid satisfies the condition of nums[mid] > nums[nums.size()-1]: 
*       if so set low = mid since no index before it contains the minimum.
*       if not return nums[mid].
* If the loop runs fully return nums[high].
* 
*
*/