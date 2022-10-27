class Solution {
public:
    int shiftANDcount(vector<vector<int>> img1, vector<vector<int>> img2, int xShift, int yShift){
        int i, j, n, cnt;
        n = img1.size();
        cnt = 0;
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(i+xShift<n && j+yShift<n && i+xShift>=0 && j+yShift>=0){
                    if(img1[i+xShift][j+yShift] && img2[i][j]) cnt++;
                }
            }
        }
        
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int i, j, n, ans;
        n = img1.size();
        ans = 0;
        for(i=-n; i<=n; i++){
            for(j=-n; j<=n; j++){
                ans = max(ans, shiftANDcount(img1, img2, i, j));
                // ans = max(ans, shiftANDcount(img1, img2, i*-1, j*-1));
            }
        }
        return ans;
    }
};