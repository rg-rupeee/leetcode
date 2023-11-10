class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjPairs) {
        map<int, vector<int>> adjMap;
        int i, n;
        n = adjPairs.size();
        for(i=0; i<n; i++){
            if(adjMap.find(adjPairs[i][0]) == adjMap.end()){
                vector<int> t1;
                adjMap[adjPairs[i][0]] = t1;
            }
            if(adjMap.find(adjPairs[i][1]) == adjMap.end()){
                vector<int> t2;
                adjMap[adjPairs[i][1]] = t2;
            }

            adjMap[adjPairs[i][0]].push_back(adjPairs[i][1]);
            adjMap[adjPairs[i][1]].push_back(adjPairs[i][0]);
        }
        // for(auto mvi: adjMap){
        //     cout<<mvi.first<<endl;
        //     for(auto x: mvi.second){
        //         cout<<x<<" ";
        //     }
        //     cout<<endl;
        // }
        int firstEl;
        for(i=0; i<n; i++){
            if(adjMap[adjPairs[i][0]].size() == 1){
                firstEl = adjPairs[i][0];
                break;
            }
            if(adjMap[adjPairs[i][1]].size() == 1){
                firstEl = adjPairs[i][1];
                break;
            }
        }
        vector<int> ans(1, firstEl);
        set<int> visited;
        visited.insert(firstEl);
        int cur, f;
        while(true){
            cur = ans.back();
            f = 1;

            if(visited.find(adjMap[cur][0]) == visited.end()){
                f = 0;
                visited.insert(adjMap[cur][0]);
                ans.push_back(adjMap[cur][0]);
            }
            else if(adjMap[cur].size() > 1 && visited.find(adjMap[cur][1]) == visited.end()){
                f = 0;
                visited.insert(adjMap[cur][1]);
                ans.push_back(adjMap[cur][1]);
            }

            if(f) break;
        }
        return ans;
    }
};