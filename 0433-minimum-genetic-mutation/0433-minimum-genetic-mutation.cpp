class Solution {
public:
    int solve(string start, string end, unordered_set<string> bank){
        int i, n;
        string temp;
        n = start.size();
        for(i=0; i<n; i++){
            if(start[i] != end[i]){
                temp = start;
                temp[i] = end[i];
                if(bank.find(temp) != bank.end()){
                    return 1 + solve(temp, end, bank);
                }
            }
        }
        return 0;
    }
    int solveBFS(string start, string end, unordered_set<string> bank){
        int i, n = start.size();
        string temp, st;
        
        queue<pair<string, int>> q;
        q.push({start, 1});
        int cnt;
        while(!q.empty()){
            cnt = q.front().second;
            st = q.front().first;
            q.pop();
            for(i=0; i<n; i++){
                if(st[i] != end[i]){
                    temp = st;
                    temp[i] = end[i];
                    if(bank.find(temp) != bank.end()){
                        if(temp == end) return cnt;
                        q.push({temp, cnt+1});
                    }
                }
            }
        }
        
        return -1;
    }
    
    int nextStr(string s1, string s2){
        int cnt = 0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]) cnt++;
        }
        return cnt == 1;
    }
    
    
    int solveBFS2(string start, string end, vector<string>& bank){
        int i, n = start.size();
        string st;
        unordered_set<string> vis;
        queue<pair<string, int>> q;
        q.push({start, 1});
        vis.insert(start);
        int cnt;
        while(!q.empty()){
            cnt = q.front().second;
            st = q.front().first;
            q.pop();
            
            for(auto x: bank){
                cout<<st<<" "<<x<<endl;
                cout<<nextStr(st, x)<<endl;
                if(nextStr(st, x)){
                    if(x == end) return cnt;
                    if(vis.find(x) == vis.end()){
                        q.push({x, cnt+1});
                        vis.insert(x);
                    }
                }
            }
        }
        
        return -1;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        return solveBFS2(start, end, bank);
    }
};