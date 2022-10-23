class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup = -1, mis = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[abs(nums[i]) - 1] < 0){
                dup = abs(nums[i]);
            }
            else{
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0) mis = i+1;
        }
        
        vector<int> ans = {dup, mis};
        
        return ans;
    }
};