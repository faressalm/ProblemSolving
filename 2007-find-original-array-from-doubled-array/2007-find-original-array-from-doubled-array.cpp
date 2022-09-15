class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2!=0)
            return {};
        vector<int> freq(int(1e5+1),0);
        for(auto val:changed)
            freq[val]++;
        vector<int> sol;
        if(freq[0]%2!=0)
            return {};
        else{freq[0]/=2;
            while(freq[0]!=0)
            {
                    sol.push_back(0);
                    freq[0]--;  
            }
        }
        for(int i=1;i<=int(1e5/2);i++)
            if(freq[i]==0)
                continue;
            else if(freq[i*2]>=freq[i]){
                freq[i*2]-=freq[i];
                while(freq[i]!=0){
                    sol.push_back(i);
                    freq[i]--;
                }
            }
            else return {};
        if(sol.size()==changed.size()/2)
            return sol; 
        return {};
    }
};