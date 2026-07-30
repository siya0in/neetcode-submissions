class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int res=0;
        unordered_set<char> hash(s.begin(),s.end());
        for(char c:hash){
            int maxf=0;int l=0;
            for(int r=0;r<s.size();r++){
                if(s[r]==c){
                    maxf++;
                }
                while((r-l+1)-maxf > k){
                    if(s[l]==c){
                        maxf--;
                    }
                    l++;
                }
                res=max(res,r-l+1); 
            }
        }
        return res;
    }
};