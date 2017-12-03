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

struct hash *hashTable = NULL;
// int eleCount = 0;

int hash_func(char *key, int key_len)
{
    int i;

    i = 0;
    if (key_len == 2)
        while (key_len--)
        {
            i = i + (int)key[key_len];
        }
    else
        while (key_len--)
        {
            i = i + ((int)key[key_len] * key_len);
        }
    i = i % 100;
    return (i);
}

struct node * createNode(char *key, char *value)
{
    struct node     *newnode;

    if (!(newnode = (struct node *)malloc(sizeof(struct node))))
        return (NULL);
    ft_strcpy(newnode->key, key);
    ft_strcpy(newnode->value, value);
    newnode->next = NULL;
    return (newnode);
}

void    insertToHash(char *key, char *value, int key_len)
{
    int hashIndex = hash_func(key, key_len);
    struct node *newnode = createNode(key, value);
    /* head of list for the bucket with index "hashIndex" */
    if (!hashTable[hashIndex].head)
    {
        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count = 1;
        return ;
    }
    /* adding new node to the list */
    newnode->next = (hashTable[hashIndex].head);
    /*
     * update the head of the list and no of
     * nodes in the current bucket
     */
    hashTable[hashIndex].head = newnode;
    hashTable[hashIndex].count++;
    return ;
}

void     searchInHash(char *key, int key_len) 
{
    int hashIndex = hash_func(key, key_len);
    int flag = 0;
    struct node *myNode;

    myNode = hashTable[hashIndex].head;
    if (!myNode)
    {
        printf("keyword-search Not found.\n");
        return ;
    }
    while (myNode != NULL)
    {
        if (myNode->key == key)
        {
            printf("%s\n", myNode->key);
            printf("%s\n", myNode->value);
            flag = 1;
            break ;
        }
        myNode = myNode->next;
    }
    if (!flag)
        printf("keyword-search Not found.\n");
    return ;
}

void     display() 
{
    struct node *myNode;
    int i;
    for (i = 0; i < hashTable->count; i++) {
        if (hashTable[i].count == 0)
            continue ;
        myNode = hashTable[i].head;
        if (!myNode)
            continue ;
        printf("\nData at index %d in Hash Table:\n", i);
        printf("--------------------------------\n");
        while (myNode != NULL) {
            printf("%-12s", myNode->key);
            printf("%-15s", myNode->value);
            myNode = myNode->next;
        }
    }
    return ;
}

int main(void)
{
    char *key;
    char *value;
    int lenk;
    int lenv;
    // t_base *base;

    // base = (t_base *)malloc(sizeof(t_base) * BASE_SIZE);
    hashTable = (struct hash *) calloc(100, sizeof(struct hash));
    while (get_line(0, &key, &lenk) & (lenk != 1) && get_line(0, &value, &lenv))
    {
        insertToHash(key, value, lenk);
    }
    display();
    if (lenk == 1)
    {
        // searchInHash(key, lenk);
        // search(base, hash_func(key, lenk), key, lenk);
        display();
        while (get_line(0, &key, &lenk) && lenk != 1)
            searchInHash(key, lenk);
        if (lenk != 1)
            searchInHash(key, lenk);
    }

    return (0);
}