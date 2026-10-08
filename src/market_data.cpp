#include <iostream>

#include "statistics.h"
#include "validator.h"



void display_marketdata(std::vector <MarketData> market_data_vector){
    std::cout << "Date"
              << "           " << "Open"
              << "         " << "High"
              << "       " << "Low" 
              << "      " << "Close" 
              << "      " << "Volume" << "\n";

    std::cout << "-----------------------------------------------------------------------" << "\n";

    for(const MarketData& record:market_data_vector)
        {
            std::cout << record.date << "     "
                    << record.open   << "      "
                    << record.high   << "      "
                    << record.low    << "      "
                    << record.close  << "      "
                    <<record.volume << "\n";
        }

    std::cout << "..."<<"\n" << "\n";

}


void show_validation_report(std::vector <MarketData>& all_market_data_vector){

    std::cout << "------------------------------------------------" << "\n";
    std::cout << "----------Validation report---------------------" << "\n";
    std::cout << "------------------------------------------------" << "\n" << "\n";

    std::vector<MarketData> invalid_market_data;

    std::vector<MarketData> market_data_vector;

    for(const MarketData& record:all_market_data_vector){
        if(!is_valid(record)){
            invalid_market_data.push_back(record);
        }
        else{
            market_data_vector.push_back(record);
        }
    }

    std::cout << "Total records: " << all_market_data_vector.size() << "\n";
    std::cout << "Valid records: " << market_data_vector.size() << "\n";
    std::cout << "Invalid records: " << invalid_market_data.size() << "\n" << "\n";

    std::cout << "Invalid record data: " << "\n";

    for (const MarketData& record:invalid_market_data){
        std::vector<std::string> reasons = validate(record);
        std::cout << record.date << " : \n";
        for(const std::string& reason:reasons){
            std::cout << reason << "\n";
        }
        std::cout << "\n";
    }

    std::cout << "\n";
}
void show_price_statistics(std::vector <MarketData>& market_data_vector){
    std::cout << "------------------------------------------------" << "\n";
    std::cout << "-----------------Statistics---------------------" << "\n";
    std::cout << "------------------------------------------------" << "\n" << "\n";

    std::cout << "Average closing price: " << average_close(market_data_vector) << "\n";
    std::cout << "Highest price: " << highest_price(market_data_vector) << "\n";
    std::cout << "Lowest price: " << lowest_price(market_data_vector) << "\n";
    std::cout << "Average Volume: " << average_volume(market_data_vector) << "\n";

    MarketData record = highest_volume_record(market_data_vector);
    std::cout << "Highest volume record: " 
        << record.date << " "
        << record.open   << " "
        << record.high   << " "
        << record.low    << " "
        << record.close  << " "
        <<record.volume << "\n";
    /*
    std::cout << "Closing prices: ";
    std::vector<double> closing = closing_prices(market_data_vector);
    for(double& val:closing){
        std::cout << val << " ";
    }
    std::cout << "\n";*/

    std::cout << "Largest intraday range: " << largest_intraday_range(market_data_vector) << "\n";
    std::cout << "Best performing day: " << best_performing_day(market_data_vector) << "\n";
    std::cout << "Worst performing day: " << worst_performing_day(market_data_vector) << "\n";

}

void show_return_statistics(std::vector <MarketData>& market_data_vector){

    /*
    std::cout << "\n" << "Daily returns: ";
    std::vector<double> d_returns = daily_returns(market_data_vector);
    for(double& val:d_returns){
        std::cout << val << " ";
    }
    std::cout << "\n";*/
    std::vector<double> d_returns = daily_returns(market_data_vector);

    std::cout << "Average return: " << average_return(d_returns) << "\n";
    std::cout << "Return volatility: " << return_volatility(d_returns) << "\n";
    std::cout << "Best return: " << best_return(d_returns) << "\n";
    std::cout << "Worst return: " << worst_return(d_returns) << "\n";
    std::cout << "Best return day: " << best_return_day(market_data_vector) << "\n";
    std::cout << "Worst return day: " << worst_return_day(market_data_vector) << "\n";
    /*
    std::cout << "Log returns: ";
    std::vector<double> l_returns = log_returns(market_data_vector);
    
    for(double& val:l_returns){
        std::cout << val << " ";
    }
    std::cout << "\n";
    */
}