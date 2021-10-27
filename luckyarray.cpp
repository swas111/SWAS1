#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define lowbit(x) (x & (-x))
#define rep(i,a,b) for (int i=a;i<b;i++)
#define repp(i,a,b) for (int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int INF = 1e9 + 10;
const int MAXN = 1e5 + 5;
const int MAXM = 1e4 + 5;
const int mod = 1e9 + 7;
const double EPS = 1e-10;
 
int n, m;
int mark[MAXM], tree[MAXN], a[MAXN];

void add(int x, int y)
{
    while(x <= n){
        tree[x] += y;
        x += lowbit(x);
    }
}

int sum(int x)
{
    int tmp = 0;
    while(x > 0){
        tmp += tree[x];
        x -= lowbit(x);
    }
    return tmp;
}

void init()
{
    memset(mark, 0, sizeof mark);
    mark[4]=mark[7]=mark[44]=mark[47]=1;
    mark[74]=mark[77]=mark[444]=mark[447]=1;
    mark[474]=mark[477]=mark[744]=mark[747]=1;
    mark[774]=mark[777]=mark[4444]=mark[4447]=1;
    mark[4474]=mark[4477]=mark[4744]=mark[4747]=1;
    mark[4774]=mark[4777]=mark[7444]=mark[7447]=1;
    mark[7474]=mark[7477]=mark[7744]=mark[7747]=1;
    mark[7774]=mark[7777]=1;
}

int main()
{
    int x, y, z;
    char s[10];
    init();
    while(cin >> n >> m){
        repp(i, 0, n)
            tree[i] = 0;
        repp(i, 1, n){
            scanf("%d", a+i);
            if(mark[a[i]])
                add(i, 1);
        }
        rep(j, 0, m){
            cin >> s >> x >> y;
            if(s[0] == 'c')
                cout << sum(y) - sum(x - 1) << endl;
            else{
                cin >> z;
                if(z == 0)
                    continue;
                repp(i, x, y){
                    if(mark[a[i]])
                        add(i, -1);
                    a[i] += z;
                    if(mark[a[i]])
                        add(i, 1);
                }
            }
        }
    }
    return 0;
}

		  	 		 			 		 	   	 	 	 	 		
