class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circles=0;
        int squares=0;
        for(int i=0; i<students.size();i++){
            if(students[i]==0){
                circles++;
            }else if(students[i]==1){
                squares++;
            }
        }
        for(int j=0;j<sandwiches.size();j++){
            if(sandwiches[j]==0 && circles == 0){
                return circles+squares;
            }else if(sandwiches[j]==1 && squares == 0){
                return circles+squares;
            }else if(sandwiches[j]==0 && circles != 0){
                circles--;
            }else if(sandwiches[j]==1 && squares != 0){
                squares--;
            }
        }
        int students_left=circles+squares;
        
    return students_left;   
    }
};

/*
* Approach: For loop comparison with removal if match
* 1. Create a for loop with int i=0 that cycles through the elements of students
* 2. If students[i]==0, increment circles
* 3. Else if students[i]==1, increment squares
* 4. Loop through sandwiches and decrement from circles or squares if sandwiches[i]==0 or 1 respectively
* 5. After loop sum circles and squares
* 6. Set students_left=sum and return
*/