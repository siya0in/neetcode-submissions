class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length()!=t.length())
            return false;

        vector<int> num(26,0);

        for(int i=0; i<s.length();i++)
        {
          num[s[i]-'a']++;
          num[t[i]-'a']--;
        }
        for(int val: num){
          if(val!=0)
            return false;
        }
        return true;
    }
};
