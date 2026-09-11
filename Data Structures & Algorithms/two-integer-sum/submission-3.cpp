class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> num_map;
        vector<int> ans_vec;

        for(int i=0; i<nums.size(); i++){
            int addend = target - nums[i];
            if(num_map.find(addend) != num_map.end()){
                return {num_map[addend],i};
            }
            num_map.insert({nums[i],i});
        }
    }
};
