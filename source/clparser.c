#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "clparser.h"

struct Command getCommandObject(char *command) {

	if (command == NULL) {
		fprintf(stderr, "Error command value is NULL in getCommandObject\n");
		exit(2);
	}

	unsigned int total = 0;
	size_t strLength = strlen(command);

	char *ghost = calloc(strLength + 1, sizeof(char));
	if (ghost == NULL) {
		fprintf(stderr, "Error could not create ghost string for struct Command\n");
		exit(2);
	}

	char *ghostTempPtr = ghost;
	bool inCommand = false;
	for (size_t i = 0; i < strLength; i++) {

		if (command[i] != ' ') {
			if (!inCommand) {
				total++;
				inCommand = true;
			}
			*(ghostTempPtr++) = command[i];
		} else {
			if (inCommand) *(ghostTempPtr++) = '\0';
			inCommand = false;

		}
	}

	ghostTempPtr = ghost;
	char **pointers = malloc(sizeof(char*) * total);
	if (pointers == NULL) {
		printf("Error could not allocate memory for pointers in getCommandObject\n");
		exit(2);
	}
	for (unsigned int i = 0; i < total; i++) {		
		pointers[i] = ghostTempPtr;
		ghostTempPtr += strlen(ghostTempPtr) + 1;
	}

	struct Command cmd;
	cmd.source = command;
	cmd.ghost = ghost;
	cmd.total = total;
	cmd.pointers = pointers;
	cmd.isFreed = false;

	return cmd;
}

void freeCommand(struct Command cmd) {
	free(cmd.ghost);
	free(cmd.pointers);
	cmd.isFreed = true;
}
