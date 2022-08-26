class Solution {
private: unordered_map<int,int> getFreq(int n){
    unordered_map<int,int> freq;
    while(n!=0){
        freq[n%10]++;
        n/=10;
    }
    return freq;
}
public:
    bool reorderedPowerOf2(int n) {
        vector<vector<int>> twos(10);
        int power ;
        for(int i=0;i<31;i++){
            power = pow(2,i);
            twos[int(log10(power))].push_back(power);            
        }
        int index = log10(n);
        unordered_map<int,int> numFreq  =  getFreq(n);
        unordered_map<int,int> freq;
        bool found =true;
        for(auto num: twos[index]){
            freq = getFreq(num);
            found =true;
            for(auto &f:numFreq){
                if(freq[f.first]!=f.second)
                {
                    found =false;
                    break;
                }
            }
            if(found)
                return found;
        }
        return false;

    }
};