#include <vector>
#include <iostream>

using namespace std;
typedef vector<char> char_l;

char_l LCS(char_l A, char_l B, int m, int n,char_l Lcs) 
{
	if (m == -1 || n == -1) 
	{
		return Lcs;      //递归基
	}
	if (A[m] == B[n])	//第一种情况:A末尾和B末尾的元素相同
	{
		Lcs.push_back(A[m]);
		return LCS(A, B, m-1, n-1, Lcs);
	}
	else                //第二种情况:A末尾和B末尾的元素相同
	{
		return LCS(A, B, m, n - 1, Lcs).size() > LCS(A, B, m - 1, n, Lcs).size() ? 
			LCS(A, B, m, n - 1, Lcs) : LCS(A, B, m - 1, n, Lcs);
	}
}
int main()
{
	char a[] = "educational";	//单词太长的话会很慢很慢
	char b[] = "advantage";	
	char_l A,B,Lcs;
	for (int i = 0; i < sizeof(a)-1; i++) 
	{
		A.push_back(a[i]);
	}
	for (unsigned int i = 0; i < sizeof(b)-1; i++)
	{
		B.push_back(b[i]);
	}
	Lcs=LCS(A, B, A.size()-1, B.size()-1,Lcs);

	
	for (unsigned int i = 0; i < Lcs.size(); i++)
	{
		cout << Lcs[Lcs.size()-1-i]<<"-";
	}
	cout << endl;
}
