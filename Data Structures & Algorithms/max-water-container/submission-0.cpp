class Solution {
public:
    int maxArea(vector<int>& heights) {
        int h_size = heights.size();
        int l_ptr = 0;
        int r_ptr = h_size - 1;
        int area = (r_ptr - l_ptr) * min(heights[l_ptr], heights[r_ptr]);
        int dummy_area = 0;

        while(l_ptr != r_ptr){
            dummy_area = (r_ptr-l_ptr) * min(heights[l_ptr],heights[r_ptr]);
            area = max(dummy_area,area);

            if(heights[l_ptr] < heights[r_ptr]){
                l_ptr++;
            }else if(heights[r_ptr] < heights[l_ptr]){
                r_ptr--;
            }else{
                l_ptr++;
            }

        }

        return area;
        
    }
};

/*
* What is known:
* There will always be at least 2 entries in heights so the maximum amount in that case is the area between the two i's.
* The height of a bar will always be non-negative integer.
* Width is determined by length between indexes.
* Length is determined by the minimum height value between the two bars.
* Need to find a way to maximize length between indexes while also maximizing height of the selected bars.
* Solution needs to maintain index location so no sort functions.
* Solution should also be O(n) TC and O(1) SC so optimal solution is most likely a two pointer solution tracking index differences and elements.
* 
* Approach: Two pointers tracking maximum possible area
* Check if heights.size()==2: if so return (1 * min(heights[0],heights[1])).
* Initialize two pointers l_ptr and r_ptr at the beginning and ending index value of heights[] respectively.
* The inital values of the two pointers represent the greatest index difference in the array, 
* therefore the only way for the area to increase if for the minimum height between heights[l_ptr] and heights[r_ptr] to increase.
* Record the area between the l_ptr and r_ptr bars into a variable area.
* Loop through heights while(l_ptr != r_ptr).
* Compute the dummy_area inside the loop using (r_ptr-l_ptr) * min(heights[l_ptr],heights[r_ptr]).
* Set area = max(area,dummy_area).
* If heights[l_ptr] < heights [r_ptr]: increment l_ptr.
* Else if heights[r_ptr] < heights[l_ptr]: decrement r_ptr.
* Else increment r_ptr.
* After the end of the loop return area.
*
* Common Pitfalls:
* Choosing pair of bars based only on the value of the elements and ignoring the difference in their indexes.
*   If height[1]= 8 and height[2] = 10 then the area is (2-1) * min(8,10) = 8. 
*   While the area for height[0] = 5 and height[5] = 6 is (5-0) * min(5,6) = 25.
*   The individual heights of the first pair were greater but the area of the second pair was greater due to the distance between index values.
* 
*/