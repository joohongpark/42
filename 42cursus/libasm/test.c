/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:21:08 by joopark           #+#    #+#             */
/*   Updated: 2021/01/18 22:28:22 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <stdio.h>
#include <string.h>
#include <sys/errno.h>

void		strlen_test(void);
void		strcpy_test(void);
void		strcmp_test(void);
void		write_test(void);
void		read_test(void);

int main (void)
{
	strlen_test();
	strcpy_test();
	strcmp_test();
	write_test();
	read_test();
	return (0);
}

void		strlen_test(void)
{
	printf("strlen test\n");
	if (ft_strlen("1234sdfsdf") != strlen("1234sdfsdf"))
		printf("error at strlen #1\n");
	if (ft_strlen("asdf\0asdf") != strlen("asdf\0asdf"))
		printf("error at strlen #2\n");
	if (ft_strlen("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") != strlen("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"))
		printf("error at strlen #3\n");
}

void		strcpy_test(void)
{
	char	buf_ft_strcpy[1000];
	char	buf_strcpy[1000];
	printf("strcpy test\n");
	if (*ft_strcpy(buf_ft_strcpy, "1234sdfsdf") != *strcpy(buf_strcpy, "1234sdfsdf"))
		printf("error at strcpy #1\n");
	printf("ft_strcpy\t: [%s]\n", buf_ft_strcpy);
	printf("strcpy\t\t: [%s]\n", buf_strcpy);
	if (*ft_strcpy(buf_ft_strcpy, "asdf\0asdf") != *strcpy(buf_strcpy, "asdf\0asdf"))
		printf("error at strcpy #2\n");
	printf("ft_strcpy\t: [%s]\n", buf_ft_strcpy);
	printf("strcpy\t\t: [%s]\n", buf_strcpy);
}

void		strcmp_test(void)
{
	printf("strcmp test\n");
	if (ft_strcmp("equal", "equal") != strcmp("equal", "equal"))
		printf("error at strcmp #1\n");
	if (ft_strcmp("not equal", "n0t equal") != strcmp("not equal", "n0t equal"))
		printf("error at strcmp #2\n");
	if (ft_strcmp("", "") != strcmp("", ""))
		printf("error at strcmp #3\n");
	if (ft_strcmp("hello!", "hello.") != strcmp("hello!", "hello."))
		printf("error at strcmp #4\n");
	if (ft_strcmp("hello.", "hello!") != strcmp("hello.", "hello!"))
		printf("error at strcmp #5\n");
	if (ft_strcmp("he\0llo.", "hello!") != strcmp("he\0llo.", "hello!"))
		printf("error at strcmp #6\n");
}

void		write_test(void)
{
	long	rtn;
	printf("write test\n");
	write(1, "print string by write\n", strlen("print string by write\n"));
	ft_write(1, "print string by write\n", strlen("print string by write\n"));
	rtn = ft_write(-1, "hi", 2);
	printf("[ft_write error test]errno : %d\n", errno);
	errno = 0;
	rtn = write(-1, "hi", 2);
	printf("[write error test]errno : %d\n", errno);
}

void		read_test(void)
{
	char	buf_ft_read[1000] = {0, };
	char	buf_read[1000] = {0, };
	long	rtn;
	printf("read test\n");
	read(0, buf_read, 1000);
	printf("[read]\n%s\n", buf_read);
	ft_read(0, buf_ft_read, 1000);
	printf("[ft_read]\n%s\n", buf_ft_read);
	rtn = read(-1, buf_read, 1000);
	printf("[read error test]errno : %d\n", errno);
	errno = 0;
	rtn = ft_read(-1, buf_ft_read, 1000);
	printf("[ft_read error test]errno : %d\n", errno);
}