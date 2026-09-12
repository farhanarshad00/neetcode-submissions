class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prod_vec(nums.size());
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        int product = 0;

        prefix[0]=1;
        suffix[nums.size()-1]=1;

        for(int i=1;i<=nums.size()-1;i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        for(int j=nums.size()-2;j>=0;j--){
            suffix[j] = suffix[j+1] * nums[j+1];
        }

        for(int k=0;k<nums.size();k++){
            product = prefix[k] * suffix[k];
            prod_vec[k]=product;
        }
        return prod_vec;
        
            
    }
};
/*
* Approach: Use prefix/suffix product for every i in nums
* create 3 vector: prod_vec, prefix, and suffix. 
* Initialize prefix[0]=1 and suffix[nums.size()-1]=1
* Loop through nums and compute prefix[i]=prefix[i-1] x nums[i-1]
* Reverse loop through nums and compute suffix[i]=suffix[i+1]*nums[i+1]
* Loop through nums again and multiply prefix[i] and suffix[i] and push back the product to prod_vec
* Return prod_vec
*/