class Solution {
        private:  map<string,int> initDic(){
        return {
            {"I",1},
            {"IV",4},
            {"V",5},
            {"IX",9},
            {"X",10},
            {"XL",40},
            {"L",50},
            {"XC",90},
            {"C",100},
            {"CD",400},
            {"D",500},
            {"CM",900},
            {"M",1000},
        };
    }
public:
    int romanToInt(string s) {
         map<string,int> dic =  initDic();
        int sol=0;
        for(int i=0;i<s.size();i++){
            string roman = "";
            roman+=s[i];
            if(i<s.size()-1&&dic[roman+s[i+1]]!=0){
                sol+=dic[roman+s[i+1]];
                i++;
            }else{
             sol+=dic[roman];
            }
        }
        return sol;
    }
};