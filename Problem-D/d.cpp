#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define N 2010
#define MOD 1000000007
int n, f[N][N][2];
bool book[N][N];
void cmax(int &x, int y) { x = max(x, y); }
int main()
{
    scanf("%d", &n);
    book[n + n][0] = true;
    for (int i = n + n - 1; ~i; --i)
    {
        f[i][0][0] = max(f[i + 1][1][1] + book[i + 1][1], f[i + 1][1][0]);
        f[i][0][1] = f[i + 1][1][0];
        book[i][0] = !(i & 1);
        for (int j = 1; j <= i; ++j)
        {
            book[i][j] = book[i + 1][j + 1] | book[i + 1][j - 1];
            f[i][j][1] = f[i + 1][j + 1][0] + f[i + 1][j - 1][0];
            f[i][j][0] = f[i][j][1] + max(0, max(f[i + 1][j + 1][1] + book[i + 1][j + 1] - f[i + 1][j + 1][0], f[i + 1][j - 1][1] + book[i + 1][j - 1] - f[i + 1][j - 1][0]));
            f[i][j][1] = (f[i][j][1] % MOD + MOD) % MOD;
            f[i][j][0] = (f[i][j][0] % MOD + MOD) % MOD;
        }
    }
    printf("%d\n", f[0][0][1]);
    return 0;
}