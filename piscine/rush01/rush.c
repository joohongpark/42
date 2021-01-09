/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 10:30:09 by joopark           #+#    #+#             */
/*   Updated: 2020/08/09 16:25:46 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int			isvaild(char *data);
char		**parser(char *data);
void		print(char **arr, int size);
char		**arrinit(int size);
int			iscorrect(char **arr, char **clue, int size);
void		twoarrfree(char **arr, int size);

char		**g_clue;
char		g_fin;

int			xydupchk(char **map, int x, int y, char n)
{
	int		i;

	i = 0;
	while (g_clue[0][i] != '\0')
	{
		if (map[i][y] == n || map[x][i] == n)
			return (1);
		i++;
	}
	return (0);
}

int			finchk(char **puzzle, int x, int y, int size)
{
	if (x == (size - 1) && y == size)
	{
		if (iscorrect(puzzle, g_clue, size) == 1)
		{
			if (g_fin == 0)
				print(puzzle, size);
			g_fin = 1;
		}
		return (1);
	}
	else
	{
		return (0);
	}
}

void		permute(char **puzzle, int x, int y, int size)
{
	int		i;

	if (finchk(puzzle, x, y, size) == 1)
		return ;
	x = (y == size) ? x + 1 : x;
	y = (y == size) ? 0 : y;
	if (puzzle[x][y] == '0')
	{
		i = 0;
		while (i++ < size)
		{
			if (xydupchk(puzzle, x, y, i + '0') == 0)
			{
				puzzle[x][y] = i + '0';
				permute(puzzle, x, y + 1, size);
				puzzle[x][y] = '0';
			}
		}
	}
	else
		permute(puzzle, x, y + 1, size);
}

int			main(int argc, char **argv)
{
	char	**arr;
	int		size;

	g_fin = 0;
	if (argc == 2)
	{
		g_clue = parser(argv[1]);
		if (g_clue)
		{
			size = isvaild(argv[1]);
			arr = arrinit(size);
			permute(arr, 0, 0, size);
			twoarrfree(arr, size);
			twoarrfree(g_clue, 4);
		}
	}
	if (g_fin == 0)
		write(1, "Error\n", 6);
	return (0);
}
