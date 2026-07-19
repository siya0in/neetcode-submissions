class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        if (arr.size() < 3) return {};

        // Sort the elements
        sort(arr.begin(), arr.end());
        set<vector<int>> result;  // set auto-removes duplicate triplets

        // Now fix the first element and find the other two elements
        for (int i = 0; i < (int)arr.size(); i++) {

            // Find other two elements using Two-Pointer approach
            int left = i + 1;
            int right = arr.size() - 1;

            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];

                if (sum == 0) {
                    // Add the triplet, and move to find other triplets
                    result.insert({arr[i], arr[left], arr[right]});
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return vector<vector<int>>(result.begin(), result.end());
    }
};