#include "FlexiPlot.h"

FlexiTimePlot myPlot;
FlexiXYPlot* xyPlot;
FlexiXYPlot* scatterPlot;
FlexiXYSeries* seriesSin;

double xVal;
uint32_t currentTime;
uint32_t lastPlotTime = 0;
uint8_t k = 0;


void setup() {
  Serial.begin(115200);

//  initTimePlot();
//  initXYPlot();
  initScatterPlot();

//  myPlot.removeSeriesByName("Sin");
}

void loop() {
//  series->addData(random(0,1000));

  currentTime = millis();

//  timePlotExample();
//  xyPlotExample(k++/7);
  scatterPlotExample(4);
  delay(60);

  
//  myPlot.printSeries();
//  Serial.println(myPlot.count());
}


void initScatterPlot()
{
  scatterPlot = new FlexiXYPlot("P1");
  scatterPlot->addSeries("Test");
}

void scatterPlotExample(uint8_t k)
{
  

  if(currentTime - lastPlotTime >= 2000)
  {
    lastPlotTime = currentTime;
    double xD;
    for(int xI = -1000; xI < 1000; xI++)
    {
      xD = xI / 10.0;
      double r = cos(k*xD);
      double x = r * cos(xD);
      double y = r * sin(xD);
      scatterPlot->series(0)->addData( x, y );
      if(xI % 10 == 0)
      {
        scatterPlot->plot();
        delay(30);
      }
    }
    
    scatterPlot->plot();
  }
}

void initXYPlot()
{
  xyPlot = new FlexiXYPlot("P1");
  xyPlot->addSeries("Test");
}

void xyPlotExample(uint8_t k)
{
  

  if(currentTime - lastPlotTime >= 2000)
  {
    lastPlotTime = currentTime;
    double xD;
    for(int xI = -50; xI < 50; xI++)
    {
      xD = xI / 10.0;
      double r = cos(k*xD);
      double x = r * cos(xD);
      double y = r * sin(xD);
      xyPlot->series(0)->addData( x, y );
    }
    
    xyPlot->plot();
  }
}

void initTimePlot()
{
  myPlot.setID("P0");
  seriesSin = myPlot.addSeries("Sin");
  myPlot.addSeries("Cos");
  myPlot.addSeries("Random");

  xVal = 0;
}

void timePlotExample()
{
  xVal += 2;
  
  seriesSin->addData(sin(xVal/10.0))->addData(sin((xVal+1)/10.0));
  myPlot.series(1)->addData(cos(xVal/10.0))->addData(cos((xVal+1)/10.0));
  myPlot.seriesByName("Random")->addData( random(-30,30)/30.0 )->addData( random(-30,30)/30.0 );
  myPlot.plot();
}

