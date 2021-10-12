// solution to two sum 
// language cpp

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<pair<int, int>> vals;
            for(int i = 0; i < nums.size(); i++) {
                vals.push_back({nums[i], i});
            }
            sort(vals.begin(), vals.end());
            int ptr1 = 0, ptr2 = nums.size() - 1;
            while(ptr1 < ptr2) {
                if(vals[ptr1].first + vals[ptr2].first == target) {
                    return {vals[ptr1].second, vals[ptr2].second};
                }
                else if(vals[ptr1].first + vals[ptr2].first < target) ptr1++;
                else ptr2--;
            }
            return {-1, -1};
        }
};
