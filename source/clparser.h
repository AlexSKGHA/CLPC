#ifndef CLIPARSER_H
#define CLIPARSER_H

#include <stdbool.h>

struct Command {
	char *source;
	char *ghost;
	char **pointers;
	unsigned int total;
	bool isFreed;
};

struct Command getCommandObject(char *command);

#endif
