class Solution {
public:
     int nextStr(string s1, string s2){
        int cnt = 0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]) cnt++;
        }
        return cnt == 1;
    }
    
    int solveBFS(string start, string end, set<string>& bank){
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
            
            string temp;
            for(int i=0; i<st.size(); i++){
                for(char ch = 'a'; ch <= 'z'; ch++){
                    temp = st;
                    temp[i] = ch;
                    if(bank.find(temp) != bank.end()){
                        if(temp == end) return cnt+1;
                        if(vis.find(temp) == vis.end()){
                            q.push({temp, cnt+1});
                            vis.insert(temp);
                        }
                    }
                }
            }
        }
        
        return 0;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> wordSet;
        for(auto x: wordList) wordSet.insert(x);
        return solveBFS(beginWord, endWord, wordSet);
    }
};