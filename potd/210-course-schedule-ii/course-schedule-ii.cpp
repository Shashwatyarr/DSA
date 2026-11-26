class Solution {
public:
    bool dfs(vector<vector<int>>& adj,stack<int>& st,int i,vector<int>& vis){
        if(vis[i]==1) return 1;
        if(vis[i]==2) return 0;
        vis[i]=1;
        for(auto it:adj[i]){
            if(dfs(adj,st,it,vis)) return 1;
        }
        vis[i]=2;
        st.push(i);
        return 0;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int n=adj.size();
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n+1,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(adj,st,i,vis)) return {};
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};