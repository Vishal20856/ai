#include <bits/stdc++.h>
#include<vector>
using namespace std;

class Nqueen{
	public:
	void dfs(int n,int i,vector<bool>&&cols,vector<bool>&&diag1,vector<bool>&&diag2,vector<string>&&board,vector<vector<string>>&ans)
	{
		if(i==n){
			ans.push_back(board);
			return;
		}

		for(int j=0;j<n;j++){
			if(cols[j]||diag1[i+j] || diag2[j-i+n-1])
				continue;
			board[i][j]='Q';
			cols[j]=diag1[i+j]=diag2[j-i+n-1]=true;
			dfs(n,i+1,move(cols),move(diag1),move(diag2),move(board),ans);
			cols[j]=diag1[i+j]=diag2[j-i+n-1]=false;
			board[i][j]='.';				
		}
	}

	
		vector<vector<string>>solve(int n){
			vector<vector<string>>ans;
			dfs(n,0,vector<bool>(n),vector<bool>(2*n-1),vector<bool>(2*n-1),vector<string>(n,string(n,'.')),ans);
			return ans;		
		}

		void print_board(vector<vector<string>>ans){
			for(int i=0;i<ans.size();i++){
				for(int j=0;j<ans[0].size();j++){
					cout<<ans[i][j]<<"\n";
				}
				cout<<"\n\n";
			}
		}
};

int main()
{
	Nqueen s;
	cout<<"Enter Size of board: ";
	int n; cin>>n;
	
	vector<vector<string>>sol(n,vector<string>(n," "));
	sol =s.solve(n);
	s.print_board(sol);
	return 0;
}