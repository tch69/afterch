#include <sys/utsname.h>
#include <stdio.h>

#include "extern.h"

void
*getsys()
{
	struct utsname sys;
	uname(&sys);

	iprint("OS/System:  ", sys.sysname);
	iprint("Kernel:     ", sys.release);

	return 0;
}

