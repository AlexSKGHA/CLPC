#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "clplotlib.h"

/*
	One issue: overflow of resolution in createPlotPlane not handled
*/

struct PlotPlane createPlotPlane(unsigned int width, unsigned int height) {
	char *matrix;
	
	if (width * height == 0) {
		fprintf(stderr, "Plane's size is 0\n");
		exit(1);
	}

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

void printPlotPlane(struct PlotPlane pp) {
	unsigned int widthCounter = 0;
	char *tempStr = calloc(pp.width + 1, sizeof(char));
	if (tempStr == NULL) {
		fprintf(stderr, "Error allocating mem to tempStr in printPlotPlane()\n");
		exit(1);
	}
	while (widthCounter < pp.width) {
		strncpy(tempStr, pp.matrix + pp.width * widthCounter, pp.width);
		printf("%s\n", tempStr);
		widthCounter++;
	}
}
