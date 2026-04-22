class Solution {
public:
    bool isAnagram(string s, string t) {
       if (s.length() != t.length()) return false;

        std::vector<int> count(26, 0);  // for lowercase English letters

        for (char ch : s) count[ch - 'a']++;  // count characters in s
        for (char ch : t) count[ch - 'a']--;  // subtract characters in t

        for (int c : count) {
            if (c != 0) return false;  // if any count is not zero, not anagram
        }

        return true; 
    }
};
