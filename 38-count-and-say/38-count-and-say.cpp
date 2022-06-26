class Solution {
private: string temp(int n,string s){
    if(n==1)
        return s;
    n--;
    int count =1;
    char prev = s[0];
    vector<char> newS;
    for(int i=1;i<s.size();i++){
        if(prev!=s[i]){
            newS.push_back(char('0' +count));
            newS.push_back(prev);
            prev=s[i];
            count=1;
        }else 
            count++;
    }
    newS.push_back(char('0' +count));
    newS.push_back(prev);    
    return temp(n,string(newS.begin(),newS.end()));
}   
public:
    string countAndSay(int n) {
        return temp(n,"1");
    }
};