#include <stdio.h>
#include <stdlib.h>

char		*gnl_simple(FILE *file)
{
	char	c; // 버퍼
	char	*rtn; // 리턴할 문자열
	int		len; // 리턴할 문자열 길이

	len = 0;
	rtn = NULL;
	while (1)
	{
		if (fread(&c, 1, 1, file) != 1)
			break;
		if (c == '\n' || c == '\0')
			break;
		if (!(rtn = realloc(rtn, len++)))
			return (NULL);
		rtn[len - 1] = c;
	}
	return (rtn);
}

int			main(int argc, char *argv[])
{
	FILE	*file; // 파일에 대한 정보를 담기 위한 구조체 포인터
	char	*line;

	if (!(file = fopen("cmd1", "r"))) // 파일을 열지 못하면 NULL포인터가 반환됨.
		return (1);
	while ((line = gnl_simple(file)))
	{
		printf("line : [%s]\n", line);
	}
	if (fclose(file) != 0)
		return (1);
	return (0);
}