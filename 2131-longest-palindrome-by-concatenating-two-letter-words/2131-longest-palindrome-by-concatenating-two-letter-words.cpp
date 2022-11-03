class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> msi;
        for(auto x: words) msi[x]++;
        
        for(auto p: msi) cout<<p.first<<" "<<p.second<<endl;
        
        int ans = 0;
        string r;
        bool flag = false;
        
        for(auto s: words){
           r = "";
            r += s[1];
            r += s[0];
            
            if(msi[s] > 0) {
                msi[s]--;
                if(msi[r] && msi[r]>0){
                    ans+=4;
                    msi[r]--;
                }
                else{
                    if(r == s){
                        flag = true;
                    }
                }
            }
        }
        
        if(flag) ans += 2;
        
        return ans;
    }
};