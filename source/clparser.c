#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "clparser.h"

struct Command getCommandObject(char *command) {

	unsigned int total = 0;
	size_t strLength = strlen(command);

	char *ghost = calloc(strLength + 1, sizeof(char));
	if (ghost == NULL) {
		fprintf(stderr, "Error could not create ghost string for struct Command\n");
		exit(2);
	}
	char *ghostTempPtr = ghost;

	bool inCommand = false;
	bool isIterated = true;
	for (size_t i = 0; i < strLength; i++) {
		if (isIterated) {
			if (command[i] != ' ') {
				if (command[i] == '\\') {
					isIterated = false;
				}
				if (!inCommand) {
					total++;
					inCommand = true;
				}
				if (isIterated) *(ghostTempPtr++) = command[i];
			} else if (command[i] == ' ') {
				inCommand = false;
				*(ghostTempPtr++) = '\0';
			}
		} else isIterated = true;
	}

	ghostTempPtr = ghost;
	char **pointers = malloc(sizeof(char*) * total);
	for (int i = 0; i < total; i++) {
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
