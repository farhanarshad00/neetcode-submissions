class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> n_map;

        for(int i=0; i<nums.size(); i++){
            if(n_map.find(nums[i])==n_map.end()){
                n_map.insert({nums[i],1});
            }else{
                return true;
            }
        }
        return false;

        
    }
};

/*
* Approach:
* Create an unordered_map that stores the vector element as a key and its occurrence as * a value
* Loop through nums and check if the key exists in the map: if so return true; if not 
* insert it into the map.
* If loop runs fully then return false
*/
