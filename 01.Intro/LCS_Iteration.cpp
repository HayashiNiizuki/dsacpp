#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
string a, b;
int p[100][100];
int LCS1(int n, int m){
    //p[100][100] = { 0 };
    memset(p, 0, 100);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
        if (a[i-1] == b[j-1])
            p[i][j] = p[i - 1][j - 1] + 1;
        else p[i][j] = max(p[i - 1][j], p[i][j - 1]);
    }
    return p[n][m];
}
void LCS(int n, int m){
    char c[100];
    int k = 0;
    //p[100][100] = { 0 };
    memset(p, 0, 100);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
        if (a[i - 1] == b[j - 1])
            p[i][j] = p[i - 1][j - 1] + 1;
        else p[i][j] = max(p[i - 1][j], p[i][j - 1]);
    }
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
        if (p[i][j] == p[i - 1][j] + 1 && p[i][j] == p[i][j - 1] + 1)
        {
            c[k++] = a[i - 1]; break;
        }
    }
    c[k] = '\0';
    cout << c << endl;
}
int main(){
    cin >> a >> b;
    cout << LCS1(a.length(), b.length()) << endl;//数组从0开始
    LCS(a.length(), b.length());
    return 0;
}
