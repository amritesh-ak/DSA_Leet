class Solution {
public:
// redooooooo
    set<string> parseExpression(string &s, int &i) {
        set<string> ans = parseTerm(s, i);

        while(i < s.size() && s[i] == ',') {
            i++;

            set<string> temp = parseTerm(s, i);

            for(auto &x : temp)
                ans.insert(x);
        }

        return ans;
    }

    set<string> parseTerm(string &s, int &i) {
        set<string> ans;
        ans.insert("");

        while(i < s.size() && s[i] != '}' && s[i] != ',') {

            set<string> cur = parseFactor(s, i);

            set<string> temp;

            for(auto &a : ans) {
                for(auto &b : cur) {
                    temp.insert(a + b);
                }
            }

            ans = temp;
        }

        return ans;
    }

    set<string> parseFactor(string &s, int &i) {
        set<string> ans;

        if(s[i] == '{') {
            i++;

            ans = parseExpression(s, i);

            i++; // skip '}'
        }
        else {
            ans.insert(string(1, s[i]));
            i++;
        }

        return ans;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = parseExpression(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};