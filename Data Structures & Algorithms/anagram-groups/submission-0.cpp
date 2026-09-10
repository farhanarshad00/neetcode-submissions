class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans_vec;
        unordered_map<string,vector<string>> ana_map;


        for(int i=0; i<strs.size(); i++){
            string dummy_string = strs[i];
            sort(dummy_string.begin(),dummy_string.end());

            if(ana_map.find(dummy_string)==ana_map.end()){
                ana_map.insert({dummy_string,{strs[i]}});
            }else{
                ana_map[dummy_string].push_back(strs[i]);
            }
        }
        for(auto& it:ana_map){
            ans_vec.push_back(it.second);
        }

        return ans_vec;
    }
};
/*
 * Approach: 
 * Create an vector<vector<string>> ans_vec to be returned at end of program
 * Create an unordered_map ana_map where [key,value] corresponds to 
 * [string dummy_string,vector<string> anas].
 * Loop through the passed vector of strings strs
 * For each string in the vector copy it to a dummy string, sort it (automatrically sorts to ascending order by ASCII value of chars).
 * Then check if the sorted dummy string exists as a key in ana_map; if it does append strs[i] to corresponding value vector, 
 * if it doesn't then use that dummy_string to insert a [key,value] pair in ana_map with ana_map.insert({dummy_string,{strs[i]}}).
 * After the loop finishes use a range based for loop to insert all ana_map values to ans_vec and return

 * 
 * Edge cases:
 * - strs is empty
 * - 
 */