#ifndef FLEXITIMEPLOT_H
#define FLEXITIMEPLOT_H

#include "FlexiXYPlot.h"
#include "FlexiXYSeries.h"

class FlexiTimePlot : public FlexiXYPlot
{
public:
    FlexiTimePlot(char* id = "P0");

    void plot();
};

#endif
