#ifndef FLEXIPIECHART_H
#define FLEXIPIECHART_H

#include "FlexiPlotBase.h"
#include "FlexiPieSeries.h"

class FlexiPieChart : public FlexiPlotBase
{
public:
    FlexiPieChart(char* id = "P0");
    
    FlexiPieSeries* addSeries(char * name);
    FlexiPieSeries* series(uint8_t index);
    FlexiPieSeries* seriesByName(char * name);

    void plot();
};

#endif
