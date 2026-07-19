class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = n * m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;   // also safer against overflow than (low+high)/2
            int row = mid / m;
            int column = mid % m;
            if (mat[row][column] < target) {
                low = mid + 1;
            }
            else if (mat[row][column] > target) {   // fixed: > not 
                high = mid - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};