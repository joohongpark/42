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

	rtn = NULL;
	r = 1;
	while (r > 0)
	{
		if (ft_strlen(buf) == 0)
		{
			r = read(0, buf, BUFSIZE);
			if (r == -1)
			{
				return (-1);
			}
			else if (r == 0 && rtn != NULL)
			{
				*line = rtn;
				return (0);
			}
			else if (r != BUFSIZE)
			{
				buf[r] = '\0';
			}
			
		}
		else
		{
			pos = ft_findchar(buf, '\n');
			if (pos == -1)
			{
				rtn = ft_stradd(rtn, buf);
				buf[0] = '\0';
			}
			else
			{
				buf[pos] = '\0';
				rtn = ft_stradd(rtn, buf);
				ft_strcpy(buf, &buf[pos + 1]);
				*line = rtn;
				return (1);
			}
		}
	}
	return (r);
}