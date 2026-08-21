class Solution {
int n;
unordered_map<int, vector<long long>> mp;
void subset(int index, long long lcm, int taken, vector<int>& coins) {
    if(index >= n) {
        if(taken) mp[taken].push_back(lcm);
        return ;
    }
    subset(index + 1, lcm, taken, coins);
    subset(index + 1, std::lcm(lcm, 1LL * coins[index]), taken + 1, coins);
}
long long principleOfInclusionExclusion(long long num) {
    long long mult = 1, factors = 0;
    for(int i = 1; i <= n; i++) {
        for(auto it : mp[i]) {
            factors += mult * num / it;
        }
        mult *= -1;
    }
    return factors;
}
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        n = coins.size();
        subset(0, 1, 0, coins);
        long long l = 1, r = 1e12;
        while(l <= r) {
            long long mid = (l + r) >> 1;
            long long k_ = principleOfInclusionExclusion(mid);
            if(k_ >= k) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};