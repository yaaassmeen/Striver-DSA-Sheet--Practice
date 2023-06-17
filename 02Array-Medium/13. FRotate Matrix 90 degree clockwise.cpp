class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //Transposing the matrix
        int n = matrix.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //reversing every row in the matrix
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
