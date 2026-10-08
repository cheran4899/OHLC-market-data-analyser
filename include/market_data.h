#ifndef MARKET_DATA_H
#define MARKET_DATA_H

#include "statistics.h"

void display_marketdata(std::vector <MarketData> market_data_vector);
void show_price_statistics(std::vector <MarketData>& market_data_vector);
void show_return_statistics(std::vector <MarketData>& market_data_vector);
void show_validation_report(std::vector <MarketData>& market_data_vector);



#endif