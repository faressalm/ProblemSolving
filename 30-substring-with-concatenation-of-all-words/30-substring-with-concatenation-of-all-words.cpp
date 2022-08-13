class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLen = words[0].size();
        unordered_map<string,int> orgDic;
        vector<int> sol;
        
        for(auto str: words)
            orgDic[str]++;
        int wordsLen =words.size();
        int window=wordsLen;
        unordered_map<string,int> dic= orgDic;
        
        for(int i= 0;i<s.size();i+=wordLen){
            string sub = s.substr(i,wordLen);
            int startInd =i-(wordsLen-window)*wordLen;
            if(dic.count(sub)==0){
                i=startInd-wordLen+1;
                window=wordsLen;
                dic=orgDic;
            }
            else if(dic[sub]!=0){
                dic[sub]--;
                window--;
                if(window==0){
                    sol.push_back(startInd);
                    if(dic.count(s.substr(startInd+1,wordLen))!=0){
                      i=startInd+1-wordLen;
                      window=wordsLen;
                      dic=orgDic;
                    }else{
                    window++;
                    dic[s.substr(startInd,wordLen)]++;
                    }

                }
            }else{

                     string startStr = s.substr(startInd,wordLen);
                if(dic.count(s.substr(startInd+1,wordLen))!=0){
                      i=startInd+1-wordLen;
                      window=wordsLen;
                      dic=orgDic;
                    }else{
                                    while(startStr!=sub){
                 window++;
                 dic[startStr]++;  
                 startInd+=wordLen;   
                 startStr = s.substr(startInd,wordLen);   
                }
                }

            }
        }
        return sol;
    }
};