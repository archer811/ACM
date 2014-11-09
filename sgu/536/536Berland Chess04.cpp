#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define inf 0x0f0f0f0f

using namespace std;
int n, m;
int can[16][20][20], ID[20][20];
char maze[20][20];

int X1[8]={-2,-2,-1,-1, 1, 1, 2, 2};
int Y1[8]={-1, 1,-2, 2,-2, 2,-1, 1};
int X2[4]={-1,-1, 1, 1};
int Y2[4]={-1, 1,-1, 1};
int X3[4]={ 0, 0,-1, 1};
int Y3[4]={-1, 1, 0, 0};
int X[8]={ 0, 0,-1, 1,-1,-1, 1, 1};
int Y[8]={-1, 1, 0, 0,-1, 1,-1, 1};

int used(int x, int y) { return (x>0 && x<=n && y>0 && y<=m) ; }
void move1(int id, int x, int y)
{
	for (int t=0; t<8; t++)
	{
		int i=x+X1[t], j=y+Y1[t];
		if (used(i, j)) can[id][i][j]=1;
	}
}
void move2(int id, int x0, int y0)
{
	for (int i=0; i<4; i++)
		for (int j=1; true; j++)
		{
			int x=x0+X2[i]*j, y=y0+Y2[i]*j;
			can[id][x][y]=1;
			if (used(x, y)==0 || maze[x][y]!='.') break;
		}
}
void move3(int id, int x0, int y0)
{
	for (int i=0; i<4; i++)
		for (int j=1; true; j++)
		{
			int x=x0+X3[i]*j, y=y0+Y3[i]*j;
			can[id][x][y]=1;
			if (used(x, y)==0 || maze[x][y]!='.') break;
		}
}

void pre()
{
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (ID[i][j])
			{
				if (maze[i][j]=='K') move1(ID[i][j], i, j);
				if (maze[i][j]=='B') move2(ID[i][j], i, j);
				if (maze[i][j]=='R') move3(ID[i][j], i, j);
			}
}

struct NODE {
	int x, y, z;
	NODE () {}
	NODE (int x, int y, int z) : x(x), y(y), z(z) {}
}	tmp;


int F[17][17][35000];
int inq[17][17][35000];
int SPFA(int sx, int sy, int _st)
{
	int ans=inf;
	queue <NODE> q;
	memset(F, 0x0f, sizeof(F));
	memset(inq, 0, sizeof(inq));

	for (q.push(NODE(sx, sy, _st)), inq[sx][sy][_st]=1, F[sx][sy][_st]=0; q.empty()==0; )
	{
		tmp=q.front(); q.pop();
		int x=tmp.x, y=tmp.y, z=tmp.z, f=F[x][y][z]; inq[x][y][z]=0;
		if (z==0) { ans=min(f, ans); continue ; }

		for (int t=0; t<8; t++)
		{
			int i=x+X[t], j=y+Y[t], flg=0, st=z;
			if (used(i, j)==0) continue ;
			for (int k=0; k<15; k++) if (((1<<k)&z) && can[k+1][i][j]==1) { flg=1; break ; }
			//cout<<flg<<"()"<<endl;
			if (flg) continue ;

			if (ID[i][j] && (st&(1<<(ID[i][j]-1)))) st^=1<<(ID[i][j]-1);
			if(z!=st)
            cout<<z<<" "<<st<<endl;
			if (F[i][j][st]>f+1)
			{
				F[i][j][st]=f+1;
				if (inq[i][j][st]==0) inq[i][j][st]=1, q.push(NODE(i, j, st));
			}
		}
	}

	return ans;
}

int main()
{
	//freopen("1.txt", "r", stdin);

	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; i++) scanf("%s", maze[i]+1);

	int id=0, sx, sy;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
		{
			if (maze[i][j]!='.' && maze[i][j]!='*') ID[i][j]=++id;
			if (maze[i][j]=='*') sx=i, sy=j;
		}

	pre();
	int ans=SPFA(sx, sy, (1<<id)-1);

	if (ans==inf) puts("-1");
	else printf("%d\n", ans);

	return 0;
}
