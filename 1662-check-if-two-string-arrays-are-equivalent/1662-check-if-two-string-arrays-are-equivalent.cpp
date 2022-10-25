class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int ind1, ind2, i1, i2;
        ind1=0;
        ind2=0;
        i1=0;
        i2=0;
        
        while(true){
            if(ind1 == word1.size() && ind2 == word2.size()) break;
            
            if(ind1 == word1.size() || ind2 == word2.size()) return false;
            
            if(word1[ind1][i1] != word2[ind2][i2]) return false;
            
            i1++;
            i2++;
            
            if(i1 == word1[ind1].size()) {
                ind1++;
                i1 = 0;
            }
            
            if(i2 == word2[ind2].size()){
                ind2++;
                i2 = 0;
            }
            
        }
        
        
        return true;
    }
};