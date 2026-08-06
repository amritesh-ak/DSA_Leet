class Solution {
public:
    int prods(int num){
        int prod=1;
        while(num){
            prod *= num%10;
            num /= 10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        int ans=0;
        for(int i=n ; ;i++){
        int prod=prods(i);
        if(prod%t==0){
            ans=i;
            break;
        }
    }

        return ans;
    }
};