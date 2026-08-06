class Solution {
public:
    int smallestNumber(int n, int t) {
        long long product = 1;
        int s = n;
        while(n>0){
            product = product * (n%10);
            n = n/10;
        }
        if(product % t == 0) return s;
        return smallestNumber(s+1,t);
    }
};