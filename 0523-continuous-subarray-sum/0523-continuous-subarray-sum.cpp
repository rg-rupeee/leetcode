class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> mii;
        int sum = 0;
        int mod;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            mod = sum % k;
            if(mod == 0 && i > 0){
                return true;
            }
            
            if(mii.find(mod) != mii.end()){
                if(i - mii[mod] > 1) return true;
            }
            else{
                mii[mod] = i;
            }
        }
        return false;
    }
};