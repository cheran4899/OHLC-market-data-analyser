#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "statistics.h"

bool is_valid(const MarketData& data);
std::vector<std::string> validate(const MarketData& data);
std::vector<MarketData> return_valid_data(const std::vector<MarketData>& market_data_vector);
std::vector<MarketData> return_invalid_data(const std::vector<MarketData>& market_data_vector);

#endif