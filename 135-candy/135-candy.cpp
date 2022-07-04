class Solution {
public:
    int candy(vector<int>& ratings) {
        int low = INT_MAX;
        int lowIndex=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        for(int i=0;i<ratings.size();i++)
          q.push({ratings[i],i});
        vector<int> candy(ratings.size(),1);
        int candies =0;
        while(!q.empty()){
            int index = q.top().second; q.pop();
            if(index!=0&&ratings[index]>ratings[index-1])
                candy[index] = 1+ candy[index-1];
            if(index!=ratings.size()-1&&ratings[index]>ratings[index+1])
                candy[index] = max(1+candy[index+1],candy[index]);
            candies +=candy[index]; 
        }
        return candies;
    }
};