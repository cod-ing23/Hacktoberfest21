class Solution {
public:
    void backtrack(map<vector<int>, int>& ans, vector<int> v, int idx, int target, vector<int>& vals){
        if(target == 0){
            ans[v]++;
            return;
        }
        for(int i = idx; i < vals.size(); i++){
            if(vals[i] <= target){
                v.push_back(vals[i]);
                backtrack(ans, v, i+1, target-vals[i], vals);
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<vector<int>, int> m;
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        backtrack(m, v, 0, target, candidates);
        for(auto i : m) ans.push_back(i.first);
        return ans;
    }
};

