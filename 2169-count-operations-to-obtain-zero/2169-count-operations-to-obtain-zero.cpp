class Solution {
public:
    int countOperations(int num1, int num2) {
        int temp;
        int counter =0;
        temp = max(num1,num2);
        num1 = min(num1,num2);
        while(num1!=0){
            counter +=temp/num1;
            num2 = num1;
            num1=temp%num1;
            temp = num2;
        }
        return counter;
    }
};