class Solution {
public:
    int candy(vector<int>& ratings) {
        int low = INT_MAX;
        int lowIndex=0;
        vector<pair<int,int>> q;
        for(int i=0;i<ratings.size();i++)
          q.push_back({ratings[i],i});
        sort(q.begin(),q.end());
        vector<int> candy(ratings.size(),1);
        int candies =0;
        for(int i=0;i<q.size();i++){
            int index = q[i].second;
            if(index!=0&&ratings[index]>ratings[index-1])
                candy[index] = 1+ candy[index-1];
            if(index!=ratings.size()-1&&ratings[index]>ratings[index+1])
                candy[index] = max(1+candy[index+1],candy[index]);
            candies +=candy[index]; 
        }
        return candies;
    }
};