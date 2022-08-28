class Solution {
private: void pos(vector<vector<int>>& mat,int r,int c,int row,int col){
            int rr=r;int cc=c;
            vector<int> temp;
            while(r<row&&c<col){
                temp.push_back(mat[r][c]);
                r++;c++;
            }
            sort(temp.begin(),temp.end());
            r=rr;c=cc;
            for(int t=0;t<temp.size();t++)
                mat[r+t][c+t]=temp[t];
}
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row =mat.size();int col = mat[0].size();
        for(int i=0;i<col;i++){
            pos(mat,0,i,row,col);
        }
        for(int i=1;i<row;i++){
            pos(mat,i,0,row,col);
        }
        return mat;
    }
};