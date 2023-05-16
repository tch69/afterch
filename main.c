/*
 * Copyright (c) 2022,2023 tch69 <ifa26417@aol.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define _MAIN_C
#include "extern.h"

char
*strloop(const char *restrict x, const int y)
{
	int i;
	char *buf = (char *) malloc(strlen(x) + y - 1);

	for (i = 0; i < y; i++) strcat(buf, x);

	free(buf);
	return buf;
}

int
main()
{
	char hostname[HOST_NAME_MAX + 1];
	gethostname(hostname, sizeof(hostname));

	printf("\n  %s--->%s     %s%s%s@%s%s%s\n", C_MAGENTA, C_RESET, C_GREEN,
			getlogin(), C_YELLOW, C_RED, strtok(hostname, "."), C_RESET);
	printf("  %s%s>%s\n", C_MAGENTA, strloop("-", 32), C_RESET);

	getsys(), getshell(), getterm(), getuptime();

	palette();
}

void
iprint(char *text, char *info)
{
	printf("\n     %s->%s %s%s%s%s", C_CYAN, C_RESET, C_BLUE,
			text,  C_RESET, info);
}

static void
palette()
{
	int i, j;
	char *fgcodes[] = { "4", "10" };

	puts("\n");

	for (i = 0; i < 2; i++) {
		printf("  %s--->%s  ", C_CYAN, C_RESET);
		for (j = 0; j < 8; j++)
			printf("\033[1;%s%dm   ", fgcodes[i], j);
		printf("%s\n", C_RESET);
	}

	puts("");
}
