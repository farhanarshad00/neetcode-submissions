class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq;
        int x = 0;
        int y = 0;

        for(int i=0; i<n; i++){
            pq.push(stones[i]);
        }

        while(pq.size() > 1){
            y = pq.top();
            pq.pop();
            x = pq.top();
            pq.pop();

            if(x<y){
                y = y - x;
                pq.push(y);
            }else{
                continue;
            }
        }
        if(pq.empty()){
            return 0;
        }
        return pq.top();
    }
};

/*
* What is known:
* There will always be at least one stone and a maximum of 20 stones.
* The stone weight is between 1 and 100.
* 
* Approach: Priority Queue that stores stones
* Initialize a variable n=stones.size(),a priority_queue<int> pq, and two int variables x and y.
* Loop through stones and push back stones[i] into the priority_queue. 
* After the for loop ends loop through pq using a while loop that runs till ps is empty.
* Record the pq.top() value into y.
* Pop from the top.
* Record the pq.top() value into x.
* Pop from the top.
* Check if x==y: if so continue the loop; if not set y = y-x and push into pq.
* Return pq.top().
*/