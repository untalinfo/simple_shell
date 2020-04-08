#ifndef HOLBERTON
#define HOLBERTON

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

list_t *add_node(list_t **head, const char *str);
int _divisor(char *_path, list_t **head);
char **com_split(char *);
size_t print_list(const list_t *h);
int _strlen(const char *s);
char *_strncat(char *dest, char *src, int n);
void search_path(char *command, const list_t *h);
char *_strcpy(char *dest, char *src);
int _fork(char **token);
void end_of_file(char *data);
void print_prompt(void);
void ctrlC(int sig);
#endif
