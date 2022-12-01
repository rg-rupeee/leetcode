class Solution {
public:
    int isVovel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U') return 1;
        return 0;
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        int mid = n/2;
        int i, cnt=0;
        for(i=0; i<mid; i++){
            cnt += isVovel(s[i]);
        }
        for(i=mid; i<n; i++){
            cnt -= isVovel(s[i]);
        }
        
        return (cnt == 0); 
    }
};