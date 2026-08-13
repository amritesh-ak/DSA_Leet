class Solution {
public:

    struct Node {
        char leftChar, rightChar;
        int prefix, suffix, best, len;

        Node() {
            leftChar = rightChar = '#';
            prefix = suffix = best = len = 0;
        }

        Node(char c) {
            leftChar = rightChar = c;
            prefix = suffix = best = len = 1;
        }
    };

    vector<Node> seg;
    string s;

    Node merge(Node a, Node b) {

        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.prefix = a.prefix;
        res.suffix = b.suffix;

        res.best = max(a.best, b.best);

        if (a.rightChar == b.leftChar) {

            res.best = max(res.best, a.suffix + b.prefix);

            if (a.prefix == a.len)
                res.prefix = a.len + b.prefix;

            if (b.suffix == b.len)
                res.suffix = b.len + a.suffix;
        }

        return res;
    }

    void build(int node, int l, int r) {

        if (l == r) {
            seg[node] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {

        if (l == r) {
            seg[node] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx, c);
        else
            update(2 * node + 1, mid + 1, r, idx, c);

        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    vector<int> longestRepeating(string s,
                                 string queryCharacters,
                                 vector<int>& queryIndices) {

        this->s = s;

        int n = s.size();

        seg.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int idx = queryIndices[i];
            char c = queryCharacters[i];

            s[idx] = c;

            update(1, 0, n - 1, idx, c);

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};