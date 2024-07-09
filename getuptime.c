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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "extern.h"

void
getuptime(void)
{
	struct timespec time;
	time_t uptime;
	int d, h, m;

	char *buf = malloc(32);

	if (clock_gettime(CLOCK_BOOTTIME, &time) != -1) {
		uptime = time.tv_sec;
		if (uptime > 59) {
			d = uptime / 86400;
			uptime %= 86400;
			h = uptime / 3600;
			uptime %= 3600;
			m = uptime / 60;

			if (d > 0)
				sprintf(buf, "%dd %dh %dm", d, h, m);
			if (h > 0 && m > 0)
				sprintf(buf, "%dh %dm", h, m);
			else {
				if (h > 0)
					sprintf(buf, "%dh", h);
				if (m > 0)
					sprintf(buf, "%dm", m);
			}
		} else
			sprintf(buf, "%lld secs", uptime);

		} else
			buf = "unknown";

	iprint("Uptime:     ", buf);
	free(buf);
}
