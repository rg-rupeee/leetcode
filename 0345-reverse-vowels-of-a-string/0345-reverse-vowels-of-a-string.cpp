class Solution {
public:
    bool isVovel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U') return true;
        
        return false;
    }
    string reverseVowels(string s) {
        stack<char> v;
        int i, n=s.size();
        for(i=0; i<n; i++){
            if(isVovel(s[i])) v.push(s[i]);
        }
        for(i=0; i<n; i++){
            if(isVovel(s[i])) {
                s[i] = v.top();
                v.pop();
            }
        }
        return s;
    }
};