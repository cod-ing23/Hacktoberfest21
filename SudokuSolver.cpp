vector<unordered_map<int,int>> rows(9);
vector<unordered_map<int,int>> cols(9);
vector<unordered_map<int,int>> box(9);

bool isValid(vector<vector<char>> board,pair<int,int> p,int i){
    int r=p.first,c=p.second;
    if(rows[r].find(i)!=rows[r].end()) return false;
    if(cols[c].find(i)!=cols[c].end()) return false;
    if(box[(r/3)*3+c/3].find(i)!=box[(r/3)*3+c/3].end()) return false;
    rows[r][i]++;
    cols[c][i]++;
    box[(r/3)*3+c/3][i]++;
    return true;
}


bool solve(vector<vector<char>> &b,vector<pair<int,int>> v,int ct,int n){
    if(ct==n) return true;
    for(int i=1;i<=9;i++){
        if(isValid(b,v[ct],i)){
            b[v[ct].first][v[ct].second]='0'+i;
            if(solve(b,v,ct+1,n)) return true;
            b[v[ct].first][v[ct].second]='.';
            rows[v[ct].first].erase(i);
            cols[v[ct].second].erase(i);
            box[(v[ct].first/3)*3+v[ct].second/3].erase(i);
        }
    }
    return false;
}


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        rows.clear();
        cols.clear();
        box.clear();
        rows.resize(9);cols.resize(9);box.resize(9);
        vector<pair<int,int>> v;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') v.push_back({i,j});
                else{
                    rows[i][board[i][j]-'0']++;
                    cols[j][board[i][j]-'0']++;
                    box[(i/3)*3+j/3][board[i][j]-'0']++;
                }
            }
        }
        int n=v.size();
        // cout<<v.size()<<endl;
        solve(board,v,0,n);
    }
};