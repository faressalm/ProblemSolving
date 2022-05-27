class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0)
            return 0;
        int count =0;
        int sign=1;
        if(divisor==-1){
            if(dividend==-2147483648)
                return 2147483647;
            return -dividend;
        }
        else if (divisor==1)
            return dividend;
        if(divisor>0&&dividend<0)
            {sign=-1;
             divisor=-divisor;
            }
        else if(dividend>0&&divisor<0){
            sign=-1;
            dividend=-dividend;
        }else if(dividend>0&&divisor>0){
             dividend=-dividend;
             divisor=-divisor;
        }
        if(dividend>divisor)
           return 0;
        while(dividend<=divisor){
            long temp= divisor;
            int mul =1;
            while(dividend<=temp)
            {
               dividend -= temp;
                count+= mul;
                mul+=mul;
                temp+=temp;
            }

        }
        if(count>=2147483647&&sign==1)
                return 2147483647;
        if(sign==-1){
            count=-count;
        }
        return count;
    }
};