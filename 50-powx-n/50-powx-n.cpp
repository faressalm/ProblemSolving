class Solution {
    
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        int sign = n<0?-1:1;
        double y=1;
        if(n==INT_MIN){
            y=x;
            n=INT_MAX;
        }else{
             n=abs(n);
        }
        while(n!=0){
            if(n&1==1)
                y*=x;
            n=n>>1;
            x*=x;
        }
        return sign>0?y:1/y;
    }
};