class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int diff = 0;
        unordered_map<int,int> numap;
        vector<int> sols;

        for(int i=0; i<nums.size(); i++){
            diff = target - nums[i];
            if(numap.find(diff)!=numap.end()){
                sols.push_back(numap[diff]);
                sols.push_back(i);
                break;
            }
            numap.insert({nums[i],i});
            }
       
    return sols;    
    }
};
