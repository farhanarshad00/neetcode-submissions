class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int curr_count=1;
        int max_count=1;

        if(nums.empty()){
            return 0;
        }
        
        vector<int> dummy_vec(nums.size());

        for(int i=0; i<nums.size(); i++){
            dummy_vec[i]=nums[i];
        }
        
        sort(dummy_vec.begin(),dummy_vec.end());
        for(int i=0; i<nums.size(); i++){
            cout<<dummy_vec[i]<<endl;
        }
        /* Received heap-buffer-overflow error. I believe its because code is trying to find j+1 value while on j
        for(int j=0; j<dummy_vec.size();j++){
            if(dummy_vec[j+1] == dummy_vec[j]+1){
                    count++;
                }else{
                    count=0;
                }
            }
        */
        // Revised loop going backwards
        // Code ran without error but output 1758182784 instead of expected 4
        for(int j=dummy_vec.size()-1; j>0;j--){
            if(dummy_vec[j-1] == dummy_vec[j]-1){
                curr_count++;
            }else if(dummy_vec[j-1]==dummy_vec[j]){
                continue;

            }else{
                if(curr_count>=max_count){
                    max_count=curr_count;
                    curr_count=1;
                }else{
                    curr_count=1;
                }
            }

            if(curr_count>max_count){
                max_count=curr_count;
            }
        }

        return max_count;

        
    }
};

/*
* Approach: Sort array and return sequence
* Create an int count that tracks how many consecutive integers there are in nums
* Create a dummy vector=nums to be sorted
* Loop through nums and set dummy_vec[i]=nums[i]
* Sort the dummy vector
* Loop through the dummy vector and check if dummy_vec[i+1]==dummy_vec[i]+1: if so increment count; if not set count to 0
* Return count
*/
