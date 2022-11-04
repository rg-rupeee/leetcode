class Solution {
public:
    bool isVovel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U') return true;
        
        return false;
    }
    string reverseVowels(string s) {
        int left, right;
        left = 0;
        right = s.size()-1;
        
        while(left <= right){
            while(left<=right && !isVovel(s[left])) {
                left++;
            }
            
            while(left<=right && !isVovel(s[right])){
                right--;
            }
            
            if(left<=right && isVovel(s[left]) && isVovel(s[right])){
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
            }
            
            left++;
            right--;
        }
        
        return s;
    }
};