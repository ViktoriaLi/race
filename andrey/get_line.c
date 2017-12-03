/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlikhotk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 12:31:49 by vlikhotk          #+#    #+#             */
/*   Updated: 2017/12/02 12:32:04 by vlikhotk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int get_line(const int fd, char **dest, int *len)
{
	int i;
	int ret;
	int k;
	char *buf;
	char *res;
	char *tmp;

	i = 0;
	k = 1;
	buf = ft_memalloc(STR_SIZE);
	ret = 1;
	while (buf[i - 1] != '\n' && ret == 1)
	{
		if (i == STR_SIZE * k)
		{	
			k *= 2;
			tmp = ft_memalloc(STR_SIZE * k);
			ft_memcpy(tmp, buf, i);
			free(buf);
			buf = tmp;
		}
		ret = read(fd, &buf[i], 1);
		i++;
	}
	buf[i - 1] = 0;
	res = ft_memalloc(i);
	ft_memcpy(res, buf, i);
	*dest = res;
	*len = i;
	free(buf);
	return (ret);
}
