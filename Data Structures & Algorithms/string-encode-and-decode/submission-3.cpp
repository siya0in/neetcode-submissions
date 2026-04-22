class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& s : strs) {
            encoded += to_string(s.length()) + "#" + s;
        }
        return encoded;

    }

    vector<string> decode(string s) {
        vector<string> result;
    int i = 0;

    while (i < s.size()) {
        // Step 1: Read the full length (could be multi-digit)
        string lenStr = "";
        while (s[i] != '#') {
            lenStr += s[i];
            i++;
        }

        int len = stoi(lenStr);  // Convert string length to integer
        i++;  // Skip the '#'

        // Step 2: Extract the word of given length
        string word = s.substr(i, len);
        result.push_back(word);

        i += len;  // Move index to next length
    }

    return result;
    }
    
};
