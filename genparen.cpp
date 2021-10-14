class Solution {
public
    vectorstring ans;
    
    void backtrack(string s,int start,int end,int n){
        if(s.length()==2n){
            ans.push_back(s);
            return;
        }
        if(startn) backtrack(s+(,start+1,end,n);
        if(endstart) backtrack(s+),start,end+1,n); 
    }
    
    vectorstring generateParenthesis(int n) {
        backtrack(,0,0,n);
        return ans;
    }
};
