class Solution {
public:
    bool isPalindrome(string s) {
        int l_ptr = 0;
        int r_ptr = s.length()-1;

        if(s.empty()){
            return true;
        }

        while(l_ptr<r_ptr){
            if(isalnum(s[l_ptr]) && isalnum(s[r_ptr])){
                if(toupper(s[l_ptr]) == toupper(s[r_ptr])){
                    l_ptr++;
                    r_ptr--;
                    continue;
                }else{
                    return false;
                    }
            }else if(isalnum(s[l_ptr])==false){
                l_ptr++;
            }else if(isalnum(s[r_ptr])==false){
                r_ptr--;
            }
        }
        return true;
        
    }
};

/*
* What we know:
* A palindrome is a string that reads the same front to back 
*   (ignoring case sensitivity and non-alphanumeric characters)
* All characters must have a duplicate to be a palindrome
* Approach: Use two pointers at the leftmost index and rightmost index tracking equality
* Initialize two pointers int l_ptr=0 and int r_ptr=s.length()-1
* Loop while l_ptr<r_ptr and check if l_ptr=r_ptr: if so continue; if not return false
* After loop ends return true
*
* Edge Cases-
* String is empty then r_ptr would be initialized as -1
*   Fix: Check if s is empty: if so return true
* String contains non-alphanumeric characters (, / #, etc)
*   Fix: Add isalnum() checks to the loop
*/