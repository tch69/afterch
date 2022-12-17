
#include <sys/utsname.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "extern.h"

char
head()
{
	char hostname[HOST_NAME_MAX + 1];
	char *user = getlogin();

	gethostname(hostname, sizeof(hostname));

	printf("\n");
	printf("  %s--->%s     %s%s%s@%s%s%s\n", bc_magenta, c_reset, bc_green,
			user, bc_yellow, bc_red, hostname,c_reset);
	/*
	 * I should have done a loop for this instead
	 */
	printf("  %s--------------------------------->%s\n",
			bc_magenta, c_reset);
	printf("\n");
}

char
body()
{
	struct utsname os;
	uname(&os);

	/*
	 * Gross looking code, hopefully 10 years later
	 * I won't be laughing too much at this
	 */
	char *info[] = { os.sysname, os.release, getenv("SHELL"),
				getenv("TERM")};
	char *text[] = { "OS/System:  ", "Kernel:     ",
				"Shell:      ", "Terminal:   " };

	unsigned int i;

	for (i = 0; i < 4; i++)
		printf("     %s->%s %s%s%s %s\n", bc_cyan, c_reset, bc_blue,
			text[i],  c_reset, info[i]);

}

char
tail()
{
	/*
	 * I tried to create a second loop, but given up.
	 * I apologise for this horrible code.
	 */
	char *c[] = { "0", "1", "2", "3", "4", "5", "6", "7" };

	unsigned int i;

	printf("\n");
	printf("  %s--->%s  ", bc_cyan, c_reset);
	for (i = 0; i < 8; i++)
		printf("\033[1;4%sm   ", c[i]);
	printf("%s\n", c_reset);
	printf("  %s--->%s  ", bc_cyan, c_reset);
	for (i = 0; i < 8; i++)
		printf("\033[1;10%sm   ", c[i]);
	printf("%s\n", c_reset);
	printf("\n");
}

int
main()
{
	head();
	body();
	tail();
	return 0;
}
