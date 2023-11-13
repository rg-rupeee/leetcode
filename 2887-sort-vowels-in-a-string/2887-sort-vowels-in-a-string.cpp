class Solution {
public:
    string vovels = "aeiouAEIOU";
    string sortVowels(string s) {
        vector<int> varr;
        for(auto x: s){
            if(vovels.find(x) != string::npos){
                varr.push_back(x);
            }
        }
        sort(varr.begin(), varr.end());
        int i, j;
        string ans = "";
        i=0; j=0;
        while(i < s.size()){
            if(vovels.find(s[i]) != string::npos){
                ans += varr[j];
                j++;
            }
            else{
                ans += s[i];
            }
            i++;
        }
        return ans;
    }
};