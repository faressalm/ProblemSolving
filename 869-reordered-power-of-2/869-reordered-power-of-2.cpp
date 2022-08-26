class Solution {
private: vector<int> getFreq(int n){
    vector<int> freq(10,0);
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
        vector<int> numFreq  =  getFreq(n);
        vector<int>  freq;
        bool found =false;
        for(auto num: twos[index]){
            freq = getFreq(num);
            if(equal(freq.begin(),freq.end(),numFreq.begin()))
                return true;
        }
        return false;

    }
};