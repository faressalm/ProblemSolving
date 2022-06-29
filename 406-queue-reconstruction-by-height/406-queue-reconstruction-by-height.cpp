class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector < int > & i1,
        const vector < int > & i2) {
              if(i1[0]==i2[0])
                  return i1[1]>i2[1];
              return i1[0]<i2[0];
        });
        vector<vector<int>> sol(people.size());
        sol[people[0][1]] = people[0];
        int index= people[0][1];
        int k= people[0][1];
        for(int i=1;i<people.size();i++){
            if(people[i][1]<k){
                int j;
                int temp =people[i][1];
                for(j=0;j<index&&temp>=0;j++){
                    if(sol[j].empty())
                        temp--;             
                }
                index=j-1;
            }else{
                int j;
                int temp =people[i][1]-k;
                for(j=index+1;j<people.size()&&temp>=0;j++){
                    if(sol[j].empty())
                        temp--;    
                }
                index=j-1;
            }
            cout<<people[i][0]<<","<<people[i][1]<<" : "<< index<<endl;
            sol[index] = people[i];
            k= people[i][1];
        }
        return sol;
    }
};