class Solution {
    private :
int count=0;
string x="";
int k;
void temp(vector<int> &nums,vector<bool> &visit,string &s){
     if(s.size() == nums.size())
     {   
         if(!x.empty()&&count+1==k)
            return;
         else if(count+1==k)
         {
             x=s;
             return ;
         }else {
             count++;
             return;
         }
     }
     for(int i= 0;i<nums.size();i++){
         if(!visit[i]){
             visit[i]=true;
             s.push_back(nums[i]+'0');
             temp(nums,visit,s);
             s.pop_back();
             visit[i]=false;            
         }
     }
} 
public:
    string getPermutation(int n, int K) {
        k=K;
        vector<int> nums;
        for(int i=0;i<n;i++){
            nums.push_back(i+1);
        }
        string s="";
        vector<bool> visit(n,false);
        temp(nums,visit,s);
        cout<<count;
        return x;
    }
};