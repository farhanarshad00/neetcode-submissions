class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();
        unordered_map<char,int> char_map;
        int count=0;
        
        

        if(s_len == t_len){
            for(int i=0; i<s_len; i++){
                if(char_map.find(s[i]) == char_map.end()){
                    char_map.insert({s[i],1});
                }else{
                    char_map.at(s[i])=char_map.at(s[i])+1;
                }
            }

            for(int j=0; j<t_len; j++){
                if(char_map.find(t[j]) == char_map.end()){
                    return false;
                }else{
                    char_map.at(t[j])=char_map.at(t[j])-1;
                }
            }

            for(auto& it : char_map){
                if(it.second!=0){
                    count++;
                }else{
                    continue;
                }
            }
            if(count==0){
                return true;
            }else{
                return false;
            }


        }else{
            return false;
        }
        
        
    }
};
/*
Approach 1:
Check if both strings have the same length
Create an unordered_map with key=char and value=occurences 
Loop through s and check if key is in map already: if so add 1 to its value,if not insert key-value pair with key being s[i] and value being 1
Loop through t and check if key is in the map: if not return false, if so decrement one from its corresponding value
Loop through map and check if any key maps to a nonzero value: if so increment count
Finally check if count==0: if so return true,if not return false
*/