class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> bucket(nums.size() + 1);
        unordered_map<int, int> frequencyMap;

        for (int n : nums) {
            frequencyMap[n]++;
        }

        for (pair<const int, int> entry : frequencyMap) {
            int key = entry.first;
            int frequency = entry.second;
            bucket[frequency].push_back(key);
        }

        vector<int> res;
        int counter = 0;

        for (int pos = bucket.size() - 1; pos >= 0 && counter < k; pos--) {
            for (int num : bucket[pos]) {
                if (counter == k) break;
                res.push_back(num);
                counter++;
            }
        }

        return res;
    }
};
