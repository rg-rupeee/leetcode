class Solution {
public:
    int strStr(string str, string pat) {
        int ss = str.size();
        int ps = pat.size();
        
        if(ss < ps) return -1;
        
        int i=0;
        while(i<ss-ps+1){
            int p=0, q=i;
            bool f = true;
            while(p<ps){
                if(pat[p] != str[q]){
                    f = false;
                    break;
                }
                
                p++;
                q++;
            }
            if(f) return i;
            i++;
        }
        
        return -1;
    }
};