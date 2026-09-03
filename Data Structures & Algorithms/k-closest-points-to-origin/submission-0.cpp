class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<int,vector<vector<int>>> dist_map;
        vector<vector<int>> ans_vec;
        int collected = 0;

        for(auto& point:points){
            int distance = (point[0]*point[0])+(point[1]*point[1]);
            dist_map[distance].push_back(point);
        }
        for(auto& it : dist_map){
            int pts_needed = k - collected;
            if(it.second.size()<=(pts_needed)){
                for(int i=0; i<it.second.size();i++){
                    ans_vec.push_back(it.second[i]);
                }
                collected = collected + it.second.size();
                }else{
                    for(int j=0; j<pts_needed; j++){
                        ans_vec.push_back(it.second[j]);
                    }
                }
        }
        return ans_vec;
        }
};
/*
If k=5, return the 5 closest points to the origins.
Calculate the Euclidean Distance between the points and (0,0)
for all the points in the array points.
Record the distances as keys in an map of vectors<vectors<int>> with the values being the vectors of points.
Return first k points 

*/