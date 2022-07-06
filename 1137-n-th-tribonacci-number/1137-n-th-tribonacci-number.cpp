class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
            return n;
        int f1=0;
        int f2=1;
        int f3=1;
        int temp;
        for(int i=3;i<=n;i++){
            temp=f3;
            f3+=f1+f2;
            f1=f2;
            f2=temp;
        }
        return f3;
    }
};