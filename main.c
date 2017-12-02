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
#include <stdio.h>

void data_base(char *key, int lenk, char *value, int lenv, int i)
{
	printf("%s\n", key);
	printf("%d\n", lenk);
	printf("%s\n", value);
	printf("%d\n", lenv);
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

int main(void)
{
	char *key;
	char *value;
	int lenk;
	int lenv;

	while (get_line(0, &key, &lenk) && get_line(0, &value, &lenv) && lenk != 1)
	{
		data_base(key, lenk, value, lenv, hash_func(key, lenk));
		printf("%d\n", hash_func(key, lenk));
		free(key);
		free(value);
	}
	if (lenk == 1)
	{
		key = value;
		lenk = lenv;
		printf("%s%d\n", key, hash_func(key, lenk));
		free(key);
		while (get_line(0, &key, &lenk))
		{
			printf("%s%d\n", key, hash_func(key, lenk));
			free(key);
		}
	}

}