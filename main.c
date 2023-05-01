/*
 * Copyright (c) 2022 Pham Ngoc Dung (tch69)
 * SPDX-License-Identifier: MIT
 */

#include <sys/utsname.h>

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "extern.h"

int
main()
{
	struct utsname os;
	char hostname[HOST_NAME_MAX + 1];
	int i, j;

	uname(&os);
	gethostname(hostname, sizeof(hostname));

	char *infvar[] 	= { os.sysname, os.release, getenv("SHELL"),
				getenv("TERM"), getuptime() };
	char *inftext[]	= { "OS/System:  ", "Kernel:     ",
				"Shell:      ", "Terminal:   ", "Uptime:     " };
	char *fgcodes[] = { "4", "10" };

	printf("\n  %s--->%s     %s%s%s@%s%s%s\n", C_MAGENTA, C_RESET, C_GREEN,
			getlogin(), C_YELLOW, C_RED, strtok(hostname, "."), C_RESET);
	printf("  %s%s>%s\n\n", C_MAGENTA, strloop("-", 32), C_RESET);

	for (i = 0; i < sizeof(infvar)/sizeof(infvar[0]); i++)
		printf("     %s->%s %s%s%s %s\n", C_CYAN, C_RESET, C_BLUE,
			inftext[i],  C_RESET, infvar[i]);

	printf("\n");

	for (i = 0; i < 2; i++) {
		printf("  %s--->%s  ", C_CYAN, C_RESET);
		for (j = 0; j < 8; j++)
			printf("\033[1;%s%dm   ", fgcodes[i], j);
		printf("%s\n", C_RESET);
	}

	printf("\n");
}
