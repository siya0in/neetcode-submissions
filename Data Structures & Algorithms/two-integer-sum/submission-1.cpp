class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < nums.size(); ++i) {
            arr.push_back({nums[i], i});
        }

        // Step 2: Sort based on the values
        sort(arr.begin(), arr.end());

        // Step 3: Two-pointer approach
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = arr[left].first + arr[right].first;

            if (sum == target) {
                int i = arr[left].second;
                int j = arr[right].second;
                return {min(i, j), max(i, j)}; // return in increasing order
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {};
    }
};
