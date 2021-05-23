#include "stdafx.h"

int a[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

int func3(int m, int n ,int arry[])
{
	int i = 0;
	
	for (i = 0; i < 2 * m + 2 * n - 4; i++)
	{
		if (i < m - 1)
		{
			arry[i] = a[0][i];
		}
		else if (i < m + n - 2)
		{
			arry[i] = a[i - m + 1][n - 1];
		}
		else if (i < 2 * m + n - 3){
			arry[i] = a[m - 1][2 * m + n - 3 - i];
		}
		else
		{
			arry[i] = a[2 * m + 2 * n - 4 - i][0];
		}
	}	

	return 0;
}

int app3(int argc, char* argv[])
{
	int m = 3, n = 3, m2, n2, i, j, arry[8], arryb[9] = {0};
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}

	m2 = m;
	n2 = n;
	while (m > 1 && n > 1)
	{
		func3(m, n, arry);
		j = 0;
		for (i = 0; i < 2 * m + 2 * n - 4; i++)
		{
			arryb[j] = arry[i];
			j++;
		}		
		j += 2 * m + 2 * n - 4;
		m = m - 2;
		n = n - 2;
		if (m == 1 && n == 1)
		{
			arryb[m2 * n2 - 1] = a[m2 / 2][n2 / 2];
		}
	}

	for (i = 0; i < 9; i++)
	{
		printf("%d ", arryb[i]);
	}
	return 0;
}