class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:edges) adj[it[0]].push_back({it[1],it[2]});
        vector<vector<int>> dist(n,vector<int>(k+1,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        dist[0][1]=0;
        pq.push({0,{0,1}});
        while(!pq.empty()){
            auto [a,x]=pq.top();
            auto [b,c]=x;
            pq.pop();
            if(a!=dist[b][c]) continue;
            if(b==n-1) return a;
            for(auto [d,e]:adj[b]){
                int cnt=1;
                if(labels[b]==labels[d]) cnt=c+1;
                if(cnt>k) continue;
                if(a+e<dist[d][cnt]){
                    dist[d][cnt]=a+e;
                    pq.push({a+e,{d,cnt}});
                }
            }
        }
        return -1;
    }
};