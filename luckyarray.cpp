#include <iostream>
using namespace std;

int n, m;
int a[100005];
int lucky[10005];
int C[100005];

bool check(int n)
{
    while (n)
    {
        if (n % 10 != 4 && n % 10 != 7) return 0;
        n /= 10;
    }
    return 1;
}

void add(int pos, int t)
{
    while (pos <= n)
    {
        C[pos] += t;
        pos += (pos & (-pos));
    }
}

int sum(int pos)
{
    int ret = 0;
    while (pos > 0)
    {
        ret += C[pos];
        pos -= (pos & (-pos));
    }
    return ret;
}

int main()
{
    for(int i = 1; i <= 10000; i++)
    {
        if (check(i))
            lucky[i] = 1;
    }
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (lucky[a[i]])
            add(i, 1);
    }
    for(int i = 0; i < m; i++)
    {
        string ope;
        int l, r;
        cin >> ope >> l >> r;
        if (ope == "add")
        {
            int k;
            cin >> k;
            for(int j = l; j <= r; j++)
            {
                int t = lucky[a[j]] ? -1 : 0;
                a[j] += k;
                if (lucky[a[j]]) t++;
                if (t != 0) add(j, t);
            }
        }
        else
            cout << sum(r) - sum(l - 1) << endl;
    }

    return 0;
}

 						 	 	 	 			   		   	
