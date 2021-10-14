class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int ptr1=0,ptr2=height.size()-1;
        while(ptr1<ptr2){
            ans=max(ans,min(height[ptr1],height[ptr2])*(ptr2-ptr1));
            if(height[ptr1]<height[ptr2]) ptr1++;
            else ptr2--;
        }
        return ans;
    }
};