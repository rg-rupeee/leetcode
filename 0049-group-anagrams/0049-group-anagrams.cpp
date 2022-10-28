class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<map<char, int>, vector<string>> mmv;
        for(auto x: strs){
            map<char, int> mci;
            for(auto y: x){
                mci[y]++;
            }
            mmv[mci].push_back(x);
        }
        
        for(auto p: mmv){
            ans.push_back(p.second);
        }
        
        return ans;
    }
};