class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int st=-1,en=-1;
        int n=nums.size();
        int j=0,k=n-1;
        while(j<=k){
            int mid=j+(k-j)/2;
            if(nums[mid]==target){
                // cout<<"here with mid "<<mid<<endl;
                st=mid,en=mid;
                j=mid;k=mid;
                while(j>=0){
                    if(nums[j]==target){
                        st=min(st,j);
                        j--;
                    }
                    else break;
                }
                while(k<n){
                    if(nums[k]==target){
                        en=max(en,k);
                        k++;
                    }
                    else break;
                }
                break;
                
            }
            else if(nums[mid]<target) j=mid+1;
            else k=mid-1;
        }
        return {st,en};
    }
};