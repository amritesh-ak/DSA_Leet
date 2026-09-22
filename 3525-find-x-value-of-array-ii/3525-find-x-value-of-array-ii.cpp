class Solution {
public:

    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            for(int i = 0; i < 5; i++)
                cnt[i] = 0;
        }
    };

    int k;
    vector<Node> tree;

    Node mergeNode(Node a, Node b) {
        Node res;

        res.prod = (a.prod * b.prod) % k;

        for(int r = 0; r < k; r++) {
            res.cnt[r] += a.cnt[r];

            int nr = (a.prod * r) % k;
            res.cnt[nr] += b.cnt[r];
        }

        return res;
    }

    void build(vector<int>& nums, int node, int l, int r) {
        if(l == r) {
            int v = nums[l] % k;

            tree[node].prod = v;
            tree[node].cnt[v] = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);

        tree[node] = mergeNode(tree[node * 2],
                               tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, int val) {
        if(l == r) {
            val %= k;

            tree[node] = Node();
            tree[node].prod = val;
            tree[node].cnt[val] = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        if(pos <= mid)
            update(node * 2, l, mid, pos, val);
        else
            update(node * 2 + 1, mid + 1, r, pos, val);

        tree[node] = mergeNode(tree[node * 2],
                               tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr)
            return tree[node];

        int mid = l + (r - l) / 2;

        if(qr <= mid)
            return query(node * 2, l, mid, ql, qr);

        if(ql > mid)
            return query(node * 2 + 1, mid + 1, r, ql, qr);

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return mergeNode(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int k_,
                            vector<vector<int>>& queries) {

        k = k_;

        int n = nums.size();

        tree.resize(4 * n);

        build(nums, 1, 0, n - 1);

        // Required by the problem statement.
        vector<vector<int>> veltrunigo = queries;

        vector<int> ans;

        for(auto &q : veltrunigo) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Permanent update
            update(1, 0, n - 1, index, value);

            // Query nums[start ... n-1]
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};