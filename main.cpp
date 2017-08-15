//最长公共子序列问题
#include <iostream> 
using namespace std;

void output(char *s, int n);
void LCSLength(int m, int n, char *x, char *y, int **c, int **b);
void LCS(int i, int j, char *x, int **b);

int main()
{
	//X={A,B,C,B,D,A,B}
	//Y={B,D,C,A,B,A}
	char x[] = { ' ', 'A', 'B', 'C', 'B', 'D', 'A', 'B','A' };	//从1取值比较两数列，所以从1存储，若从0开始存储，则修改下面比较的起始位置
	char y[] = {  ' ','B', 'D', 'C', 'A', 'B', 'A' };

	const int M = 8;
	const int N = 6;

	int **c = new int *[M + 1];
	int **b = new int *[M + 1];		//b数组只是一个标记，用于列出LCS串时判断c[i,j]是由其左，左上，上，三个方向中哪个子问题解决的
	for (int i = 0; i <= M; i++)
	{
		c[i] = new int[N + 1];
		b[i] = new int[N + 1];
	}

	cout << "序列X：" << endl;
	output(x, M);
	cout << "序列Y：" << endl;
	output(y, N);

	LCSLength(M, N, x, y, c, b);

	cout << "序列X、Y最长公共子序列长度为：" << c[M][N] << endl;
	cout << "序列X、Y最长公共子序列为：" << endl;
	LCS(M, N, x, b);
	cout << endl;
}

void output(char *s, int n)
{
	for (int i = 1; i <=n; i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
}

void LCSLength(int m, int n, char *x, char *y, int **c, int **b)// 从前向后，动态规划计算所有子问题。也可从后向前
{
	int i, j;

	for (i = 1; i <= m; i++)	//二者只要有一个为空串时，则最长子序列为空串，这两个循环完成
		c[i][0] = 0;
	for (i = 0; i <= n; i++)
		c[0][i] = 0;

	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (x[i] == y[j])		//如果x，y两个序列都是从位置1开始存储的话则比较x[i]与y[j]，如果从0开始存储的话，则此处改为x[i-1]与y[j-1]即可使字符对应，其他不需改
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 2;
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = 3;
			}
		}
	}
}

void LCS(int i, int j, char *x, int **b)	//这里是递归的，由于下面的程序递归在输出位置之前，所以LCS前面的会先输出
{
	if (i == 0 || j == 0)
	{
		return;
	}
	if (b[i][j] == 1)
	{
		LCS(i - 1, j - 1, x, b);
		cout << x[i] << " ";				//若下标从0开始这里也需要改
	}
	else if (b[i][j] == 2)
	{
		LCS(i - 1, j, x, b);
	}
	else
	{
		LCS(i, j - 1, x, b);
	}
}