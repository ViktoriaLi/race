/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlikhotk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 12:31:39 by vlikhotk          #+#    #+#             */
/*   Updated: 2017/12/02 12:31:43 by vlikhotk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void search(t_base *base, int i, char *key, int j)
{
	if (base[i].key)
	{
		write(1, base[i].value, (int)base[i].len - 1);
		write(1, "\n", 1);
	}
	if (!base[i].key)
	{
		write(1, key, j);
		write(1, " Not found.\n", 12);
	}
}

int hash_func(char *string, int length)
{
	int i;

	i = 0;
	if (length == 2)
		while (length--)
		{
			i = i + (int)string[length];
		}
	else
		while (length--)
		{
			i = i + ((int)string[length] * length);
		}
	i = i % 100;
	return (i);
}

t_base *data_base(t_base *base, char *key, int lenk, char *value, int lenv)
{
	int i;

	i = hash_func(key, lenk);
	base[i].key = ft_memalloc(lenk);
	base[i].key = key;
	base[i].value = ft_memalloc(lenv);
	base[i].value = value;
	base[i].len = lenv;
	return(base);
}

int main(void)
{
	char *key;
	char *value;
	int lenk;
	int lenv;
	t_base *base;

	base = (t_base *)malloc(sizeof(t_base) * BASE_SIZE);
	while (get_line(0, &key, &lenk) && get_line(0, &value, &lenv) && lenk != 1)
		data_base(base, key, lenk, value, lenv);
	if (lenk == 1)
	{
		key = value;
		lenk = lenv;
		search(base, hash_func(key, lenk), key, lenk);
		while (get_line(0, &key, &lenk))
			search(base, hash_func(key, lenk), key, lenk);
	}

}