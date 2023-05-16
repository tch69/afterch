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

#include <sys/utsname.h>

#include <stdio.h>
#include <stdlib.h>

#include "extern.h"

void
*getsys()
{
	struct utsname sys;
	uname(&sys);

#ifdef __linux__
	FILE *f = fopen("/etc/os-release", "r");

	if (f != NULL) {
		char buf[32];
		char *l = NULL;
		size_t strlen;

		while (getline(&l, &strlen, f) != -1)
			if (sscanf(l, "ID=%[^\\0\n]+", buf)) break;

		free(l);
		iprint("OS/System:  ", buf);
	}

	fclose(f);
#else
	iprint("OS/System:  ", sys.sysname);
#endif
	iprint("Kernel:     ", sys.release);

	return 0;
}

