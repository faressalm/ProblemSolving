class Solution {
private: void temp(int r1,int r2,int c1, int c2,vector<vector<int>>& matrix,int &num){
    for(int c=c1;c<c2;c++)
        matrix[r1][c] = num++;
    bool e = (c1<c2);
    for(int r=r1+1;r<r2&&e;r++)
        matrix[r][c2-1] = num++;
    e= e&&(r1+1<r2);
    for(int c=c2-2;c>=c1&&e;c--)
        matrix[r2-1][c] = num++;
    e =e&&(c2-2>=c1);
    for(int r=r2-2;r>r1&&e;r--)
        matrix[r][c1] = num++;
}    
public:
    vector<vector<int>> generateMatrix(int n) {
        bool changeCol = true;
        int r1=0;int r2=n;
        int c1=0;int c2=n;
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int spiralsLen = min(ceil(double(r2)/2),ceil(double(c2)/2));
        int num=1;
        for(int i=0;i<spiralsLen;i++){
            temp(r1+i,r2-i,c1+i,c2-i,matrix,num);
        }
        return matrix;        
    }
};
