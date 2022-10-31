class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n, m, i, j, p;
        n = matrix.size();
        m = matrix[0].size();
        int val;
        for(p=0; p<n; p++){
            i = p;
            j = 0;
            
            val = matrix[i][j];
            while(true){
                if(i>=n || j>=m) break;
                
                
                if(matrix[i][j] != val) return false;
                
                i++;
                j++;
            }
        }
        
        for(p=1; p<m; p++){
            i = 0;
            j = p;
            
            val = matrix[i][j];
            while(true){
                if(i>=n || j>=m) break;
                
                
                if(matrix[i][j] != val) return false;
                
                i++;
                j++;
            }
        }
        
        return true;
    }
};