class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> miv;
        for(int i=0; i<nums.size(); i++){
            if(miv.find(nums[i]) != miv.end()){
                for(int j=0; j<miv[nums[i]].size(); j++){
                    if(abs(miv[nums[i]][j] - i) <= k) return true;
                }
            }
            miv[nums[i]].push_back(i);
        }
        return false;
    }
};