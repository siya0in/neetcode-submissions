class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;

    TimeMap() {
        
    }

    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) return "";

        vector<pair<int, string>>& values = store[key];
        int low = 0, high = values.size() - 1;
        string res = "";

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (values[mid].first <= timestamp) {
                res = values[mid].second;   // this timestamp works, remember it
                low = mid + 1;              // try to find something even more recent
            } else {
                high = mid - 1;             // this timestamp is too far in the future
            }
        }

        return res;
    }
};