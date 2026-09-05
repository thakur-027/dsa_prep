class Solution {
public:
bool binarySearch(vector<vector<int>>& matrix, int target, int m, int n) {
    int low = 0;
    int high = m * n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int row = mid / n;
        int col = mid % n;

        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
        int n = matrix[0].size();

        return binarySearch(matrix, target, m, n);
}
};
