#ifndef FLEXIXYPLOT_H
#define FLEXIXYPLOT_H

#include "FlexiPlotBase.h"
#include "FlexiXYSeries.h"

class FlexiXYPlot : public FlexiPlotBase
{
public:
    FlexiXYPlot(char* id = "P0");
    
    FlexiXYSeries* addSeries(char * name);
    FlexiXYSeries* series(uint8_t index);
    FlexiXYSeries* seriesByName(const char * name);

    void plot();
};

#endif
