class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size()==1)
            return "";
        int i;
        for(i=0;i<palindrome.size();i++)
            if(palindrome[i]!='a'&&(palindrome.size()%2==0||(i!=palindrome.size()-i-1)))
                break;
        if(i==palindrome.size())
        {
            palindrome[palindrome.size()-1] ='b';
        }else
            palindrome[i] = 'a';
        return palindrome;
    }
};