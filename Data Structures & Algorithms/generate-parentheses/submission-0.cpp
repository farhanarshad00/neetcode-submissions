//OFFICIAL NEETCODE SOLUTION
class Solution {
public:
    void backtrack(int openN, int closedN, int n, vector<string>& res, string& stack) {
        if (openN == closedN && openN == n) { //If the string is valid push it to the array
            res.push_back(stack);
            return;
        }

        if (openN < n) { //If there is still space left in the string
            stack += '('; //Add an open parenthese
            backtrack(openN + 1, closedN, n, res, stack);// Recursive call to backtrack function with incremented open count
            stack.pop_back();//Pop end of the stack
        }
        if (closedN < openN) {//If there are less closes than opens in the string
            stack += ')';// Add a close parenthese
            backtrack(openN, closedN + 1, n, res, stack);// Recursive call to backtrack function with incremented close count
            stack.pop_back();//Pop end of the stack
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stack;
        backtrack(0, 0, n, res, stack);
        return res;
    }
};
/*
* What is known:
* n is between 1 and 7.
* The base case for any n is "() () ... ()" where the number of pairs of parentheses is equal to n.
* For example: n=2 then the base combination of two pairs of parentheses is "() ()".
* Working backwards we can decide to enclose one pair in another to get "(())".
* Therefore we end up with the answer of all well formed parentheses strings we can make with n = 2 as ["(())","()()"].
* Now that we have n = 1 and n = 2 defined we need a way to define all the possible well-formed parentheses strings for n > 2.
* We know that after the base case the next possible combination is enclosing one pair within another, however with n = 3 the possibilities of pairs enclosed in each other grows from 4 with the possible combinations of pairs enclosed in pairs being ["((()))","(()())","(())()","()(())"].
* Along the base case this forms and array with 5 strings inside of it: ["((()))","(()())","(())()","()(())","()()()"].
* The time complexity being O(4^n/sqrt(n)) suggests a formula for determining possible well-formed parentheses strings based on the number of pairs.
* Before deciding an approach we need to determine the amount of possible strings their are where at least one pair is enclosed in another given n pairs.
* For n = 1 there are 0 possible strings with enclosed pairs, for n = 2 there is 1 possible string with an enclosed pair, however for n = 3 there are 4 possible strings where there is at least one pair enclosed in another.
* Intuitively, this tells us that the pattern begins at n = 3 and that n = 1 and n = 2 are base cases.
* n = 4 yields ["()()()()","()()(())","()(())()","(())()()","(())(())","()((()))","((()))()","(((())))"] which has 8 possible strings and 7 possible strings where at least one pair is enclosed in another.
* 
* Couldn't solve within time limit and as a result looked at the solution and implemented it.
*
* Miss log:
* Overcomplicated the prompt
* When dealing with string validity check if the string satisfies validity conditions after every change.
* State conditions for a string to be valid before writing code.
*  
*/