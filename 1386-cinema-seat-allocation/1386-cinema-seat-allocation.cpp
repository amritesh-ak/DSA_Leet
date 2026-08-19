class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, int> mp;

        // Store reserved seats as a bitmask for each row
        for (auto &x : reservedSeats) {
            int row = x[0];
            int seat = x[1];

            if (seat >= 2 && seat <= 9) {
                mp[row] |= (1 << seat);
            }
        }

        int ans = (n - mp.size()) * 2;

        for (auto &p : mp) {
            int mask = p.second;

            bool left = true;   // 2,3,4,5
            bool mid = true;    // 4,5,6,7
            bool right = true;  // 6,7,8,9

            for (int seat = 2; seat <= 5; seat++) {
                if (mask & (1 << seat))
                    left = false;
            }

            for (int seat = 4; seat <= 7; seat++) {
                if (mask & (1 << seat))
                    mid = false;
            }

            for (int seat = 6; seat <= 9; seat++) {
                if (mask & (1 << seat))
                    right = false;
            }

            if (left && right)
                ans += 2;
            else if (left || mid || right)
                ans += 1;
        }

        return ans;
    }
};