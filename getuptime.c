/*
 * Copyright (c) 2022 Pham Ngoc Dung (tch69)
 * SPDX-License-Identifier: MIT
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char
*getuptime()
{
	struct timespec time;
	time_t uptime;
	int d, h, m;

	char *buf = (char *) malloc(12);

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

	free(buf);
	return buf;
}
