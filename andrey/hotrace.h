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

# define STR_SIZE 32
// # define BASE_SIZE 100

struct node 
{
    char             key[100];
    char             value[100];
    // int                key_len;
    // int                val_len;
    struct node *next;
};
 
struct hash 
{
    struct node     *head;
    int             count;
};

int     get_line(const int fd, char **dest, int *len);
void    *ft_memalloc(size_t size);
void    *ft_memcpy(void *dst, const void *src, size_t n);
char    *ft_strcpy(char *dst, const char *src);
int     hash_func(char *key, int key_len);
struct     node * createNode(char *key, char *value);
void    insertToHash(char *key, char *value, int key_len);
void     searchInHash(char *key, int key_len);

#endif
