class Solution {
public:
    vector<string> ans;
    
    void backtrack(string s,int start,int end,int n){
        if(s.length()==2*n){
            ans.push_back(s);
            return;
        }
        if(start<n) backtrack(s+"(",start+1,end,n);
        if(end<start) backtrack(s+")",start,end+1,n); 
    }
    
    vector<string> generateParenthesis(int n) {
        backtrack("",0,0,n);
        return ans;
    }
};