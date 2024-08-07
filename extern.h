/*
 * Copyright (c) 2023 tch69 <ifa26417@aol.com>
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

void iprint(char *, char *);

#ifdef _MAIN_C
/*
 * Colour codes defined here are not used to display the palette;
 * we use loops instead.
 */
#define C_RESET 	"\033[0m"
#define C_RED 		"\033[1;31m"
#define C_GREEN 	"\033[1;32m"
#define C_YELLOW 	"\033[1;33m"
#define C_BLUE 		"\033[1;34m"
#define C_MAGENTA 	"\033[1;35m"
#define C_CYAN	 	"\033[1;36m"
#define C_WHITE 	"\033[1;39m"

char *strloop(const char *restrict, const int);
void getsysname(void);
void getkern(void);
void getuptime(void);
static void getshell(void) { iprint("Shell:      ", getenv("SHELL")); }
static void getterm(void) { iprint("Terminal:   ", getenv("TERM")); }
#endif
