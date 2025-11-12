#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "clplotlib.h"

struct PlotPlane createPlotPlane(unsigned int width, unsigned int height) {
	if (((width * height) / width) != height) {
		fprintf(stderr, "Error matrix not jive with dimensions\n");
		exit(1);
	}

	char *matrix;

	if ((matrix = malloc(sizeof(char) * height * width)) == NULL) {
		fprintf(stderr, "Error allocating mem for PlotPlane\n");
		exit(1);
	}

	for (unsigned int i = 0; i < height * width; i++) {
		matrix[i] = ' ';
	}

	struct PlotPlane pp = {.matrix=matrix, .height=height, .width=width};
	return pp;
}

int areCordsWithinRange(struct PlotPlane pp, unsigned int x, unsigned int y) {
	if ((x < pp.width) && (y < pp.height)) {
		return 1;
	} else return 0;
}

void setPixel(struct PlotPlane pp, unsigned int x, unsigned int y, char texture) {
	if (areCordsWithinRange(pp, x, y)) {
		pp.matrix[pp.width * y + x] = texture;
	} else {
		fprintf(stderr, "Error setting the pixel out of bounds\n");
	}
}

void printPlotPlane(struct PlotPlane pp) {
	unsigned int heightCounter = 0;
	char *tempStr = calloc(pp.width + 1, sizeof(char));
	if (tempStr == NULL) {
		fprintf(stderr, "Error allocating mem to tempStr in printPlotPlane()\n");
		exit(1);
	}
	while (heightCounter < pp.height) {
		strncpy(tempStr, pp.matrix + pp.width * heightCounter, pp.width);
		printf("%s\n", tempStr);
		heightCounter++;
	}
}

char *setStringHorizontally(struct PlotPlane pp, unsigned int x, unsigned int y, char *str) {
	if (!areCordsWithinRange(pp, x, y)) return NULL;

	unsigned int strLength = strlen(str);
	unsigned int newx = x;
	for (unsigned int i = 0; i < strLength; i++) {
		if (newx < pp.width) {
			setPixel(pp, newx, y, str[i]);
			newx++;
		} else {
			return str + newx;
		}
	}
	return '\0';
}
