#ifndef STATISTICS_H
#define STATISTICS_H

#include <string>
#include <vector>


struct MarketData
{
    std::string date;
    double open;
    double high;
    double low;
    double close;
    long volume;
};

std::vector<MarketData> load_market_data(const std::string file_name);
double average_close(const std::vector<MarketData>& market_data);
double highest_price(const std::vector<MarketData>& market_data);
double lowest_price(const std::vector<MarketData>& market_data);
double average_volume(const std::vector<MarketData>& market_data);
MarketData highest_volume_record(const std::vector<MarketData>& market_data);
std::vector<double> closing_prices(const std::vector<MarketData>& market_data);
double daily_range(const MarketData& data);
double daily_change(const MarketData& data);
double daily_percentage_change(const MarketData& data);
double largest_intraday_range(const std::vector<MarketData>& market_data);
std::string best_performing_day(const std::vector<MarketData>& market_data);
std::string worst_performing_day(const std::vector<MarketData>& market_data);
double daily_return(const MarketData& data);
std::vector<double> daily_returns(const std::vector<MarketData>& data);
double average_return(const std::vector<double>& returns);
double return_volatility(const std::vector<double>& returns);
double best_return(const std::vector<double>& returns);
double worst_return(const std::vector<double>& returns);
std::string best_return_day(const std::vector<MarketData>& market_data );
std::string worst_return_day(const std::vector<MarketData>& market_data);
double log_return(const MarketData& data);
std::vector<double> log_returns(const std::vector<MarketData>& market_data);



#endif