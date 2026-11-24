class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26);
        int l = 0;
        int max_len = 0;
        

        for(int r = 0; r < s.length(); r++){
            counts[(s[r] - 'A')]++;

            while((r - l + 1) - *max_element(counts.begin(), counts.end()) > k){
                counts[(s[l] - 'A')]--;
                l++;
            }
            max_len = max(max_len, (r - l + 1));
        }
        return max_len;
    }
};

/*
* What is known:
* k is in [0,s.length].
* If k = 0 then return the lrc substring in s.
* There are 26 letters in the alphabet and uppercase chars can be converted to ints by subtracting 'A'.
* Approach: Variable Size Sliding Window Replacement
* Initialize a vector<int> named counts with size 26 that stores the count of each letter in s.
* Initialize an int named max_len that records the length of the lrc substring encountered so far.
* Loop through the string s and push the numeric value of s[r] into counts.
* The possible number of replacements depends on the size of k and the number of non dominant elements.
* The size of the window is determined by how many dominant elements there are consecutively (r - l + 1) and the size of k is just k.
* The number of non-dominant elements is determined by (r - l + 1) - number of dominant character occurences.
*   In the loop, while((r - l + 1) - *max_element(counts.begin(),counts.end()) > k ):
*       Decrement the occurence of s[l] from the vector.
*       Set l = r.
*       By doing so we are effectively shrinking the window so that there a valid number of replacements.
* Set max_len = max(max_len,(r - l + 1)).
* After the loop ends, return max_len.
* 
*/