class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() == 0){
            return 0;
        }
        int ptr1 = 0, ptr2 = height.size()-1;
        int maxarea = 0;
        while(ptr1 < ptr2){
            if(min(height[ptr1],height[ptr2])*(ptr2-ptr1) > maxarea){
                maxarea = min(height[ptr1],height[ptr2])*(ptr2-ptr1);
            }
            if(height[ptr1] < height[ptr2]){
                ptr1++;
            }
            else{
                ptr2--;
            }
        }
        return maxarea;
    }
};
