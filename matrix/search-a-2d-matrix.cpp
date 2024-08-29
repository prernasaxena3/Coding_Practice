//search-a-2d-matrix

/*You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n =  matrix.size();
        int m = matrix[0].size();
        int top = 0,right = m-1;
        while(top<n && right>=0){
            // for(int i = top;i<=right;i++){
            //     if(matrix[top][i] == target){
            //         return true;
            //     }
            // }
            // top++;

            if(matrix[top][right] == target){
                return true;
            }else if(matrix[top][right]>target){
                right--;
            }else{
                top++;
            }
        }
        return false;
    }
};
