class Solution {
public:
    vector<vector<int>> ans;
    
    void backtrack(vector<int> v,int index,vector<int> &temp,int n){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<v.size();i++){
            temp.push_back(v[i]);
            vector<int> v1;
            for(int j=0;j<v.size();j++) if(j!=i) v1.push_back(v[j]);
            backtrack(v1,index,temp,n);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp={};
        backtrack(nums,0,temp,nums.size());
        return ans;
    }
};