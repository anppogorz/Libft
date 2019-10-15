#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../libft/libft.h"

// gcc test.c ../libft/ft_memset.c ../libft/ft_strdup.c ../libft/ft_strncmp.c ../libft/ft_isdigit.c ../libft/ft_strlcpy.c ../libft/ft_strlcat.c ../libft/ft_strnstr.c ../libft/ft_atoi.c ../libft/ft_bzero.c ../libft/ft_memcpy.c ../libft/ft_memccpy.c ../libft/ft_memmove.c ../libft/ft_memchr.c ../libft/ft_memcmp.c ../libft/ft_strlen.c ../libft/ft_strchr.c ../libft/ft_strrchr.c

void test_memset(char *s, int c, int len);
void test_bzero(void *s, size_t n);
void test_memcpy(void *dst, const void *src, size_t n);
void test_memccpy(void *dst, const void *src, int c, size_t n);
void test_memmove(void *dst, const void *src, size_t len);
void test_memchr(const void *s, int c, size_t n);
void test_memcmp(const void *s1, const void *s2, size_t n);
void test_strlen(const char *s);
void test_strchr(const char *s, int c);
void test_strrchr(const char *s, int c);
void test_strncmp(const char *s1, const char *s2, size_t n);
void test_strlcpy(char *dst, const	char *src, size_t size);
void test_strlcat(char *dst, const char *src, size_t size);
void test_strnstr(const char *haystack, const char *needle, size_t len);
void test_atoi(const char *str);
void test_strdup(const char *str);

int main(void)
{
	printf("Testing memset...\n");
	test_memset(NULL, 0, 0);
	test_memset(NULL, 0, 1000);
	test_memset(NULL, 0, -1);
	printf("Testing bzero...\n");
	test_bzero(NULL, 0);
	test_bzero(NULL, 100);
	test_bzero(NULL, -1);
	printf("Testing memcpy...\n");
	test_memcpy(NULL, NULL, 0);
	test_memcpy(NULL, NULL, 100);
	test_memcpy(NULL, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	printf("Testing memccpy...\n");
	test_memccpy(NULL, NULL, 0, 0);
	test_memccpy(NULL, NULL, 0, 100);
	test_memccpy(NULL, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0, 10);
	printf("Testing memmove...\n");
	test_memmove(NULL, NULL, 0);
	test_memmove(NULL, NULL, 100);
	test_memmove(NULL, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	printf("Testing memchr...\n");
	test_memchr(NULL, 0, 0);
	test_memchr(NULL, 0, 100);
	printf("Testing memcmp...\n");
	test_memcmp(NULL, NULL, 0);
	test_memcmp(NULL, NULL, 100);
	test_memcmp(NULL, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 100);
	printf("Testing strlen...\n");
	test_strlen(NULL);
	test_strlen("\0");
	printf("Testing strchr...\n");
	test_strchr(NULL, 0);
	test_strchr(NULL, '\n');
	printf("Testing strnchr...\n");
	test_strrchr(NULL, 0);
	test_strrchr(NULL, '\n');
	printf("Testing strncmp...\n");
	test_strncmp(NULL, NULL, 0);
	test_strncmp(NULL, NULL, 100);
	test_strncmp(NULL, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	printf("Testing strlcpy...\n");
	test_strlcpy(NULL, NULL, 0);
	test_strlcpy(NULL, NULL, 100);
	test_strlcpy(NULL, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	printf("Testing strlcat...\n");
	test_strlcat(NULL, NULL, 0);
	test_strlcat(NULL, NULL, 100);
	test_strlcat(NULL, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	printf("Testing strnstr...\n");
	test_strnstr(NULL, NULL, 0);
	test_strnstr(NULL, NULL, 100);
	test_strnstr(NULL, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	printf("Testing atoi...\n");
	test_atoi(NULL);
	printf("Testing strdup...\n");
	test_strdup(NULL);
	return (0);
}

void test_strdup(const char *str)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		strdup(str);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_strdup(str);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\t\033[31m[KO]\033[0m ft_strdup need to crash with (%s).\n", str);
			else if (!org_crash && new_crash)
				printf("\t\033[31m[KO]\033[0m ft_strdup is crashing with (%s).\n", str);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
		}
	}
}

void test_atoi(const char *str)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		atoi(str);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_atoi(str);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\t\033[31m[KO]\033[0m ft_atoi need to crash with (%s).\n", str);
			else if (!org_crash && new_crash)
				printf("\t\033[31m[KO]\033[0m ft_atoi is crashing with (%s).\n", str);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
		}
	}
}

void test_strnstr(const char *haystack, const char *needle, size_t len)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		strnstr(haystack, needle, len);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_strnstr(haystack, needle, len);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\t\033[31m[KO]\033[0m ft_strnstr need to crash with (%s %s %zu).\n", haystack, needle, len);
			else if (!org_crash && new_crash)
				printf("\t\033[31m[KO]\033[0m ft_strnstr is crashing with (%s %s %zu).\n", haystack, needle, len);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
		}
	}
}

void test_strlcat(char *dst, const	char *src, size_t size)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		strlcat(dst, src, size);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_strlcat(dst, src, size);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\t\033[31m[KO]\033[0m ft_strlcat need to crash with (%s %s %zu).\n", dst, src, size);
			else if (!org_crash && new_crash)
				printf("\t\033[31m[KO]\033[0m ft_strlcat is crashing with (%s %s %zu).\n", dst, src, size);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
		}
	}
}

void test_strlcpy(char *dst, const	char *src, size_t size)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		strlcpy(dst, src, size);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_strlcpy(dst, src, size);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\t\033[31m[KO]\033[0m ft_strlcpy need to crash with (%s %s %zu).\n", dst, src, size);
			else if (!org_crash && new_crash)
				printf("\t\033[31m[KO]\033[0m ft_strlcpy is crashing with (%s %s %zu).\n", dst, src, size);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
		}
	}
}

void test_strncmp(const char *s1, const char *s2, size_t n)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		strncmp(s1, s2, n);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_strncmp(s1, s2, n);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\t\033[31m[KO]\033[0m ft_strncmp need to crash with (%s %s %zu).\n", s1, s2, n);
			else if (!org_crash && new_crash)
				printf("\t\033[31m[KO]\033[0m ft_strncmp is crashing with (%s %s %zu).\n", s1, s2, n);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
		}
	}
}

void test_strrchr(const char *s, int c)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		strrchr(s, c);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_strrchr(s, c);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\t\033[31m[KO]\033[0m ft_strrchr need to crash with (%s).\n", s);
			else if (!org_crash && new_crash)
				printf("\t\033[31m[KO]\033[0m ft_strrchr is crashing with (%s).\n", s);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
		}
	}
}

void test_strchr(const char *s, int c)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		strchr(s, c);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_strchr(s, c);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\t\033[31m[KO]\033[0m ft_strchr need to crash with (%s).\n", s);
			else if (!org_crash && new_crash)
				printf("\t\033[31m[KO]\033[0m ft_strchr is crashing with (%s).\n", s);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
		}
	}
}

void test_strlen(const char *s)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		strlen(s);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_strlen(s);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\t\033[31m[KO]\033[0m ft_strlen need to crash with (%s).\n", s);
			else if (!org_crash && new_crash)
				printf("\t\033[31m[KO]\033[0m ft_strlen is crashing with (%s).\n", s);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
		}
	}
}

void test_memcmp(const void *s1, const void *s2, size_t n)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		memcmp(s1, s2, n);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_memcmp(s1, s2, n);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\t\033[31m[KO]\033[0m ft_memcmp need to crash with (%s, %s, %zu).\n", s1, s2, n);
			else if (!org_crash && new_crash)
				printf("\t\033[31m[KO]\033[0m ft_memcmp is crashing with (%s, %s, %zu).\n", s1, s2, n);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
		}
	}
}

void test_memchr(const void *s, int c, size_t n)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		memchr(s, c, n);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_memchr(s, c, n);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\t\033[31m[KO]\033[0m ft_memchr need to crash with (%s, %i, %zu).\n", s, c, n);
			else if (!org_crash && new_crash)
				printf("\t\033[31m[KO]\033[0m ft_memchr is crashing with (%s, %i, %zu).\n", s, c, n);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
		}
	}
}

void test_memmove(void *dst, const void *src, size_t len)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		memmove(dst, src, len);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_memmove(dst, src, len);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\t\033[31m[KO]\033[0m ft_memmove need to crash with (%s, %s, %zu).\n", dst, src, len);
			else if (!org_crash && new_crash)
				printf("\t\033[31m[KO]\033[0m ft_memmove is crashing with (%s, %s, %zu).\n", dst, src, len);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
		}
	}
}

void test_memccpy(void *dst, const void *src, int c, size_t n)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		memccpy(dst, src, c, n);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_memccpy(dst, src, c, n);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\t\033[31m[KO]\033[0m ft_memccpy need to crash with (%s, %s, %i, %zu).\n", dst, src, c, n);
			else if (!org_crash && new_crash)
				printf("\t\033[31m[KO]\033[0m ft_memccpy is crashing with (%s, %s, %i, %zu).\n", dst, src, c, n);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
		}
	}
}

void test_memcpy(void *dst, const void *src, size_t n)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		memcpy(dst, src, n);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_memcpy(dst, src, n);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\t\033[31m[KO]\033[0m ft_memcpy need to crash with (%s, %s, %zu).\n", dst, src, n);
			else if (!org_crash && new_crash)
				printf("\t\033[31m[KO]\033[0m ft_memcpy is crashing with (%s, %s, %zu).\n", dst, src, n);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
		}
	}
}

void test_memset(char *s, int c, int len)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		memset(s, c, len);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_memset(s, c, len);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\t\033[31m[KO]\033[0m ft_memset need to crash with (%s, %c, %i).\n", s, c, len);
			else if (!org_crash && new_crash)
				printf("\t\033[31m[KO]\033[0m ft_memset is crashing with (%s, %c, %i).\n", s, c, len);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
		}
	}
}

void test_bzero(void *s, size_t n)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		bzero(s, n);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_bzero(s, n);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\t\033[31m[KO]\033[0m ft_bzero need to crash with (%s, %zu).\n", s, n);
			else if (!org_crash && new_crash)
				printf("\t\033[31m[KO]\033[0m ft_bzero is crashing with (%s, %zu)\n", s, n);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m\n");
		}
	}
}

