class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long total_h = 0;
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        // Koko must spend an hour per pile therefore min rate = max(pile[i])
        if(h == piles.size()) return high;

        int k = 0;
        int hpp = 0; // hour per pile

        while(low < high){
            k = low + (( high - low ) / 2); // Overflow Protected Calculation
            
            for(int i=0; i<piles.size();i++){
                //piles[i] + k - 1 in the numerator makes remaining bananas count as a leftover hour
                hpp = ((piles[i]+k-1)/k); 
                total_h = total_h + hpp;
            }

            if(total_h > h){
                total_h = 0;
                low = k + 1;
            }else{
                total_h = 0;
                high = k;
            }
        }
        
        return high;
    }
};

/*
* What is known:
* k represents the bananas eaten per pile rate.
* Doesn't matter if the pile has less bananas then k, koko must stay at that pile for the full hour.
* Koko can spend multiple hours at one pile.
* The length of the piles is <= h, meaning that there will always be a rate at which koko can eat every banana in the piles.
* The length of the piles is between [1,10000] and the piles[i] is between [1,1,000,000,000] meaning there will always be at least one banana for koko to eat.
* Therefore the base case of k is one banana per hour where this is only 1 pile holding one banana and there is at least one hour on the clock.
* The brute force solution would be to choose k = piles.max(), where the rate of bannas per hour is equal to the maximum amount of bananas throughout the piles.
* Therefore k should be a number between [1,piles.max()].
* The goal is to find a minimum integer that fulfills the condition of eating all the bananas in the hours given.
* If the hours == piles.size() then k must be equal to the max of piles, since Koko only has one hour to eat all the bananas in every pile.
* If hours>piles.size() then hours-piles.size() returns the excess amount of hours Koko can give to all the piles.
* hours/piles.size() gives the max time Koko can dedicate per pile.
* Therefore the rate has to be calculated as a value s.t k * max_time > piles[i] for all i in piles.
* Could try to sort piles and use binary search to find a mid s.t mid*max_time > piles[i] for all i.
* However, that would require looping through piles for every potential mid value and doesn't account for an uneven time distribution (ie Koko spend 2 hours at one pile but only one hour on another pile).
* 
* Approach: Binary Search on possible rates
* Sort the vector in ascending order.
* The range of possible rates is between [1,max(piles)].
* Initialize two variables low=1 and high = max_element(piles.begin(), piles.end()).
* Initialize a middle value k = (low+(high-low))/2 to act as the starting rate.
* While low<high:
*   Check if k works by checking if the total sum of hours Koko eats for using rate k <= h.
*       Use ceil(pile/hours) to find the amount of time Koko eats per pile and sum that.
*   If k works, then it is guarenteed all k's above it works so high = k.
*   If k doesn't work, its guarenteed that no k below it will work so low = k+1. 
*/