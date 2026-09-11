class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> n_set;

        for(int i=0; i<nums.size(); i++){
            if(n_set.find(nums[i])==n_set.end()){
                n_set.insert(nums[i]);
            }else{
                return true;
            }
        }
        return false;

        
    }
};

/*
* Approach:
* Create an unordered_set that stores the vector element nums
* Loop through nums and check if the key exists in the set: if so return true; if not 
* insert it into the map.
* If loop runs fully then return false
*/
