#ifndef CLPLOTLIB_H
#define CLPLOTLIB_H

struct PlotPlane{
	char *matrix;
	unsigned int height;
	unsigned int width;
};

struct Pixel {
	char texture;
	unsigned int x;
	unsigned int y;
};

struct PlotPlane createPlotPlane(unsigned int height, unsigned int width);
void printPlotPlane(struct PlotPlane pp);
#endif
