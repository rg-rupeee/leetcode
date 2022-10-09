class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mi;
        int i, n=nums.size();
        for(i=0; i<n; i++){
            mi[nums[i]] = i;
        }
        vector<int> ans;
        for(i=0; i<n; i++){
            int t = target - nums[i];
            if(mi.find(t) != mi.end() && mi[t] != i){
                ans.push_back(mi[t]);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};