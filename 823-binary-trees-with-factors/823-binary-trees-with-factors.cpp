class Solution {
    // better than sqrt check previous elements only
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int,long> tree;
        int mode=1e9+7;
        for(auto & num:arr)
            tree[num]=1;
        sort(arr.begin(),arr.end());
        int sum=0;
        for(int num=0;num<arr.size();num++){
            for(int i=0;i<num;i++){
                if(arr[num]%arr[i]==0)
                {
                    tree[arr[num]]=
                        (tree[arr[num]]+(tree[arr[i]]*tree[arr[num]/arr[i]])%mode) %mode;
                }
            }
            sum=(sum+tree[arr[num]])%mode;
        }
        return sum;
    }
};