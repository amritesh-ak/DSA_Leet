class Solution {
public:

    struct Node {
        long long score;
        vector<int> ids;
    };

    bool better(const Node& a, const Node& b) {
        if(a.score != b.score)
            return a.score > b.score;

        return a.ids < b.ids;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        struct I {
            int l, r, id;
            long long w;
        };

        vector<I> a;

        for(int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                i,
                intervals[i][2]
            });
        }

        // Sort by right endpoint for weighted interval scheduling
        sort(a.begin(), a.end(), [](const I& x, const I& y) {
            if(x.r != y.r)
                return x.r < y.r;

            return x.id < y.id;
        });

        vector<int> ends(n);

        for(int i = 0; i < n; i++)
            ends[i] = a[i].r;

        // Previous compatible interval
        vector<int> prev(n);

        for(int i = 0; i < n; i++) {
            prev[i] =
                lower_bound(ends.begin(), ends.begin() + i, a[i].l)
                - ends.begin();
        }

        vector<vector<Node>> dp(n + 1, vector<Node>(5));

        for(int i = 1; i <= n; i++) {

            // Don't take current interval
            for(int cnt = 0; cnt <= 4; cnt++)
                dp[i][cnt] = dp[i - 1][cnt];

            int cur = i - 1;

            // Take current interval
            for(int cnt = 1; cnt <= 4; cnt++) {

                Node candidate = dp[prev[cur]][cnt - 1];

                candidate.score += a[cur].w;
                candidate.ids.push_back(a[cur].id);

                sort(candidate.ids.begin(), candidate.ids.end());

                if(better(candidate, dp[i][cnt]))
                    dp[i][cnt] = candidate;
            }
        }

        Node ans = dp[n][0];

        for(int cnt = 1; cnt <= 4; cnt++) {
            if(better(dp[n][cnt], ans))
                ans = dp[n][cnt];
        }

        return ans.ids;
    }
};