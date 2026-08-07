class Solution {
    int f[48][31];

    void precompute() {
        for (int i = 0; i < 48; i++) {
            for (int j = 0; j < 31; j++) {
                f[i][j] = 1e9;
            }
        }

        f[0][0] = 0;

        int d_pa[] = {1, 0, 2, 1, 3, 0};
        int d_pb[] = {0, 1, 0, 1, 0, 2};

        for (int a = 0; a < 48; a++) {
            for (int b = 0; b < 31; b++) {

                if (a == 0 && b == 0)
                    continue;

                for (int k = 0; k < 6; k++) {

                    int prev_a = std::max(0, a - d_pa[k]);
                    int prev_b = std::max(0, b - d_pb[k]);

                    f[a][b] = std::min(f[a][b], 1 + f[prev_a][prev_b]);
                }
            }
        }
    }

    struct Factors {
        int c2, c3, c5, c7;
    };

    Factors getFactors(long long n) {

        Factors res = {0, 0, 0, 0};

        while (n % 2 == 0) {
            res.c2++;
            n /= 2;
        }

        while (n % 3 == 0) {
            res.c3++;
            n /= 3;
        }

        while (n % 5 == 0) {
            res.c5++;
            n /= 5;
        }

        while (n % 7 == 0) {
            res.c7++;
            n /= 7;
        }

        return res;
    }

    int getMinLen(long long n) {

        Factors fct = getFactors(n);

        if (fct.c2 >= 48 || fct.c3 >= 31)
            return 1e9;

        return fct.c5 + fct.c7 + f[fct.c2][fct.c3];
    }

    std::string buildSuffix(int len, long long req) {

        std::string ans;

        for (int pos = 1; pos <= len; pos++) {

            for (int d = 1; d <= 9; d++) {

                long long g = std::gcd(req, (long long)d);

                long long nxt = req / g;

                if (getMinLen(nxt) <= len - pos) {

                    ans += char('0' + d);
                    req = nxt;
                    break;
                }
            }
        }

        return ans;
    }

public:
    std::string smallestNumber(std::string num, long long t) {

        long long tmp = t;

        for (long long p : {2LL, 3LL, 5LL, 7LL}) {

            while (tmp % p == 0)
                tmp /= p;
        }

        if (tmp > 1)
            return "-1";

        precompute();

        int n = num.size();

        bool zero = false;

        for (char c : num) {

            if (c == '0') {
                zero = true;
                break;
            }
        }

        if (!zero) {

            long long g = 1;

            for (char c : num)
                g = std::gcd(t, g * (c - '0'));

            if (g == t)
                return num;
        }

        int firstZero = num.find('0');

        if (firstZero == std::string::npos)
            firstZero = n;

        std::vector<long long> pref(n + 1, 1);

        for (int i = 0; i < n; i++)
            pref[i + 1] = std::gcd(t, pref[i] * (num[i] - '0'));

        for (int i = n - 1; i >= 0; i--) {

            if (i > firstZero)
                continue;

            long long g = pref[i];

            for (int d = (num[i] - '0') + 1; d <= 9; d++) {

                long long nxt = std::gcd(t, g * d);

                long long req = t / nxt;

                int rem = n - i - 1;

                if (getMinLen(req) <= rem) {

                    return num.substr(0, i) + char('0' + d) +
                           buildSuffix(rem, req);
                }
            }
        }

        int len = n + 1;

        while (true) {

            if (getMinLen(t) <= len)
                return buildSuffix(len, t);

            len++;
        }

        return "-1";
    }
};