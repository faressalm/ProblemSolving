class Solution {
    private:  map<int,string> initDic(){
        return {
            {1,"I"},
            {4,"IV"},
            {5,"V"},
            {9,"IX"},
            {10,"X"},
            {40,"XL"},
            {50,"L"},
            {90,"XC"},
            {100,"C"},
            {400,"CD"},
            {500,"D"},
            {900,"CM"},
            {1000,"M"},
        };
    }
public:
    string intToRoman(int num) {
        map<int,string> dic = initDic();
        string roman="";
        while(num!=0){
            if(!dic[num].empty()){
                roman+=dic[num];
                break;
            }else{
                int numberOfDigits = int(log10(num) + 1);
                int tens = (int) pow(10,numberOfDigits-1);
                int digit = (num / tens)*tens;
                num = num % (int) tens;
                
                if(!dic[digit].empty())
                    roman += dic[digit];
                else{
                    int half = (int)pow(10,numberOfDigits)/2;
                    if(digit> half){
                        roman+=dic[half];
                        digit-= half;
                    }
                   for(int i=0;i<digit/tens;i++)
                       roman += dic[tens];
                }
            }
        }
        
        return roman;
    }
};