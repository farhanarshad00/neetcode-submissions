class Solution {
public:

    string encode(vector<string>& strs) {
        string combo ="";

        for(int i=0; i<strs.size(); i++){
            int numeric_s_len = strs[i].length();
            string s_len = to_string(numeric_s_len);
            combo = combo + s_len + '#' + strs[i];
        }

        return combo;

    }

    vector<string> decode(string s) {
        vector<string> sol_vec;
        stringstream combo_stream(s);
        int length;

        while(combo_stream>>length){
            combo_stream.get();
            string word(length,' ');
            combo_stream.read(&word[0],length);
            sol_vec.push_back(word);
        }
        return sol_vec;

        


    }
};

/*
* What is known:
* Any string can be represented as a combination of its characters ASCII values
*   However, it is possible for equal ASCII sums to come from different character combinations
*   Therefore ASCII method fails
* Multiple strings can be combined into one string
*   The difficulty is in decomposing them into their original strings
*   Perhaps a flag like a comma or slash could be used to distinguish separate strings
*
* Approach: Use string arithmetic to encode string vector and use stringstream to decode 
* In the encode function:
*   Initialize a string combo 
*   Loop through the vector strs and record s_len=strs[i].length() then 
*   set combo= combo+ s_len +'#'+strs[i]
*   Return combo
* In the decode function:
*   Initialize a vector<string> sol_vec
*   Initialize a stringstream object combo_stream(s)
*   Initialize an int length
*   Loop while(combo_stream<<length)
*       Use .get() to consume the '#' delimiter
*       Create an empty string of size=length
*       Use combo_stream.read(&word[0],length) to populate the string
*       Use push_back to append the string to sol_vec
*   return sol_vec
*   
*
*
*/