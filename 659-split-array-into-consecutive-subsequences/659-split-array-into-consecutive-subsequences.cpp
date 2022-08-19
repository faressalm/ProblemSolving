class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int size = nums.size();
        vector<pair<int,int>> seqs={{nums[0],1}};// first: last number ,  second:size
        bool notAdded=true;
        int index;
        for(int i=1;i<size;i++){
            index = seqs.size()-1;
            while(index>=0){
              if(seqs[index].first+1==nums[i])
                {   
                    notAdded =false;
                    seqs[index].first++;
                    seqs[index].second++;
                    break;
                }
                index--;
            }
            if(notAdded)
                seqs.push_back({nums[i],1});
            else notAdded = true;
        }
        for(auto &seq:seqs)
            if(seq.second<3)
                return false;
        return true;
    }
};