class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;

        // Give every litter a bit number
        vector<vector<int>> id(m, vector<int>(n, -1));
        int litter = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = litter++;
                }
            }
        }

        int fullMask = (1 << litter) - 1;

        // maxEnergy[row][col][mask]
        // stores maximum energy with which we have reached this state
        vector<vector<vector<int>>> maxEnergy(
            m,
            vector<vector<int>>(n, vector<int>(1 << litter, -1))
        );

        queue<tuple<int, int, int, int, int>> q;

        // row, col, mask, energy, moves
        q.push({sr, sc, 0, energy, 0});

        maxEnergy[sr][sc][0] = energy;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto [r, c, mask, en, moves] = q.front();
            q.pop();

            if (mask == fullMask) {
                return moves;
            }

            // If energy is 0, we cannot make another move
            if (en == 0) {
                continue;
            }

            for (int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                // Outside grid
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                // Obstacle
                if (classroom[nr][nc] == 'X')
                    continue;

                int newEnergy = en - 1;
                int newMask = mask;

                // Collect litter
                if (classroom[nr][nc] == 'L') {
                    newMask |= (1 << id[nr][nc]);
                }

                // Reset energy
                if (classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }

                // If we have already reached this position with
                // same mask and MORE energy, this state is useless.
                if (maxEnergy[nr][nc][newMask] >= newEnergy)
                    continue;

                maxEnergy[nr][nc][newMask] = newEnergy;

                q.push({
                    nr,
                    nc,
                    newMask,
                    newEnergy,
                    moves + 1
                });
            }
        }

        return -1;
    }
};