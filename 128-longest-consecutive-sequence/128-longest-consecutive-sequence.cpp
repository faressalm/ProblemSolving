class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_map<int,bool> m;
       for(auto num:nums)
           m[num]=false;
        int left,right;
        int sol = 0;
       for(auto num:nums)
       {
           if(!m[num]){
               left=right=1;
               while(m.find(num-left)!=m.end()){
                   m[num-left]=true;
                   left++;
               }
               while(m.find(num+right)!=m.end()){
                   m[num+right]=true;
                   right++;
               }
               sol =max(sol,left+right-1);
               m[num]=true;
           }
       }
        return sol;
    }
};