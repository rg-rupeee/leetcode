class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "", temp;
        map<char, int> ms;
        map<char, int> mt;
        
        for(auto x: s) mt[x] = 0;
        for(auto x: t) mt[x]++;
        
        // for(auto x: mt){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        
        int i=0, j=0, cnt=0;
        while(j<s.size()){
            // cout<<i<<" "<<j<<endl;
            ms[s[j]]++;
            
            if(ms[s[j]] <= mt[s[j]]) cnt++;
            
            // cout<<i<<" "<<j<<" "<<cnt<<" "<<endl;

            
            j++;
            // for(auto x: ms){
            //     cout<<x.first<<"="<<x.second<<endl;
            // }
            while(cnt==t.size() && i<=j){
                temp = s.substr(i, j-i);
                // cout<<temp<<" "<<cnt<<endl;
                if(ans == ""){
                    ans = temp;
                }
                else if(ans.size() > temp.size()){
                    ans = temp;
                }
                
                ms[s[i]]--;
                
                if(ms[s[i]] < mt[s[i]]) cnt--;
                
                i++;
            }
        }
        
        
        return ans;
    }
};