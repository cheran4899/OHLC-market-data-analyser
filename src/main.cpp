#include <iostream>
#include <vector>

#include "statistics.h"
#include "market_data.h"
#include "validator.h"

int main(){

    std::vector<MarketData> all_market_data_vector = load_market_data("data/marketdata.csv");

    std::vector<MarketData> valid_market_data = return_valid_data(all_market_data_vector);

    std::cout << "========================================" << "\n";
    std::cout << "          Market Data Analyser          " << "\n";
    std::cout << "========================================" << "\n";

    while (true)
   {
        std::cout << "---------------------------------------------------" <<"\n";
        std::cout << "1. Display market data \n2. Show price statistics \n3. Show return statistics \n4. Show validation report \n5. Exit \n";
        int option;
        std::cout << "Enter option: ";
        std::cin >> option;
        switch (option)
        {
        case 1:
            display_marketdata(all_market_data_vector);
            break;
        case 2:
            show_price_statistics(valid_market_data);
            break;
        case 3:
            show_return_statistics(valid_market_data);
            break;
        case 4:
            show_validation_report(all_market_data_vector);
            break;
        case 5:
            return 0;
        default:
            std::cout << "Entered invalid option :( ";
            break;
        }
        std::cout << "---------------------------------------------------" <<"\n";
    }
    

    return 0;
}