#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

char		**setmem(int w, int h, char c)
{
	char	**rtn;
	int		y;

	y = 0;
	rtn = malloc(sizeof(char *) * h);
	while (y < h)
	{
		rtn[y] = malloc(sizeof(char) * w);
		memset(rtn[y], c, w);
		y++;
	}
	return (rtn);
}

int			main(int argc, char *argv[])
{
	FILE	*file; // 파일에 대한 정보를 담기 위한 구조체 포인터
	char	**canvas; // 출력되는 2차원 배열
	int		w;
	int		h;
	char	c;
	float	x;
	float	y;
	float	r;
	char	f;
	float	rp;


	if (!(file = fopen("cmd1", "r"))) // 파일을 열지 못하면 NULL포인터가 반환됨.
		return (1);
	if (fscanf(file, "%d %d %c\n", &w, &h, &c) != 3)
		return (1);
	canvas = setmem(w, h, c);

	while (fscanf(file, "%c %f %f %f %c\n", &c, &x, &y, &r, &f) == 5)
	{
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				rp =  sqrtf((powf(y - i, 2.0) + powf(x - j, 2.0)));
				if (rp <= r)
				{
					if (c == 'C')
						canvas[i][j] = f;
					else if (c == 'c' && r - rp < 1.0)
						canvas[i][j] = f;
				}
			}
		}
	}
	for (int i = 0; i < h; i++)
	{
		write(1, canvas[i], w);
		write(1, "\n", 1);
	}
	if (fclose(file) != 0)
		return (1);
	return (0);
}