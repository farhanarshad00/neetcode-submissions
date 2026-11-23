class Solution {
public:
    int characterReplacement(string s, int k) {
        if(k == s.length()){return s.length();}

        vector<int> chars(26);
        int max_len = 1;
        int l = 0;

        for(int r = 0; r < s.length(); r++){ //Populates the alphabet vector
            chars[(s[r] - 'A')]++;

            while((r - l + 1) - *max_element(chars.begin(),chars.end()) > k){
                chars[(s[l]) - 'A']--;
                l++;
            }
            max_len = max(max_len, (r - l + 1));
        }



        return max_len;
        
    }
};

/*
* What is known:
* You can replace k characters in s with any uppercase english letter.
* Optimal approach to get the longest possible substring would be to first record the longest repeating character substring in s then change the k elements next to it into that character.
* k is in the range of [0,s.length].
* If k == 0 then return the longest repeating character (rc) substring in s.
* If k == s.length then return s.length.
* 
* Approach: Replacement using variable sliding window
* First check if k == s.length: if so return s.length; if not continue.
* Initialize a vector of size 26 representing the alphabet.
* Populate the vector by looping through the string and incrementing the vector elements value based on their occurrences within the string.
* Determine the amount of occurrences the dominant character in the string has by using *max element().
* Find the amount of occurences non-dominant characters in the string by finding the sum of the vector - dominant_count.
* If k == ndom_cnt then return dom_cnt + k.
* 
*/