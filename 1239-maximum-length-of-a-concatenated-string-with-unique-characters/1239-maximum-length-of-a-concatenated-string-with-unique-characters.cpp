class Solution {
public:
    int solve(vector<string> &arr, int ind, int mask){
        if(ind == arr.size()){
            return 0;
        }
        
        int rem = solve(arr, ind+1, mask);
        
        bool flag = true;
        
        for(int i=0; i<arr[ind].size(); i++){
            int k = arr[ind][i]-'a';
            // check if the kth bith is set
            if((mask & (1<<k))){
                flag = false;
                break;
            }
            
            // set kth bit
            mask = mask | (1<<k);
        }
               
        if(!flag) return rem;
               
        int cur = arr[ind].size() + solve(arr, ind+1, mask);
               
        return max(rem, cur);
    }
    int maxLength(vector<string>& arr) {
        // generate all subsets and check them
        return solve(arr, 0, 0);
    }
};