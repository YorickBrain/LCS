//���������������
#include <iostream> 
using namespace std;

void output(char *s, int n);
void LCSLength(int m, int n, char *x, char *y, int **c, int **b);
void LCS(int i, int j, char *x, int **b);

int main()
{
	//X={A,B,C,B,D,A,B}
	//Y={B,D,C,A,B,A}
	char x[] = { ' ', 'A', 'B', 'C', 'B', 'D', 'A', 'B','A' };	//��1ȡֵ�Ƚ������У����Դ�1�洢������0��ʼ�洢�����޸�����Ƚϵ���ʼλ��
	char y[] = {  ' ','B', 'D', 'C', 'A', 'B', 'A' };

	const int M = 8;
	const int N = 6;

	int **c = new int *[M + 1];
	int **b = new int *[M + 1];		//b����ֻ��һ����ǣ������г�LCS��ʱ�ж�c[i,j]�����������ϣ��ϣ������������ĸ�����������
	for (int i = 0; i <= M; i++)
	{
		c[i] = new int[N + 1];
		b[i] = new int[N + 1];
	}

	cout << "����X��" << endl;
	output(x, M);
	cout << "����Y��" << endl;
	output(y, N);

	LCSLength(M, N, x, y, c, b);

	cout << "����X��Y����������г���Ϊ��" << c[M][N] << endl;
	cout << "����X��Y�����������Ϊ��" << endl;
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

void LCSLength(int m, int n, char *x, char *y, int **c, int **b)// ��ǰ��󣬶�̬�滮�������������⡣Ҳ�ɴӺ���ǰ
{
	int i, j;

	for (i = 1; i <= m; i++)	//����ֻҪ��һ��Ϊ�մ�ʱ�����������Ϊ�մ���������ѭ�����
		c[i][0] = 0;
	for (i = 0; i <= n; i++)
		c[0][i] = 0;

	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (x[i] == y[j])		//���x��y�������ж��Ǵ�λ��1��ʼ�洢�Ļ���Ƚ�x[i]��y[j]�������0��ʼ�洢�Ļ�����˴���Ϊx[i-1]��y[j-1]����ʹ�ַ���Ӧ�����������
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

void LCS(int i, int j, char *x, int **b)	//�����ǵݹ�ģ���������ĳ���ݹ������λ��֮ǰ������LCSǰ��Ļ������
{
	if (i == 0 || j == 0)
	{
		return;
	}
	if (b[i][j] == 1)
	{
		LCS(i - 1, j - 1, x, b);
		cout << x[i] << " ";				//���±��0��ʼ����Ҳ��Ҫ��
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