#ifndef FLEXITIMEPLOT_H
#define FLEXITIMEPLOT_H

#include "FlexiPlotBase.h"
#include "FlexiXYSeries.h"

class FlexiTimePlot : public FlexiPlotBase
{
public:
    FlexiTimePlot(char* id = "P0");
    
    FlexiXYSeries* addSeries(char * name);
    FlexiXYSeries* series(uint8_t index);
    FlexiXYSeries* seriesByName(const char * name);

    void plot();
};

#endif
