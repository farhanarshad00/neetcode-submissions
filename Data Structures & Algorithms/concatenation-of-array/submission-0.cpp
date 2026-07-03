class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int two_n = 2 * n;
        vector<int> ans(two_n);

        for(int i=0; i<n;i++){
            ans[i]=nums[i];
            ans[i+n]=nums[i];
        }
    return ans;    
    }
};

/*
* Approach: Loop based solution copying initial vector values twice
* 1. Initialize size n,two_n, and new vector ans with size(two_n)
* 2. Loop through nums and populate ans with corresponding values from nums
* 3. return ans
*/