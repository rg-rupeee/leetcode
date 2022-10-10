class Solution {
public:
    string breakPalindrome(string p) {
        if(p.size() == 1) return "";
        
        int n = p.size();
        for(int i=0; i<n; i++){
            if(n%2 == 0){
                if(p[i] != 'a'){
                    p[i] = 'a';
                    return p;
                }
            }
            else{
                if(i != n/2 && p[i] != 'a'){
                    p[i] = 'a';
                    return p;
                }
            }    
        }
        
        p[n-1] = 'b';
        return p;
    }
};