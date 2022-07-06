class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int> s;
        int count,first,temp,prev,sol=INT_MIN;
        for(int i=0;i<arr.size();i++)
            s[arr[i]] = i;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                count = 2;
                prev=arr[i]+arr[j];
                first= arr[j];
                while(s.find(prev)!=s.end()){
                    count++;
                    temp = prev;    
                    prev += first;
                    first = temp;
                }
                sol = max(count,sol);
            }
        }
        return sol==2?0:sol;
    }
};