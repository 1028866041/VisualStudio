#include "stdafx.h"
#include <string.h>

int app4(int argc, char* argv[])
{
	char c, str[1024] = { '\0' }, str2[1024] = { '\0' };
	unsigned int i = 0, j = 0;

	while((c = getchar())!= EOF)
	{
		str[i++] = c;
		if ('\n' == c)
			break;
	}

	for (i = 0; i < strlen(str); i++)
	{
		j = strlen(str2);
		if (str[i] ==' ')
		{			
			str2[j] = '%';
			str2[j + 1] = '2';
			str2[j + 2] = '0';
			j = j + 2;
		}
		else
		{
			str2[j] = str[i];			
		}
	}
	printf("%s", str2);

	return 0;
}