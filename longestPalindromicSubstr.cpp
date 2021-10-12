class Solution {
public:
    string expand(string maxi, string s, int st, int en) {
        int n = s.length();
        string res = "";
        while(st >= 0 && en < n && s[st] == s[en]) {
            st--; en++;
        }
        res = s.substr(st + 1, en - st - 1);
        if((int)res.length() > (int)maxi.length()) return res;
        return maxi;
    }
    
    string longestPalindrome(string s) {
        int n = s.length(); if(n == 0) return "";
        string maxi = string(1, s[0]);
        for(int i = 0; i < n; i++) {
            if(i - 1 >= 0 && i + 1 < n) maxi = expand(maxi, s, i - 1, i + 1);
            if(i + 1 < n) maxi = expand(maxi, s, i, i + 1);
        }
        return maxi;
    }
};
