#ifndef CLPLOTLIB_H
#define CLPLOTLIB_H

struct PlotPlane{
	char *matrix;
	unsigned int height;
	unsigned int width;
};

struct PlotPlane createPlotPlane(unsigned int height, unsigned int width);
void printPlotPlane(struct PlotPlane pp);
void setPixel(struct PlotPlane pp, unsigned int x, unsigned int y, char texture);
int areCordsWithinRange(struct PlotPlane pp, unsigned int x, unsigned int y);
char *setStringHorizontally(struct PlotPlane pp, unsigned int x, unsigned int y, char *str);
#endif
