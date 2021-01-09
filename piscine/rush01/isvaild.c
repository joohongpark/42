/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvaild.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 10:48:19 by joopark           #+#    #+#             */
/*   Updated: 2020/08/09 11:56:23 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			check_colup(char **arr, char *clue, int size)
{
	int		i;
	int		j;
	char	cnt;
	char	max;

	i = 0;
	while (i < size)
	{
		j = 0;
		cnt = 0;
		max = 0;
		while (j < size)
		{
			if (arr[j][i] > max)
			{
				cnt++;
				max = arr[j][i];
			}
			j++;
		}
		if ((cnt + '0') != clue[i])
			return (0);
		i++;
	}
	return (1);
}

int			check_coldown(char **arr, char *clue, int size)
{
	int		i;
	int		j;
	char	cnt;
	char	max;

	i = 0;
	while (i < size)
	{
		j = size - 1;
		cnt = 0;
		max = 0;
		while (j >= 0)
		{
			if (arr[j][i] > max)
			{
				cnt++;
				max = arr[j][i];
			}
			j--;
		}
		if ((cnt + '0') != clue[i])
			return (0);
		i++;
	}
	return (1);
}

int			check_rowleft(char **arr, char *clue, int size)
{
	int		i;
	int		j;
	char	cnt;
	char	max;

	i = 0;
	while (i < size)
	{
		j = 0;
		cnt = 0;
		max = 0;
		while (j < size)
		{
			if (arr[i][j] > max)
			{
				cnt++;
				max = arr[i][j];
			}
			j++;
		}
		if ((cnt + '0') != clue[i])
			return (0);
		i++;
	}
	return (1);
}

int			check_rowright(char **arr, char *clue, int size)
{
	int		i;
	int		j;
	char	cnt;
	char	max;

	i = 0;
	while (i < size)
	{
		j = size - 1;
		cnt = 0;
		max = 0;
		while (j >= 0)
		{
			if (arr[i][j] > max)
			{
				cnt++;
				max = arr[i][j];
			}
			j--;
		}
		if ((cnt + '0') != clue[i])
			return (0);
		i++;
	}
	return (1);
}

int			iscorrect(char **arr, char **clue, int size)
{
	int		a;
	int		b;
	int		c;
	int		d;

	a = check_colup(arr, clue[0], size);
	b = check_coldown(arr, clue[1], size);
	c = check_rowleft(arr, clue[2], size);
	d = check_rowright(arr, clue[3], size);
	return (a && b && c && d);
}
