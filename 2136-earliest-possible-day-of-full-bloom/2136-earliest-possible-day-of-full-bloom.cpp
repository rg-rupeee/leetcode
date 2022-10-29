bool comp(pair<int, int> &p1, pair<int, int> &p2){
    return p1.first > p2.first;
}
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int i, n = plantTime.size();
        vector<pair<int, int>> vp(n);
        for(i=0; i<n; i++){
            vp[i] = {growTime[i], plantTime[i]};
        }
        sort(vp.begin(), vp.end(), comp);
        
        int ans = 0;
        int time = 0;
        int blossom;
        for(i=0; i<n; i++){
            time = time + vp[i].second;
            blossom = time + vp[i].first;
            ans = max(ans, blossom);
        }
        
        return ans;
    }
};