class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {

        int rightMax = -1;

        for(int i=arr.size()-1; i>-1;i--){
            int newMax = max(rightMax,arr[i]);
            arr[i]=rightMax;
            rightMax = newMax;
            }
        
        
    return arr;
    }
};

/*
* Approach: Loop based comparison
* 1. Set rightMax variable to -1 as it is last element.
* 2. Loop through array from right to left
* 3. Set newMax as maximum between rightMax and arr[i]
* 4. Set arr[i]=newMax
* 5. Update rightMax=newMax
* 6. return arr
*/