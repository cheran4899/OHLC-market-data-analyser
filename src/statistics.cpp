#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>

#include "statistics.h"

std::vector<MarketData> load_market_data(const std::string file_name){

    std::ifstream data(file_name);
    std::vector<MarketData> market_data_vector;

    if(!data.is_open()){
        std::cout << "File does not exist " << "\n";
        return market_data_vector;
    }

    std::string line;

    std::getline(data, line);
    while(std::getline(data, line)){

            std::string d;
            std::string o;
            std::string h;
            std::string l;
            std::string c;
            std::string v;

            std::stringstream ss(line);
            std::getline(ss, d, ',');
            std::getline(ss, o, ',');
            std::getline(ss, h, ',');
            std::getline(ss, l, ',');
            std::getline(ss, c, ',');
            std::getline(ss, v, ',');

            MarketData record;

            record.date = d;
            record.open = std::stod(o);
            record.high = std::stod(h);
            record.low = std::stod(l);
            record.close = std::stod(c);
            record.volume = std::stol(v);

            market_data_vector.push_back(record);


    }

    return market_data_vector;

}

double average_close(const std::vector<MarketData>& market_data){
    double total_closing = 0.0;

    for(const MarketData& record:market_data){
        total_closing += record.close;
    }
    return total_closing/market_data.size();


}
double highest_price(const std::vector<MarketData>& market_data){
    double highest = market_data[0].high;

    for(const MarketData& record:market_data){
        if(highest < record.high){
            highest = record.high;
        }
    }
    return highest;

}
double lowest_price(const std::vector<MarketData>& market_data){

    double lowest = market_data[0].low;

    for(const MarketData& record:market_data){
        if(lowest > record.low){
            lowest = record.low;
        }
    }
    return lowest;

}

double average_volume(const std::vector<MarketData>& market_data){

    long volume =0;

    for(const MarketData& record: market_data){
        volume += record.volume;
    }

    return volume / market_data.size();
    }

MarketData highest_volume_record(const std::vector<MarketData>& market_data){

    MarketData highest_record = market_data[0];
    long volume = market_data[0].volume;
    for(const MarketData& record: market_data){

        if(volume < record.volume){
            volume = record.volume;
            highest_record = record;
        }
    }
    return highest_record;
}


std::vector<double> closing_prices(const std::vector<MarketData>& market_data){

    std::vector<double> closing;

    for(const MarketData& record:market_data){
        closing.push_back(record.close);
    }
    return closing;
}

double daily_range(const MarketData& data){
    return data.high - data.low;
}

double daily_change(const MarketData& data){
    return data.close - data.open;
}

double daily_percentage_change(const MarketData& data){
    return (data.close - data.open) * 100 / data.open;
}

double largest_intraday_range(const std::vector<MarketData>& market_data){

    double range = daily_range(market_data[0]);

    for(const MarketData& record:market_data){
        if(range < daily_range(record)){
            range = daily_range(record);
        }
    }
    return range;
}

std::string best_performing_day(const std::vector<MarketData>& market_data){
    std::string best_day = market_data[0].date;
    double change = daily_percentage_change(market_data[0]);
    for(const MarketData& record:market_data){
        if(change < daily_percentage_change(record)){
            change = daily_percentage_change(record);
            best_day = record.date;
        }
    }
    return best_day;

}
std::string worst_performing_day(const std::vector<MarketData>& market_data){
    std::string worst_day = market_data[0].date;
    double change = daily_percentage_change(market_data[0]);

    for(const MarketData& record:market_data){
        if(change > daily_percentage_change(record) ){

            change = daily_percentage_change(record);
            worst_day = record.date;
        }
    }
    return worst_day;

}

double daily_return(const MarketData& data){

    return (data.close - data.open) / data.open;
}

std::vector<double> daily_returns(const std::vector<MarketData>& data){
    
    std::vector<double> returns;

    for(const MarketData& record:data){
        returns.push_back(daily_return(record));
    }

    return returns;
}

double average_return(const std::vector<double>& returns){
    double values = 0.0;
    
    for(const double& val:returns){
        values += val;
    }

    return values/(double) returns.size();
}


double return_volatility(const std::vector<double>& returns){

    double volatility;
    double average = average_return(returns);
    double sum_of_square_of_differences = 0;
    for(const double& val:returns){
        sum_of_square_of_differences += (average - val) * (average - val); 
    }
    volatility = sqrt(sum_of_square_of_differences/(returns.size() - 1));
    return volatility;

}

double best_return(const std::vector<double>& returns){
    double b_return = returns[0];
    for(const double val:returns){
        if(b_return < val){
            b_return = val;
        }
    }
    return b_return;
}

double worst_return(const std::vector<double>& returns){
    double w_return = returns[0];
    for(const double val:returns){
        if(w_return > val){
            w_return = val;
        }
    }
    return w_return;
}

std::string best_return_day(const std::vector<MarketData>& market_data ){

    std::string best_day = market_data[0].date;
    double b_return = daily_return(market_data[0]);

    for(const MarketData& record:market_data){
        if(b_return < daily_return(record)){
            b_return = daily_return(record);
            best_day = record.date;
        }
    }
    return best_day;
}

std::string worst_return_day(const std::vector<MarketData>& market_data){


    std::string worst_day = market_data[0].date;
    double w_return = daily_return(market_data[0]);

    for(const MarketData& record:market_data){
        if(w_return > daily_return(record)){
            w_return = daily_return(record);
            worst_day = record.date;
        }
    }
    return worst_day;
}

double log_return(const MarketData& data){
    return std::log(data.close/data.open);
}

std::vector<double> log_returns(const std::vector<MarketData>& market_data){

    std::vector<double> l_returns;

    for(const MarketData& record:market_data){
        l_returns.push_back(log_return(record));
    }

    return l_returns;

}