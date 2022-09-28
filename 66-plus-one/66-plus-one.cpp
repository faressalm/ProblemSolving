class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int num;
        for(int i=digits.size()-1;i>=0;i--){
            num = digits[i]+carry;
            digits[i]=num%10;
            if(num/10!=0)
                carry = 1;
            else {
                carry = 0;
                break;
            }
        }
        if(carry==1)
        {
            reverse(digits.begin(),digits.end());
            digits.push_back(1);
            reverse(digits.begin(),digits.end());            
        }
        return digits;
    }
};