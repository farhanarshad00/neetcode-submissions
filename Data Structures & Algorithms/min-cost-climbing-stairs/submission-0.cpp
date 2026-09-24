class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> minCost(2);
        int i = 2;
        int tmp;

        while(i<=n){
            tmp = minCost[1];
            minCost[1] = min(tmp+cost[i-1],minCost[0]+cost[i-2]);
            minCost[0] = tmp;
            i++;
        }
        return minCost[1];

    }
};

/*
* What is known:
* There will always be a minimum of 2 indices in cost.
* The value per indice or cost[i] will always be nonnegative.
* Can start at index 0 or 1.
* After paying the cost[0] or cost[1] you can move to i=1,i=2 OR i=2,i=3 respectively.
* The absolute minimum comes from the case where cost.length()=2 and cost[0]=j,cost[1]=k.
* If (j<k): Start at index=0, move (0+2=2) over, then the minCost=j.
* Else: Start at index=1, move (1+1=2) over, then the minCost=k.
* The number of steps taken has to be <= to cost.length().
* Given that the start point can be either 0 or 1 how can we reduce n?
*/