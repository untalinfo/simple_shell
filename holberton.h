#ifndef HOLBERTON
#define HOLBERTON
#define _GNU_SOURCE
#define MAX_ARG 10
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
extern char **environ;
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
char *_getenv(char *);
list_t *add_node(list_t **head, const char *str);
int _divisor(char *_path, list_t **head);
char **com_split(char *);
size_t print_list(const list_t *h);
int _strlen(const char *s);
char *_strncat(char *dest, char *src, int n);
void search_path(char **command, const list_t *h);
char *_strcpy(char *dest, char *src);
int _fork(char **token, const list_t *head);
void end_of_file(char *data);
void print_prompt(void);
void ctrlC(int sig);
int _strcmp(char *s1, char *s2);
void free_tok(char **token);
void _fork_fail(void);
void free_list(list_t *head);
char *_strdup(char *str);
char *_strchr(char *s, char c);
void free_exit(char *_path, char *data, list_t *head, char **token, char *);
void print_env(void);
char * _cd(char **, char *);

#endif
