class Solution {
public:
    string multiply(string num1, string num2) {
        string sol(num1.size()+num2.size(),'0');
        for(int i=num1.size()-1;i>=0;i--){
            int solIndex = sol.size()-num1.size()+i;
            int carry =0;
            int n1 =num1[i]-'0'; 
            for(int j=num2.size()-1;j>=0;j--){
                int n2 =num2[j]-'0';
                int prev = sol[solIndex] - '0';
                int digit = (n1*n2+carry+prev)%10;
                sol[solIndex] = to_string(digit)[0];
                solIndex--;
                carry = (n1*n2+carry+prev)/10;
            }
            while(carry!=0&&solIndex>=0)
            {   
                int digit =  ((sol[solIndex] - '0' )+carry)%10;
                carry = ((sol[solIndex] - '0' )+carry)/10;
                sol[solIndex] = to_string(digit)[0];
                solIndex--;
            }
        
        }
        //to over come leading zeros
        int start=0;
        while(sol[start]=='0'&&start<sol.size()-1)
            start++;
        return sol.substr(start);

    }
};