class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.size();
        if(size<2)
            return 0;
        int sol =0;
        stack<pair<char,int>> st;
        for(int i=0;i<size;i++){
                if(s[i]==')'&&!st.empty()&&st.top().first=='(')
                { 
                    st.pop();
                }else{
                    st.push({s[i],i});
                }
        }
        int start =0 ;
        int end=size;
        if(st.empty())
            return size;
        while(!st.empty()){
            start = st.top().second+1;
            sol=  max(sol,end-start);
            end = st.top().second;
            st.pop();
        }
         sol=  max(sol,end-0);
        return sol;
    }
};