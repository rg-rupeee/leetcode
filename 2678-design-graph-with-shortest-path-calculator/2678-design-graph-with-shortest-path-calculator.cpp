class Graph {
public:
    int nodes;
    vector<vector<pair<int, int>>> graph;
    map<int, map<int, int>> cache;
    Graph(int n, vector<vector<int>>& edges) {
        nodes = n;
        graph.resize(n, vector<pair<int,int>>());
        for(auto edge: edges){
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1], edge[2]});
        cache.clear();
    }

    int shortestPath(int node1, int node2) {
        if(cache.find(node1) != cache.end() && cache[node1].find(node2) != cache[node1].end()){
            return cache[node1][node2];
        }
        int ans = -1;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> nodeCost(nodes, INT_MAX);
        nodeCost[node1] = 0;
        pq.push({0, node1});

        int curCost, curNode, neighNode, cost, newCost;
        while(!pq.empty()){
            curCost = pq.top()[0];
            curNode = pq.top()[1];
            pq.pop();

            if(curCost > nodeCost[curNode]) continue;

            if(curNode == node2){
                ans = curCost;
                break;
            }

            for(auto &neigh: graph[curNode]){
                neighNode = neigh.first;
                cost = neigh.second;
                newCost = curCost + cost;

                if(newCost < nodeCost[neighNode]){
                    nodeCost[neighNode] = newCost;
                    pq.push({newCost, neighNode});
                }
            }
        }
        return cache[node1][node2] = ans;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */