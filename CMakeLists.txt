cmake_minimum_required(VERSION 3.16)

project(MarketDataAnalyser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(market_data_analyser
    src/main.cpp
    src/market_data.cpp
    src/validator.cpp
    src/statistics.cpp
)

target_include_directories(market_data_analyser
    PRIVATE
    include
)