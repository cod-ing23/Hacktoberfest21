class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0){
            return 0;
        }
        int start = 0, ans = 0;
        string tempS = s.substr(0,1);
        for(int i = 1; i < s.length(); i++){
            if(tempS.find(s[i]) == string::npos){
                tempS += s[i];
            }
            else{
                ans = max(ans, (int)tempS.length());
                start = start + tempS.find(s[i])+1;
                tempS = s.substr(start,1); 
                i = start;
            }
        }
        ans = max(ans, (int)tempS.length());
        return ans; 
    }
};
