class Solution {
public:

    struct Node {
        int l, r, w, idx;
    };

    struct State {
        long long score = 0;
        vector<int> ids;
    };

    vector<Node> a;

    State better(const State& A, const State& B) {

        if(A.score != B.score)
            return (A.score > B.score ? A : B);

        if(lexicographical_compare(
                A.ids.begin(), A.ids.end(),
                B.ids.begin(), B.ids.end()))
            return A;

        return B;
    }

    int getPrev(int i) {

        int lo = 0, hi = i - 1;
        int ans = -1;

        while(lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            if(a[mid].r < a[i].l) {
                ans = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }

        return ans;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        a.resize(n);

        for(int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        sort(a.begin(), a.end(),
             [](const Node& x, const Node& y) {
                 return x.r < y.r;
             });

        vector<int> prev(n);

        for(int i = 0; i < n; i++)
            prev[i] = getPrev(i);

        vector<vector<State>> dp(
            n + 1,
            vector<State>(5)
        );

        for(int i = 1; i <= n; i++) {

            for(int k = 1; k <= 4; k++) {

                State skip = dp[i-1][k];

                int p = prev[i-1];

                State take = dp[p+1][k-1];

                take.score += a[i-1].w;

                take.ids.push_back(a[i-1].idx);

                sort(take.ids.begin(), take.ids.end());

                dp[i][k] = better(skip, take);
            }
        }

        return dp[n][4].ids;
    }
};