class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum=0;
        long long prod=1;
        int p=n;
        while(p){
            int x=p%10;
            sum +=x;
            prod *=x;
            p=p/10;
        }

        int total=sum+prod;

        return (n%total)? false :true;
    }
};