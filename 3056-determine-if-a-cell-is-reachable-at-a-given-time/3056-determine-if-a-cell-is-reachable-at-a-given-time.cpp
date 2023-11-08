class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x = abs(sx-fx);
        int y = abs(sy-fy);

        if(x==0 && y==0){
            return t != 1 ? true : false;
        }

        int d = min(x, y);

        cout<<x<<" "<<y<<" "<<d<<endl;

        if(t >= x + y - d) return true;


        return false;
    }
};