class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string> v(numRows,"");
        int row=0,d=1;
        // bool flag=true;
        for(int i=0;i<s.length();i++){
            if(row==numRows){
                d=-1;
                row+=d;
                row+=d;
            }
            if(row==-1){
                d=1;
                row+=d;
                row+=d;
            }
            v[row]+=s[i];
            row+=d;
        }
        string ans="";
        for(auto x:v) ans+=x;
        return ans;
    }
};