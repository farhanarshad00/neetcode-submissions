class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> wordmap;
  
        

        if(s.length()!=t.length()){
            return false;
        }
        for(int i=0; i<s.length(); i++){
            wordmap[s[i]]++;
        }
        for(int j=0; j<t.length(); j++){
            wordmap[t[j]]--;
        }
        for(auto& [key, value] : wordmap){
            if(value != 0){
                return false;
                }
        }
       


   
    return true;
    }
};
