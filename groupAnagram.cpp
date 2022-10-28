class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string,vector<string>> m;
        for(auto x:strs){
            string p=x;
            sort(p.begin(),p.end());
            m[p].push_back(x);
        }
        for(auto x:m) ans.push_back(x.second);
        return ans;
    }
};