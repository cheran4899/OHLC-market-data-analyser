#include <iostream>

#include "validator.h"


bool is_valid(const MarketData& data){

    if (!(data.open > 0 && data.high > 0 && data.low > 0 && data.close>0 && data.volume >= 0 )){
        return false;
    }

    if (!(data.low <= data.open && data.low <= data.high && data.low <= data.close 
    && data.high >= data.open && data.high >= data.close && data.high >= data.low)){
        return false;
    }
    return true;

}
std::vector<std::string> validate(const MarketData& data){

    std::vector<std::string> invalid_data;

    if (!(data.open > 0)){
        invalid_data.push_back("Open cannot be negative");
    }
    if (!(data.high > 0)){
        invalid_data.push_back("High cannot be negative");
    }
    if (!(data.low > 0)){
        invalid_data.push_back("Low cannot be negative");
    }
    if (!(data.close > 0)){
        invalid_data.push_back("Close cannot be negative");
    }
    if (!(data.volume > 0)){
        invalid_data.push_back("Volume cannot be negative");
    }
    if(!(data.low <= data.open)){
        invalid_data.push_back("Low cannot be greater than open");
    }
    if(!(data.low <= data.high)){
        invalid_data.push_back("Low cannot be greater than high");
    }
    if(!(data.low <= data.close)){
        invalid_data.push_back("Low cannot be greater than close");
    }
    if(!(data.high >= data.open)){
        invalid_data.push_back("High cannot be less than open");
    }
    if(!(data.high >= data.close)){
        invalid_data.push_back("High cannot be lower than close");
    }

    return invalid_data;
}



std::vector<MarketData> return_valid_data(const std::vector<MarketData>& market_data_vector){

    std::vector<MarketData> valid;
    for(const MarketData& record:market_data_vector){
        if(is_valid(record)){
            valid.push_back(record);
        }
    }
    return valid;
}
std::vector<MarketData> return_invalid_data(const std::vector<MarketData>& market_data_vector){
    std::vector<MarketData> invalid;
    for(const MarketData& record:market_data_vector){
        if(!(is_valid(record))){
            invalid.push_back(record);
        }
    }
    return invalid;
}

