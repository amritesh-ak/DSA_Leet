class Solution {
public:
//If the smallest cookie cannot satisfy the least greedy child, it cannot satisfy any child. Therefore, discarding that cookie can never hurt the optimal answer.
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count=0;
        // sort both 
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i=0,j=0;

        while(i<g.size()&& j<s.size()){
            if(g[i]<=s[j]){
                count++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return count;
    }
};