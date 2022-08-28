class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row =mat.size();int col = mat[0].size();
        
        for(int i=0;i<col;i++){
            int r=0;int c =i;
            vector<int> temp;
            while(r<row&&c<col){
                temp.push_back(mat[r][c]);
                r++;c++;
            }
            sort(temp.begin(),temp.end());
            r=0;c=i;
            for(int t=0;t<temp.size();t++)
                mat[r+t][c+t]=temp[t];
        }
        for(int i=1;i<row;i++){
            int r=i;int c=0;
            vector<int> temp;
            while(r<row&&c<col){
                temp.push_back(mat[r][c]);
                r++;c++;
            }
            sort(temp.begin(),temp.end());
            r=i;c=0;
            for(int t=0;t<temp.size();t++)
                mat[r+t][c+t]=temp[t];
        }
        return mat;
    }
};