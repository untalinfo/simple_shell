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
char *_getenv(char *, char **);
list_t *add_node(list_t **head, char *str);
int _divisor(char *_path, list_t **head);
char **com_split(char *);
int _strlen(const char *s);
char *_strncat(char *dest, char *src, int n);
int search_path(char **command, const list_t *h, char **);
char *_strcpy(char *dest, char *src);
int _fork(char **token, list_t *head, int, char **, int *, char **,
char *, char *, char *);
void end_of_file(char *data, int *, char *);
void print_prompt(void);
void ctrlC(int sig);
int _strcmp(char *s1, char *s2);
void free_tok(char **token);
void _fork_fail(void);
void free_list(list_t *head);
char *_strdup(char *str);
char *_strchr(char *s, char c);
void free_exit(char *_path, char *data, list_t *head,
char **token, char *, int *);
int print_env(char **);
char *_cd(char **, char *);
void mod_pwd(char *current, char **);
int exec(char **token, char *current, char *_path,
list_t *head, char *data, int, char **, int *, char**);
#endif
