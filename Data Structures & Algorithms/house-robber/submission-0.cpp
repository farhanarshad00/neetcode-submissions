class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> best(2);
        int n = nums.size();
        int i = 2;
        int tmp = 0;
        if(nums.size()==1){
            return nums[0];
        }
        best[0] = nums[0];
        if(nums[0]>nums[1]){
            best[1]=nums[0];
        }else{
            best[1] = nums[1];
        }

        while(i<n){
            tmp = best[1];
            best[1] = max(tmp,(best[0]+nums[i]));
            best[0] = tmp;
            i++;
        }
        return best[1];

    }
};

/*
* What is known:
* Each house is an index in nums and the money inside it is nums[i].
* No adjacent houses can be hit.
* Base Case: nums.size()=1 and maximum money that can be obtained = nums[0].
* For n=5: Starting at step 0 you can only go to step 2 then step 4 OR step 3.
*          Starting at step 1 you can only go to step 3.
*/