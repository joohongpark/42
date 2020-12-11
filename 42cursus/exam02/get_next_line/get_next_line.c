#include "get_next_line.h"

void		ft_strcpy(char *a, char *b)
{
	while (*b != '\0')
	{
		*a = *b;
		a++;
		b++;
	}
	*a = *b;
}

int			ft_strlen(char *str)
{
	int		rtn;

	rtn = 0;
	while (str[rtn] != '\0')
		rtn++;
	return (rtn);
}

int			ft_findchar(char *str, char c)
{
	int		rtn;

	rtn = 0;
	while (*str != '\0' && *str != c)
	{
		str++;
		rtn++;
	}
	if (*str == '\0')
		return (-1);
	else
		return (rtn);
}

char		*ft_stradd(char *a, char *b)
{
	char	*rtn;

	if (a == NULL)
	{
		if (!(rtn = (char *)malloc(sizeof(char) * (ft_strlen(b) + 1))))
			return (NULL);
		ft_strcpy(rtn, b);
	}
	else
	{
		if (!(rtn = (char *)malloc(sizeof(char) * (ft_strlen(a) + ft_strlen(b) + 1))))
			return (NULL);
		ft_strcpy(rtn, a);
		ft_strcpy((rtn + ft_strlen(a)), b);
		free(a);
	}
	return (rtn);
}

int get_next_line(char **line)
{
	static char buf[BUFSIZE + 1] = {0, }; // 정적 변수 버퍼
	int			r;
	int			pos;
	char		*rtn;

	rtn = NULL; // 인수로 반환하기 전에 리턴할 문자열 임시 저장 공간
	r = 1; // 초기 진입조건을 만들기 위해 1로 초기화 시킴
	while (r > 0)
	{
		if (ft_strlen(buf) == 0) // 만약에 버퍼가 비었으면?
		{
			r = read(0, buf, BUFSIZE); // 버퍼 사이즈만큼 읽어서 가져온다.
			if (r == -1) // 읽기 오류
			{
				return (-1);
			}
			else if (r == 0 && rtn != NULL) // 읽어올 값이 없고 리턴 문자열이 존재하면
			{
				*line = rtn; // 마지막 라인 리턴
				return (0);
			}
			else if (r != BUFSIZE)
			{
				buf[r] = '\0';
			}
		}
		else // 버퍼가 비어있지 않으면?
		{
			pos = ft_findchar(buf, '\n'); // 버퍼 내에서 개행 위치를 찾음
			if (pos == -1) // 개행이 없으면
			{
				rtn = ft_stradd(rtn, buf); // 반환할 문자열에 현재 버퍼에 있는 문자열을 합침
				buf[0] = '\0'; // 버퍼 비움 (루프 처음으로 돌아감)
			}
			else // 개행이 있으면
			{
				buf[pos] = '\0'; // 개행을 널로 바꿔서 앞의 문자열이 구분되게 만듬
				rtn = ft_stradd(rtn, buf); // 문자열 합침
				ft_strcpy(buf, &buf[pos + 1]); // 뒤에 있는 문자열을 앞으로 당김
				*line = rtn; // 문자열 반환
				return (1);
			}
		}
	}
	return (0);
}