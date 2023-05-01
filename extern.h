/*
 * extern.h
 */

/*
 * Bold text colours; we use loops to display the colour blocks instead
 */
#define C_RESET 	"\033[0m"
#define C_RED 		"\033[1;31m"
#define C_GREEN 	"\033[1;32m"
#define C_YELLOW 	"\033[1;33m"
#define C_BLUE 		"\033[1;34m"
#define C_MAGENTA 	"\033[1;35m"
#define C_CYAN	 	"\033[1;36m"
#define C_WHITE 	"\033[1;39m"

char *getuptime(void);
char *strloop(const char *restrict, const int);
