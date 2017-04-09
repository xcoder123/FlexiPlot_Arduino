#ifndef FLEXIBARPLOT_H
#define FLEXIBARPLOT_H

#include "FlexiPlotBase.h"
#include "FlexiBarSeries.h"
#include "FlexiBarColumn.h"


typedef struct flexi_bar_column_t flexi_bar_column_t;
struct flexi_bar_column_t
{
    FlexiBarColumn * column;
    struct flexi_bar_column_t * next;
};

class FlexiBarPlot : public FlexiPlotBase
{
public:
    FlexiBarPlot(char* id = "P0");

    FlexiBarPlot* addColumn(char * col_name);
    void removeColumn(uint8_t index);

    uint8_t columns();
    int8_t columnIndex(char * col_name); //If column can't be found it will return -1
    
    FlexiBarSeries* addSeries(char * name);
    FlexiBarSeries* series(uint8_t index);
    FlexiBarSeries* seriesByName(char * name);

    void plot();

    void printColumns();

private:
    void addColumnToLinkedList(flexi_bar_column_t * el);
    void addColumnToAllSeries();
    void removeColumnFromAllSeries(uint8_t index);

private:
    flexi_bar_column_t* m_columns;
    uint8_t columnCount;
};

#endif
