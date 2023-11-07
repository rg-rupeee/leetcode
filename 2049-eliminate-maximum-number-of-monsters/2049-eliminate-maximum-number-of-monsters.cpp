class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> time(n);
        int i;
        for(i=0; i<n; i++){
            time[i] = ceil((double)dist[i] / speed[i]);
        }
        sort(time.begin(), time.end());
        int ans = 0;
        for(i=0; i<n; i++){
            // cout<<time[i]<<endl;
            // cout<<ans<<" "<<time[i]<<endl;
            if(time[i] > ans){
                ans++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};