#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

int			print_error(char *errormsg)
{
	int		len;

	len = 0;
	while (errormsg[len] != '\0')
		len++;
	write(1, errormsg, len);
	return (1);
}

int			main(int argc, char *argv[])
{
	FILE	*file; // 파일에 대한 정보를 담기 위한 구조체 포인터
	char	*canvas; // 출력되는 배열
	int		w;
	int		h;
	char	c;
	float	x;
	float	y;
	float	r;
	char	f;
	float	rp;
	int		e;

	if ((argc != 2) || !(file = fopen(argv[1], "r"))) // 파일을 열지 못하면 NULL포인터가 반환됨.
		return (print_error("Error: argument\n"));
	if (fscanf(file, "%d %d %c\n", &w, &h, &c) != 3)
		return (print_error("Error: Operation file corrupted\n"));
	if (!(w > 0 && w <= 300) || !(h > 0 && h <= 300))
		return (print_error("Error: Operation file corrupted\n"));
	if (!(canvas = malloc(sizeof(char) * w * h)))
		return (1);
	memset(canvas, c, w * h);

	while ((e = fscanf(file, "%c %f %f %f %c\n", &c, &x, &y, &r, &f)))
	{
		if (e > 0 && e < 5)
			return (print_error("Error: Operation file corrupted\n"));
		else if (e == -1)
			break;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				rp =  sqrtf((powf(y - i, 2.0) + powf(x - j, 2.0)));
				if (rp <= r)
				{
					if (c == 'C')
						canvas[i * w + j] = f;
					else if (c == 'c' && r - rp < 1.0)
						canvas[i * w + j] = f;
					else if (c != 'c' && c != 'C')
						return (print_error("Error: Operation file corrupted\n"));
				}
			}
		}
	}
	for (int i = 0; i < h; i++)
	{
		write(1, &canvas[i * w], w);
		write(1, "\n", 1);
	}
	free(canvas);
	if (fclose(file) != 0)
		return (1);
	return (0);
}