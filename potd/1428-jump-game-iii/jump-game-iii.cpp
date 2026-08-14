class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int> vis(n,0);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int v=q.front();
            q.pop();
            if(arr[v]==0) return 1;
            if( v+arr[v]<arr.size() && !vis[arr[v]+v] ){ 
                q.push(arr[v]+v);
                vis[arr[v]+v]=1;
            }
            if(v-arr[v]>=0 && !vis[v-arr[v]]) {
                q.push(v-arr[v]);
                vis[v-arr[v]]=1;
            }
        }
        return 0;
    }
};