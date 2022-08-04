class Solution {
public:
    int mirrorReflection(int p, int q) {
        //Divide p,q by 2 until at least one odd.
        while ((p%2==0) and (q%2==0)){
            p/=2;
            q/=2;
        }

        return 1 - p % 2 + q % 2;
    }
};