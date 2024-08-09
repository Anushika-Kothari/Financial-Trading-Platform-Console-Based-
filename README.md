## Project Overview

This project is a **Financial Trading System** that simulates trading in various financial instruments such as stocks, bonds, mutual funds, cryptocurrencies, real estate, and commodities. The system is built using C++ and allows users to manage their holdings, perform transactions (buying and selling), and view available financial instruments.

### Key Features

- **Financial Instruments**: Includes stocks, bonds, mutual funds, cryptocurrencies, real estate, and commodities, each with unique attributes.
- **User Management**: Tracks user balance and holdings, and updates them based on trades.
- **Trading Functionality**: Supports buying and selling of instruments with balance checks and holdings updates.
- **Instrument Details**: Displays detailed information about each financial instrument available for trading.
- **Transaction Execution**: Implements trades through an intuitive interface, adjusting user holdings and balance accordingly.

### Structure

- **Classes**: 
  - `FinancialInstrument`: Base class with common attributes and virtual trade function.
  - `Stock`, `Bond`, `MutualFund`, `CryptoCurrency`, `RealEstate`, `Commodity`: Derived classes with specific attributes and trade implementations.
  - `User`: Manages user data, including balance and holdings.
  - `TradingAccount`: Manages available instruments and handles trade transactions.

### Usage

- **Display Instruments**: View details of all available financial instruments.
- **Perform Transactions**: Execute buy or sell orders for specific instruments.
- **View Holdings**: Check current user holdings and balance.

This project serves as a basic simulation of a financial trading system, suitable for understanding the fundamentals of trading various financial instruments programmatically.
