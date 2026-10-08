# Market Data Analyser

A C++ command-line application for reading, validating, and analysing OHLC market data from CSV files.

This project was built as part of my C++ learning journey, with a focus on financial data processing, file I/O, data validation, statistics, and project structure using CMake.

## Features

- Read market data from CSV files
- Parse OHLCV data
- Validate market data records
- Calculate price statistics
- Calculate daily returns
- Calculate log returns
- Calculate return volatility
- Identify best and worst performing days
- Identify highest-volume trading days
- Generate a validation report
- Command-line menu for accessing different analyses

## Market Data Format

The application expects CSV data in the following format:

```csv
Date,Open,High,Low,Close,Volume
2026-09-01,100.20,103.80,99.40,102.90,12500
2026-09-02,102.90,105.60,101.80,104.75,14800
```

### Fields

| Field | Description |
|---|---|
| Date | Trading date |
| Open | Opening price |
| High | Highest price during the day |
| Low | Lowest price during the day |
| Close | Closing price |
| Volume | Trading volume |

## Validation

The application checks for invalid market data, including:

- Negative prices
- Negative volume
- Low greater than Open
- Low greater than High
- Low greater than Close
- High lower than Open
- Other invalid OHLC relationships

Invalid records are excluded from statistical calculations.

## Project Structure

```text
OHLC-market-data/
├── src/
│   ├── main.cpp
│   ├── market_data.cpp
│   ├── validator.cpp
│   └── statistics.cpp
├── include/
│   ├── market_data.h
│   ├── validator.h
│   └── statistics.h
├── data/
│   └── market_data.csv
├── build/
├── CMakeLists.txt
└── README.md
```

## Building

### Requirements

- C++17 compatible compiler
- CMake 3.16+

### Build

Clone the repository:

```bash
git clone <repository-url>
cd OHLC-market-data
```

Create a build directory:

```bash
mkdir build
cd build
```

Configure the project:

```bash
cmake ..
```

Build the executable:

```bash
cmake --build .
```

## Running

From the project root:

```bash
./build/market_data_analyser
```

The application currently reads the market data from:

```text
data/market_data.csv
```

## Example Menu

```text
========================================
          Market Data Analyser
========================================
1. Display market data
2. Show price statistics
3. Show return statistics
4. Show validation report
5. Exit
Enter option:
```

## Financial Calculations

### Daily Return

The simple daily return is calculated as:

```text
Return = (Close - Open) / Open
```

### Log Return

```text
Log Return = log(Close / Open)
```

### Return Volatility

Sample standard deviation is used to calculate daily return volatility:

```text
σ = sqrt( Σ(rᵢ - r̄)² / (n - 1) )
```

## Performance

The application was tested with a market-data CSV containing more than 300,000 records.

Performance benchmarking will be added as the project develops.

## What I Learned

This project helped me practise:

- C++ structs
- Header/source file separation
- Functions and reusable modules
- `std::vector`
- `std::string`
- `std::ifstream`
- `std::stringstream`
- CSV parsing
- Exception/error handling
- Data validation
- Financial return calculations
- CMake
- Project directory structure
- Command-line applications

## Future Improvements

Planned improvements include:

- Accept CSV path through command-line arguments
- Add automated unit tests
- Add performance benchmarking
- Improve CSV parsing performance
- Support larger datasets
- Improve error reporting
- Add portfolio and P&L functionality
- Eventually extend the project into a market-data/trading system

## Author

Built as part of my C++ and quantitative development learning journey.