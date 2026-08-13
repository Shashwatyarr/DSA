class SegTree {
// prefix_length maxi_val suffix_length prefix_char suffix_char
vector<array<int, 5>> tree;
public :
    SegTree(int n) {
        tree.resize(n * 4);
    }

    array<int, 5> merge(array<int, 5>& a, int lena, array<int, 5>& b, int lenb) {
        int maxi = max(a[1], b[1]);
        int prefix = a[0], suffix = b[2];
        if(a[4] == b[3]) {
            maxi = max(maxi, a[2] + b[0]);
            if(lena == a[0]) prefix += b[0];
            if(lenb == b[0]) suffix += a[2];
        }
        return {prefix, maxi, suffix, a[3], b[4]};
    }

    void build(int node, int l, int r, string& s) {
        if(l == r) {
            tree[node][0] = tree[node][1] = tree[node][2] = 1;
            tree[node][3] = tree[node][4] = s[l];
            return ;
        }
        int mid = (l + r) >> 1;
        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);
        tree[node] = merge(tree[node*2], mid - l + 1, tree[node*2+1], r - mid);
    }

    void update(int node, int l, int r, int index, char c) {
        if(index < l || index > r) return ;
        if(l == r) { tree[node][3] = tree[node][4] = c; return ;}
        int mid = (l + r) >> 1;
        update(node * 2, l, mid, index, c);
        update(node * 2 + 1, mid + 1, r, index, c);
        tree[node] = merge(tree[node*2], mid - l + 1, tree[node*2+1], r - mid);
    }

    int find() {
        return tree[1][1];
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size(), q = queryCharacters.size();
        SegTree tree(n); vector<int> ans(q);
        tree.build(1, 0, n - 1, s);
        for(int i = 0; i < q; i++) {
            tree.update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree.find();
        }
        return ans;
    }
};