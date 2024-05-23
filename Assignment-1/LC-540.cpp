class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l=1, r=n-2;
        int mid=-1;
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        while(l<=r)
        {
            mid = l + (r-l)/2;
            // cout<<l<<" "<<mid<<" "<<r<<endl;
            int left=mid-l, right=r-mid;
            if((nums[mid+1]!=nums[mid] && nums[mid-1]!=nums[mid]))      
                // || mid==n-1 || mid==0)
            {
                return nums[mid];
            }
            else if((mid%2==0 && nums[mid+1]==nums[mid]) 
                ||  (mid%2==1 && nums[mid-1]==nums[mid]))
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }            
        }
        return nums[mid];
    }
};
