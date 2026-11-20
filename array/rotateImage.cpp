class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int j=0; j<n; j++){
            int start = 0;
            int end = n-1;
            while(start<end){
                swap(matrix[j][start], matrix[j][end]);
                start++;
                end--;
            }
        }
    }
};
