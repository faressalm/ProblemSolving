class Solution {
public:
    int fib(int n) {
        if(n<2)
            return n;
        int f1=0;
        int f2=1;
        int temp;
        for(int i=2;i<=n;i++){
            temp=f2;
            f2+=f1;
            f1=temp;
        }
        return f2;
    }
};