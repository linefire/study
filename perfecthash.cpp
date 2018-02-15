//Студент Групи К-29 Михед Олександр Михайлович
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_MUL 31
#define HASH_SIZE 11

unsigned int hash(char * s)
{
	unsigned int h = 0;
	char *p;
	for (p = s; *p != '\0'; p++)
	{
		h = h*HASH_MUL + (unsigned int)*p;
	}
	return h % HASH_SIZE;
}

struct listnode
{
	char* key;
	int value;
	struct listnode *next;
};

struct listnode *hashtab[HASH_SIZE];

int hashtab_hash(char *key)
{
	int h = 0;
	char *p;
	for (p = key; *p != '\0'; p++)
	{
		h = h*HASH_MUL + (int)*p;
	}
	return h % HASH_SIZE;
}
void hashtab_init(struct listnode **hashtab)
{
	int i;
	for (i = 0; i < HASH_SIZE; i++)
	{
		hashtab[i] = NULL;
	}
}
void hashtab_add(struct listnode **hashtab, char *key, int value)
{
	struct listnode * node;
	int index = hashtab_hash(key);
	node = (listnode *)malloc(sizeof(*node));
	if (node != NULL)
	{
		node->key = key;
		node->value = value;
		node->next = hashtab[index];
		hashtab[index] = node;
	}
}
struct listnode *hashtab_lookup(struct listnode **hashtab, char *key)
{
	int index;
	index = hashtab_hash(key);
	struct listnode * node;
	for (node = hashtab[index]; node != NULL; node = node->next)
	{
		if (strcmp(node->key, key) == 0)
		{
			return node;
		}
	}
	return NULL;
}

int main()
{
	struct listnode * node;
	hashtab_init(hashtab);
	hashtab_add(hashtab, "Hello1", 1);
	hashtab_add(hashtab, "Hello2", 2);
	hashtab_add(hashtab, "Hello3", 3);
	hashtab_add(hashtab, "Hello4", 4);
	hashtab_add(hashtab, "Hello5", 5);
	hashtab_add(hashtab, "Hello6", 6);
	hashtab_add(hashtab, "Hello7", 7);
	hashtab_add(hashtab, "Hello8", 8);
	hashtab_add(hashtab, "Hello9", 9);
	hashtab_add(hashtab, "Hello1", 10);
	hashtab_add(hashtab, "Hello2", 12);

	node = hashtab_lookup(hashtab, "Hello3");
	printf("Node: %s, %d\n", node->key, node->value);
	int s;
	scanf_s("%i", &s);
	return 0;
}
