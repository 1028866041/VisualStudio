#include "stdafx.h"

int app(int argc, char* argv[])
{
	int arry[3][3] = { 0 }; 
	int n = 3, l = 0, i = 0, s = 0, e, v = 2, f = 0;

	scanf_s("%d", &v);

	for (l = 0; l < n; l++)
	{
		for (i = 0; i < n; i++)
		{
			scanf_s("%d", &arry[l][i]);			
		}
	}
	getchar();
	for (l = 0; l < n; l++)
	{
		for (i = 0; i < n; i++)
		{
			printf("%d", arry[l][i]);
		}
	}

	e = n - 1;

	if (arry[0][0]<v && arry[n - 1][n - 1]>v)
	{
		for (l = 0; l < n; l++)
		{
			while (s <e && arry[l][0]<v && arry[l][n - 1]>v)
			{
				i = s + (e - s) / 2;
				if (v > arry[l][i])
				{
					s = i;
					printf("%d", 1);
				}
				else if (v < arry[l][i])
				{
					e = i;
					printf("%d", 2);
				}
				else
				{
					f = 1;
					break;
				}
			}
			if (f = 1)
				break;
		}
	}

	if (f == 1)
	{		
		return  true;
	}
	else
	{
		return  false;	
	}
}