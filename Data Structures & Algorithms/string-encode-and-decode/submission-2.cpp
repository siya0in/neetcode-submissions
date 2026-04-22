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

        while (i < s.length()) {
            // Find the position of '#'
            int j = i;
            while (s[j] != '#') {
                j++;
            }

            // Get the length of the word
            int len = stoi(s.substr(i, j - i));

            // Get the word of that length after '#'
            string word = s.substr(j + 1, len);
            result.push_back(word);

            // Move to the next encoded string
            i = j + 1 + len;
        }

        return result;
    }
    
};
