 bool dfs(int i,int j,vector<vector<char> >& board,string s,int ch,vector<vector<int>> &vis){
        
        int n = board.size();
        int m = board[0].size();
        
        int delrow[] = {-1,-1,0,1,1,1,0,-1};
        int delcol[] = {0,1,1,1,0,-1,-1,-1};
        
        for(int loop=0;loop<8;loop++){
            int nrow = i + delrow[loop];
            int ncol = j + delcol[loop];
            
            if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and vis[nrow][ncol]==0 and board[nrow][ncol]==string[ch+1] ){
                vis[nrow][ncol]=1;
                if(dfs(nrow,ncol,board,s,ch+1,vis))return true;
            }
        }
        
        
       return false;
    }
    bool exists(vector<vector<char>>& board,string s){
        int ch=0;
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==s[ch]){
                    vis[i][j]=1;
                    if(dfs(i,j,board,s,ch,vis))return true;
                    vis[i][j]=0;
                }
            }
        }
        return false;
    }

	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	   vector<string> res;
	   
	   for(int i=0;i<dictionary.length();i++){
	       string s = dictionary[i];
	       if(exists(board,s)){
	           res.push_back(s);
	       }
	   }
	   return res;
	}