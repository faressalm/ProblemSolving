#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// Declaring ordered_set for pair<int,int>
typedef tree<pair<int,int>, null_type, 
        less<pair<int,int>>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set_pair;
class Solution {
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> sol(nums.size(),0);
        ordered_set_pair q;
        q.insert({nums[nums.size()-1],nums.size()});
        for(int i=nums.size()-2;i>=0;i--){
            sol[i] = q.order_of_key({nums[i],-1});
            q.insert({nums[i],i});
        }
        return sol;
    }
};