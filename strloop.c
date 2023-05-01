/*
 * Copyright (c) 2023 Pham Ngoc Dung (tch69)
 * SPDX-License-Identifier: MIT
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char
*strloop(const char *restrict x, const int y)
{
	int i;
	char *buf = (char *) malloc(strlen(x) + y - 1);

	for (i = 0; i < y; i++) strcat(buf, x);

	free(buf);
	return buf;
}
