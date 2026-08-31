class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            auto it = s.find(nums[i]);
            if(it != s.end()){
                return true;
            }else{
                s.insert(nums[i]);
            }

            
        }
        return false;    
    }
};