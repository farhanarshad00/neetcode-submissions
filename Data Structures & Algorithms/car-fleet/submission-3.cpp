class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>> cars(n);
        double time;
        stack<double> fleet_time;
        int diffFleets=1;

        for(int i=0; i<n;i++){
            cars[i]={position[i],speed[i]};
        }
        sort(cars.rbegin(),cars.rend());

        for(int j=0; j<n; j++){
            time=static_cast<double>((target-cars[j].first))/cars[j].second;
            if(fleet_time.empty()){
                fleet_time.push(time);
            }else if (time>fleet_time.top()){
                fleet_time.push(time);
                diffFleets++;
            }
        }
        return diffFleets;
    }
};
/*
* What is known:
* The end goal is "target-position[i]" for every ith car
* Each car is a fleet in and of itself so there will always be an upper bound of n car fleets
* 
* Approach create a vector of pairs of position[i] and speed[i], 
* a stack to track the fleet, the time it takes for a car to reach the end goal as double time, 
* and the different amount of fleets as an int.
* Loop through position and speed to populate the vector of pairs.
* Afterward sort the vector of pairs in descending order to get the 
* position closest to the goal as the first element.
* Loop through the vector pair and calculate the time from reaching the end per car.
* Check if the stack is empty: if so push the current time onto the stack;
*   Else If the stack is populated and the time is > than the fleet time:
*       it means that this car will not meet the current fleet and another fleet will be created.
*       push the new time onto the stack and increment the amount of different fleets. 
* After the loop ends return the different amount of fleets 
*/