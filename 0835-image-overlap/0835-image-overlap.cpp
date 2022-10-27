class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int i, j, n;
        n = img1.size();
        vector<pair<int, int>> v1;
        vector<pair<int, int>> v2;
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(img1[i][j]) v1.push_back({i, j});
                if(img2[i][j]) v2.push_back({i, j});
            }
        }
        
        int xdis, ydis, ans=0;
        map<pair<int, int>, int> mp;
        for(auto x: v1){
            for(auto y: v2){
                xdis = x.first - y.first;
                ydis = x.second - y.second;
                
                mp[{xdis, ydis}]++;
                ans = max(ans, mp[{xdis, ydis}]);
            }
        }
        return ans;
    }
};