#include "shell.h"

/**
 * _strcmp - comparison of two strings.
 * @s1: the first string
 * @s2: the second string
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	if (s1 != NULL)
	{
		_strcmp(s1, s2);
	}
	else 
{
    /* handle the case where s1 is NULL  */

    printf("Error: s1 is null\n");
}
}
/*	while (s1[i] && s2[i] && s1[i] == s2[i]) */
/*		i++; */
/*	return (s1[i] - s2[i]);
}
*/

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	if (!s)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*needle != *haystack)
			return (NULL);
		needle++;
		haystack++;
	}
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, const char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';

	return (ret);
}
