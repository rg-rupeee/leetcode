int MOD = 1000000007;
class Solution {
public:
    int countHomogenous(string s) {
        char ch;
        map<char, int> freq;
        long long i, n, cnt, ans, temp;
        n = s.size();
        ans = 0;
        i = 0;
        while(i < n){
            cnt = 0;
            ch = s[i];
            while(i < n && s[i] == ch){
                i++;
                cnt++;
            }

            temp = ((cnt * (cnt + 1)) / 2) % MOD;

            ans = (ans + temp) % MOD;
        }

        return ans;
    }
};