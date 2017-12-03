/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlikhotk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 12:34:36 by vlikhotk          #+#    #+#             */
/*   Updated: 2017/12/03 17:06:29 by vlikhotk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define STR_SIZE 100
# define BASE_SIZE 101

typedef struct	s_base
{
	unsigned char	*key;
	unsigned char	*value;
	int				len;
	struct s_base	*next;
}				t_base;

int				get_line(const int fd, unsigned char **dest, int *len);
void			*ft_memalloc(size_t size);
void			*ft_memcpy(void *dst, const void *src, size_t n);
unsigned char	*ft_strcpy(unsigned char *dst, unsigned char *src);
int				ft_strcmp(unsigned char *s1, unsigned char *s2);
int				ft_strlen(unsigned char *s);

#endif
