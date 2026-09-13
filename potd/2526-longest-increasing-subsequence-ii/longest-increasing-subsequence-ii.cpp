class SegTree {
vector<int> tree;
public :
    SegTree(int n) {
        tree.resize(n * 4, 0);
    }

    int query(int node, int ql, int qr, int l, int r) {
        if(ql <= l && qr >= r) return tree[node];
        if(r < ql || l > qr) return 0;
        int mid = (l + r) >> 1;
        int lq = query(node * 2, ql, qr, l, mid); 
        int rq = query(node * 2 + 1, ql, qr, mid + 1, r);
        return max(lq, rq); 
    }

    void update(int node, int l, int r, int x, int size) {
        if(x < l || x > r) return ;
        if(l == r) {
            tree[node] = size;
            return ;
        }
        int mid = (l + r) >> 1;
        update(node * 2, l, mid, x, size); 
        update(node * 2 + 1, mid + 1, r, x, size);
        tree[node] = max(tree[node*2], tree[node*2+1]); 
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        SegTree segTree(maxi + 1);
        int ans = 0;
        for(auto it : nums) {
            int ql = max(0, it - k);
            int qr = max(0, it - 1);
            int size = segTree.query(1, ql, qr, 0, maxi);
            ans = max(ans, 1 + size);
            segTree.update(1, 0, maxi, it, size + 1);
        }
        return ans;
    }
};