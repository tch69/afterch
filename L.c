#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>

#define bold_black 	"\e[1;30m"
#define bold_red 	"\e[1;31m"
#define bold_green 	"\e[1;32m"
#define bold_yellow 	"\e[1;33m"
#define bold_blue 	"\e[1;34m"
#define bold_magenta 	"\e[1;35m"
#define bold_cyan 	"\e[1;36m"
#define grey 		"\e[1;37m"
#define norm_grey 	"\e[0;37m"

#define fg_black 	"\e[1;40m"
#define fg_red 		"\e[1;41m"
#define fg_green 	"\e[1;42m"
#define fg_yellow 	"\e[1;43m"
#define fg_blue 	"\e[1;44m"
#define fg_magenta 	"\e[1;45m"
#define fg_cyan 	"\e[1;46m"
#define fg_grey 	"\e[1;47m"

#define fg_lblack 	"\e[1;100m"
#define fg_lred	 	"\e[1;101m"
#define fg_lgreen 	"\e[1;102m"
#define fg_lyellow 	"\e[1;103m"
#define fg_lblue 	"\e[1;104m"
#define fg_lmagenta 	"\e[1;105m"
#define fg_lcyan 	"\e[1;106m"
#define fg_white 	"\e[1;107m"

#define colour_reset 	"\e[0m"

char * os() {
        FILE *l;
        char *os;
        char L[37];
        l = fopen("/etc/os-release", "r");
        fgets(L, 37, l);
        fclose(l);
        os = strtok(L, "NAME=\"");
        return os;
}

char *exec(const char *exec) {
        FILE *l = popen(exec, "r");
        char *L = malloc(256);
        fscanf(l, "%[^\n]s", L);
        pclose(l);
        return L;
}

int main() {
	struct utsname L;
	uname(&L);
	system("clear");
	printf("\n");
	printf(" %s--->%s     %s%s%s@%s%s%s\n", bold_magenta, colour_reset, bold_green, getenv("USER"), bold_yellow, bold_red, getenv("HOST"), colour_reset);
	printf(" %s--------------------------------->%s\n", bold_magenta, colour_reset);
	printf("\n");
	printf("    %s->%s  %sOS/Distro%s:%s %s\n", bold_cyan, colour_reset, bold_blue, bold_red, norm_grey, os());

	printf("    %s->%s  %sKernel%s:%s    %s\n", bold_cyan, colour_reset, bold_blue, bold_red, norm_grey, strtok(L.release, "-*"));
	printf("    %s->%s  %sPackages%s:%s  %s\n", bold_cyan, colour_reset, bold_blue, bold_red, norm_grey, exec("qlist -I | wc -l"));
	printf("    %s->%s  %sShell:%s:%s    %s\n", bold_cyan, colour_reset, bold_blue, bold_red, norm_grey, strtok(getenv("SHELL"), "*/bin/"));
	printf("    %s->%s  %sWM%s:%s        %s\n", bold_cyan, colour_reset, bold_blue, bold_red, norm_grey, exec("wmctrl -m | awk '/Name/ {print $2}'"));
	printf("    %s->%s  %sTerminal:%s:%s %s\n", bold_cyan, colour_reset, bold_blue, bold_red, norm_grey, getenv("TERM"));
	printf("\n");
	printf(" %s--->%s  %s   %s   %s   %s   %s   %s   %s   %s   %s\n", bold_cyan, colour_reset, fg_black, fg_red, fg_green, fg_yellow, fg_blue, fg_magenta, fg_cyan, fg_grey, colour_reset);
	printf(" %s--->%s  %s   %s   %s   %s   %s   %s   %s   %s   %s\n", bold_cyan, colour_reset, fg_lblack, fg_lred, fg_lgreen, fg_lyellow, fg_lblue, fg_lmagenta, fg_lcyan, fg_white, colour_reset);
	printf("\n");
	return 0;
}
