class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> dups;
        for(int i=0;i<nums.size();i++){
            if(dups.find(nums[i])==dups.end()){
                dups.insert({nums[i],1});
            }else{
                return true;
            }
        }
    return false;   
    }
};