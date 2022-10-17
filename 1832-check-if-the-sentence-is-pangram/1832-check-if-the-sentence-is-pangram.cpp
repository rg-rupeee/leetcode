class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> sc;
        for(auto x: sentence){
            sc.insert(x);
        }
        
        return sc.size() == 26;
    }
};