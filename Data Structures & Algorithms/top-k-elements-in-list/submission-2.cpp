class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq_map;
        vector<vector<int>> freq_vec(nums.size()+1);
        vector<int> sol_vec;

        for(int i=0; i<nums.size();i++){
            freq_map[nums[i]]++;
        }

        for(auto& it:freq_map){
            freq_vec[it.second].push_back(it.first);
        }

        for(int j=nums.size();sol_vec.size()<k;j--){
            for(auto& it:freq_vec[j]){
                sol_vec.push_back(it);
                if(sol_vec.size()==k){               
                    return sol_vec;
                }
            }
        }

    return sol_vec;   
    }
};

/*
* Problem Type: How many times have I seen this value before?
* Approach: Use hash data structure to track occurences of values
* Create an unordered_map<int,int> freq_map where the key,value pair is nums[i],occurence
* Loop through nums and set freq_map[nums[i]]++
* Loop through freq_map and set freq_vec[it.second]=it.first
* Loop backward through freq_vec have a second nested range-based loop going through freq_vec[i]
* in the range based loop initialize an int count
* Create a check to see if count==k:
*   if it doesn't, populate the solution vector sol_vec.push_back(it.second) and increment count 
*   if it does, return sol_vec
* 

* Roadblocks:
* Can't sort a map by values to get the keys pointing to the highest occurences. 
* If you switch key,value pair to occurence,nums[i] can't increment the key of a map.
* 
* 
*/