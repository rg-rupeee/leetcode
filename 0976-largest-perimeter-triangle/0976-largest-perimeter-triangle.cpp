class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // valid if sum of two sides greater than third
        sort(nums.begin(), nums.end());
        int n, i, j, k;
        n = nums.size();
        i=n-1;
        j=n-2;
        k=n-3;
        
        while(k >= 0){
            if(nums[k]+nums[j] > nums[i]) return nums[i] + nums[j] + nums[k];
            i--;
            j--;
            k--;
        }
        
        return 0;
    }
};