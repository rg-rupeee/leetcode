struct Compare{
    bool operator() (pair<string, int> p1, pair<string, int> p2){
        if(p1.second != p2.second) return p1.second < p2.second;
        return p1.first > p2.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> msi;
        for(auto x: words){
            msi[x]++;
        }
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;
        for(auto x: msi){
            pq.push(make_pair(x.first, x.second));
        }
        
        vector<string> ans;
        
        while(k--){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        return ans;
    }
};