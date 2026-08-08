class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // prev_occ[i][c] = last occurrence of character c
        // at or before index i in word1
        vector<array<int, 26>> prev_occ(n);

        for (int c = 0; c < 26; c++)
            prev_occ[0][c] = -1;

        prev_occ[0][word1[0] - 'a'] = 0;

        for (int i = 1; i < n; i++) {
            prev_occ[i] = prev_occ[i - 1];
            prev_occ[i][word1[i] - 'a'] = i;
        }

        // R0[j] = largest index from which
        // word2[j...] can be matched EXACTLY
        vector<int> R0(m + 1, -1);

        R0[m] = n;

        for (int j = m - 1; j >= 0; j--) {

            if (R0[j + 1] > 0) {
                R0[j] =
                    prev_occ[R0[j + 1] - 1][word2[j] - 'a'];
            }
        }

        // R1[j] = largest index from which
        // word2[j...] can be matched with at most ONE mismatch
        vector<int> R1(m + 1, -1);

        R1[m] = n;

        for (int j = m - 1; j >= 0; j--) {

            // Use the one mismatch at this position
            int useChange = -1;

            if (R0[j + 1] > 0) {
                useChange = R0[j + 1] - 1;
            }

            // Match this position exactly
            int match = -1;

            if (R1[j + 1] > 0) {
                match =
                    prev_occ[R1[j + 1] - 1][word2[j] - 'a'];
            }

            R1[j] = max(useChange, match);
        }

        // ------------------------------------------------
        // Greedily construct lexicographically smallest
        // sequence of indices
        // ------------------------------------------------

        vector<int> ans;
        ans.reserve(m);

        int current = 0;
        bool changed = false;

        for (int j = 0; j < m; j++) {

            int picked = -1;

            for (int i = current; i < n; i++) {

                // We haven't used our mismatch yet
                if (!changed) {

                    // Use mismatch at i
                    bool useChange =
                        (i < R0[j + 1]);

                    // Match word2[j] exactly
                    bool exactMatch =
                        (word1[i] == word2[j] &&
                         i < R1[j + 1]);

                    if (useChange || exactMatch) {

                        picked = i;

                        if (word1[i] != word2[j])
                            changed = true;

                        break;
                    }
                }

                // Mismatch already used
                else {

                    if (word1[i] == word2[j] &&
                        i < R0[j + 1]) {

                        picked = i;
                        break;
                    }
                }
            }

            if (picked == -1)
                return {};

            ans.push_back(picked);
            current = picked + 1;
        }

        return ans;
    }
};