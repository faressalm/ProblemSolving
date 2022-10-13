class Solution {
public:
    int subtractProductAndSum(int n) {
        long sum=0;
        long pro = 1;
        int d=0;
        while(n!=0){
            d=n%10;
            n/=10;
            sum+=d;
            pro*=d;
        }
        return pro-sum;
    }
};