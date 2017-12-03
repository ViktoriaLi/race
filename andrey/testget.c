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

static void		to_end(unsigned char *buf, int i, unsigned char **dest,
	int *len)
{
	buf[i - 1] = 0;
	*dest = ft_memalloc(i);
	ft_memcpy(*dest, buf, i);
	*len = i;
	free(buf);
}

int				get_line(const int fd, unsigned char **dest, int *len)
{
	int				i;
	int				ret;
	int				k;
	unsigned char	*buf;
	unsigned char	*tmp;

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
		ret = read(fd, &buf[i++], 1);
	}
	to_end(buf, i, dest, len);
	return (ret);
}
