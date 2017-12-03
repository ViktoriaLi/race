/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlikhotk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 12:31:39 by vlikhotk          #+#    #+#             */
/*   Updated: 2017/12/03 16:55:36 by vlikhotk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdio.h>

static int		search(t_base *base[], int i, unsigned char *key, int j)
{
	t_base *it;

	it = base[i];
	while (it)
	{
		if (ft_strcmp(it->key, key) == 0)
		{
			write(1, base[i]->value, (int)base[i]->len - 1);
			write(1, "\n", 1);
			return (0);
		}
		it = it->next;
	}
	if (!it)
	{
		write(1, key, j);
		write(1, " Not found.\n", 12);
	}
	return (0);
}

static int		hash_func(unsigned char *string, int length)
{
	int i;

	i = 0;
	if (length == 2)
		while (length--)
		{
			i = i + (int)string[length] * 17;
		}
	else
		while (length--)
		{
			i = i + ((int)string[length] * length);
		}
	i = i % 101;
	return (i);
}

static t_base	**data_base(t_base *base[], unsigned char *key, int lenk, unsigned char *value, int lenv)
{
	int		i;
	t_base	*new_node;

	new_node = (t_base *)malloc(sizeof(*new_node));
	i = hash_func(key, lenk);
	new_node->key = malloc(lenk);
	ft_strcpy(new_node->key, key);
	new_node->value = malloc(lenk);
	ft_strcpy(new_node->value, value);
	new_node->len = lenv;
	new_node->next = base[i];
	base[i] = new_node;
	return (base);
}

static void		init_base(t_base *base[])
{
	int i;

	i = 0;
	while (i < BASE_SIZE)
	{
		base[i] = NULL;
		i++;
	}
}

int				main(void)
{
	int				lenk;
	int				lenv;
	unsigned char	*key;
	unsigned char	*value;
	t_base			*base[BASE_SIZE];

	init_base(base);
	while (get_line(0, &key, &lenk) && lenk != 1 && get_line(0, &value, &lenv))
		data_base(base, key, lenk, value, lenv);
	if (lenk == 1)
		while (get_line(0, &key, &lenk) && lenk != 1)
			search(base, hash_func(key, lenk), key, lenk);
	if (lenk != 1)
		search(base, hash_func(key, lenk), key, lenk);
}
