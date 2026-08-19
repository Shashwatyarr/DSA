class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = 2 * n;
        sort(reservedSeats.begin(), reservedSeats.end());
        for(int i = 0; i < reservedSeats.size();) {
            int row = reservedSeats[i][0];
            bool left = true, right = true, middle = true;
            while(i < reservedSeats.size() && reservedSeats[i][0] == row) {
                int x = reservedSeats[i][1];
                if(x >= 2 && x <= 5) left = false;
                if(x >= 6 && x <= 9) right = false;
                if(x >= 4 && x <= 7) middle = false;
                i++;
            }
            if(left && right) ans -= 0;
            else if(left || right || middle) ans -= 1;
            else ans -= 2;
        }
        return ans;
    }
};