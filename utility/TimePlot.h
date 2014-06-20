#pragma once
#include <Arduino.h>
#include "Plot.h"

class TimePlot : public Plot
{

public:
  TimePlot(const char *channelName = NULL, Print &rDestination = Serial);
  TimePlot(const __FlashStringHelper *channelName, Print &rDestination = Serial);

  template<class TYData> void SendData(const char * seriesName, TYData yValue, const char * seriesProperties=NULL)
  {
    SendDataHeader(F("DATA"));
    m_rDestination.print(seriesName);
    SendSeriesProperties(seriesProperties);
    m_rDestination.print(F("T|"));
    m_rDestination.print(yValue);
    SendDataTail();
  }

  template<class TYData> void SendData(const char * seriesName, TYData yValue, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle)
  {
    SendDataHeader(F("DATA"));
    m_rDestination.print(seriesName);
    SendSeriesProperties(Color, Line, uLineWidth, Marker);
    m_rDestination.print(F("T|"));
    m_rDestination.print(yValue);
    SendDataTail();
  }

  void SendFloatData(const char * seriesName, float yValue, int nDecimalPlaces, const char * seriesProperties=NULL);
  void SendFloatData(const char * seriesName, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle);

  template<class TYData> void SendData(const __FlashStringHelper * seriesName, TYData yValue, const char * seriesProperties=NULL)
  {
    SendDataHeader(F("DATA"));
    m_rDestination.print(seriesName);
    SendSeriesProperties(seriesProperties);
    m_rDestination.print(F("T|"));
    m_rDestination.print(yValue);
    SendDataTail();
  }

  template<class TYData> void SendData(const __FlashStringHelper * seriesName, TYData yValue, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle)
  {
    SendDataHeader(F("DATA"));
    m_rDestination.print(seriesName);
    SendSeriesProperties(Color, Line, uLineWidth, Marker);
    m_rDestination.print(F("T|"));
    m_rDestination.print(yValue);
    SendDataTail();
  }

  void SendFloatData(const __FlashStringHelper * seriesName, float yValue, int nDecimalPlaces, const char * seriesProperties=NULL);
  void SendFloatData(const __FlashStringHelper * seriesName, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle);
};