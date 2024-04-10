class Solution {
public:
    bool checkn(int i,int j, vector<vector<char>>&board,bool &nc,int direction,vector<vector<bool>>&visited2,vector<pair<int,int>>&queue){
        visited2[i][j]=true;
        //cout<<i<<" "<<j<<'\n';
        queue.push_back({i,j});
        if(i==0||i==board.size()-1||j==0||j==board[0].size()-1)nc=true;    
        
        if(j-1>=0&&direction!=1&&!visited2[i][j-1]&&board[i][j-1]=='O')checkn(i,j-1,board,nc,2,visited2,queue);            
        if(j+1<board[0].size()&&direction!=2&&!visited2[i][j+1]&&board[i][j+1]=='O')checkn(i,j+1,board,nc,1,visited2,queue);
        if(i-1>=0&&direction!=3&&!visited2[i-1][j]&&board[i-1][j]=='O')checkn(i-1,j,board,nc,4,visited2,queue);
        if(i+1<board.size()&&direction!=4&&!visited2[i+1][j]&&board[i+1][j]=='O')checkn(i+1,j,board,nc,3,visited2,queue);
        
        return nc;
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>>visited2(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                vector<pair<int,int>>queue;
                bool nc=false;
                set<pair<int,int>>visited;
                cout<<"go"<<'\n';
                if(board[i][j]=='O'&&visited2[i][j]==false)
                if(!checkn(i,j,board,nc,0,visited2,queue))
                        for(auto i:queue){
                            board[i.first][i.second]='X';
                        }
            }
        }
        
    }
};
