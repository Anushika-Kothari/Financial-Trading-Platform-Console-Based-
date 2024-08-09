#include <iostream>
#include <string>

class User;

class FinancialInstrument {
protected:
    std::string instrumentID;
    std::string name;
    double currentPrice;
    std::string market;
    int quantityAvailable;

public:
    FinancialInstrument(std::string id, std::string n, double price, std::string m, int quantity)
        : instrumentID(id), name(n), currentPrice(price), market(m), quantityAvailable(quantity) {}

    void displayDetails() {
        std::cout << "Instrument ID: " << instrumentID << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Current Price: " << currentPrice << std::endl;
        std::cout << "Market: " << market << std::endl;
        std::cout << "Quantity Available: " << quantityAvailable << std::endl;
    }

    std::string getInstrumentID() {
        return instrumentID;
    }

    std::string getName() {
        return name;
    }

    double getCurrentPrice() {
        return currentPrice;
    }

    std::string getMarket() {
        return market;
    }

    int getQuantityAvailable() {
        return quantityAvailable;
    }

    virtual void performTrade(User& user, int quantity, bool isBuying) = 0;
};

class User {
private:
    std::string userID;
    double balance;
    int stockHoldings;
    int bondHoldings;
    int mutualFundHoldings;
    int cryptoHoldings;

public:
    User(std::string id, double initialBalance)
        : userID(id), balance(initialBalance), stockHoldings(0), bondHoldings(0), mutualFundHoldings(0), cryptoHoldings(0) {}

    void displayHoldings() {
        std::cout << "User Holdings:" << std::endl;
        std::cout << "Stocks: " << stockHoldings << std::endl;
        std::cout << "Bonds: " << bondHoldings << std::endl;
        std::cout << "Mutual Funds: " << mutualFundHoldings << std::endl;
        std::cout << "Cryptocurrencies: " << cryptoHoldings << std::endl;
    }

    void addHolding(std::string instrumentType, int quantity) {
        if (instrumentType == "Stock") {
            stockHoldings += quantity;
        } else if (instrumentType == "Bond") {
            bondHoldings += quantity;
        } else if (instrumentType == "MutualFund") {
            mutualFundHoldings += quantity;
        } else if (instrumentType == "CryptoCurrency") {
            cryptoHoldings += quantity;
        }
    }

    void removeHolding(std::string instrumentType, int quantity) {
        if (instrumentType == "Stock") {
            stockHoldings -= quantity;
        } else if (instrumentType == "Bond") {
            bondHoldings -= quantity;
        } else if (instrumentType == "MutualFund") {
            mutualFundHoldings -= quantity;
        } else if (instrumentType == "CryptoCurrency") {
            cryptoHoldings -= quantity;
        }
    }

    bool hasHolding(std::string instrumentType, int quantity) {
        if (instrumentType == "Stock") {
            return stockHoldings >= quantity;
        } else if (instrumentType == "Bond") {
            return bondHoldings >= quantity;
        } else if (instrumentType == "MutualFund") {
            return mutualFundHoldings >= quantity;
        } else if (instrumentType == "CryptoCurrency") {
            return cryptoHoldings >= quantity;
        }
        return false;
    }

    void reduceBalance(double amount) {
        balance -= amount;
    }

    void increaseBalance(double amount) {
        balance += amount;
    }

    double getBalance() {
        return balance;
    }
};

class Stock : public FinancialInstrument {
private:
    std::string stockSymbol;
    double dividendYield;
    double earningsPerShare;

public:
    Stock(std::string id, std::string n, double price, std::string m, int quantity,
          std::string symbol, double dividend, double earnings)
        : FinancialInstrument(id, n, price, m, quantity), stockSymbol(symbol), dividendYield(dividend), earningsPerShare(earnings) {}
        void displayDetails() {
        FinancialInstrument::displayDetails();
        std::cout << "Stock Symbol: " << stockSymbol << std::endl;
        std::cout << "Dividend Yield: " << dividendYield << std::endl;
        std::cout << "Earnings Per Share: " << earningsPerShare << std::endl;
    }

    void performTrade(User& user, int quantity, bool isBuying);
};

class Bond : public FinancialInstrument {
private:
    std::string bondID;
    double couponRate;
    std::string maturityDate;

public:
    Bond(std::string id, std::string n, double price, std::string m, int quantity,
         std::string bondId, double rate, std::string maturity)
        : FinancialInstrument(id, n, price, m, quantity), bondID(bondId), couponRate(rate), maturityDate(maturity) {}

    void displayDetails() {
        FinancialInstrument::displayDetails();
        std::cout << "Bond ID: " << bondID << std::endl;
        std::cout << "Coupon Rate: " << couponRate << std::endl;
        std::cout << "Maturity Date: " << maturityDate << std::endl;
    }

    void performTrade(User& user, int quantity, bool isBuying);
};

class MutualFund : public FinancialInstrument {
private:
    std::string fundID;
    double expenseRatio;

public:
    MutualFund(std::string id, std::string n, double price, std::string m, int quantity,
               std::string fundId, double expense)
        : FinancialInstrument(id, n, price, m, quantity), fundID(fundId), expenseRatio(expense) {}

    void displayDetails() {
        FinancialInstrument::displayDetails();
        std::cout << "Fund ID: " << fundID << std::endl;
        std::cout << "Expense Ratio: " << expenseRatio << "%" << std::endl;
    }

    void performTrade(User& user, int quantity, bool isBuying);
};

class CryptoCurrency : public FinancialInstrument {
private:
    std::string cryptoID;
    std::string blockchain;

public:
    CryptoCurrency(std::string id, std::string n, double price, std::string m, int quantity,
                   std::string cryptoId, std::string bc)
        : FinancialInstrument(id, n, price, m, quantity), cryptoID(cryptoId), blockchain(bc) {}

    void displayDetails() {
        FinancialInstrument::displayDetails();
        std::cout << "Crypto ID: " << cryptoID << std::endl;
        std::cout << "Blockchain: " << blockchain << std::endl;
    }

    void performTrade(User& user, int quantity, bool isBuying);
};

class RealEstate : public FinancialInstrument {
private:
    std::string propertyID;
    double rentalIncome;
    double propertyValue;

public:
    RealEstate(std::string id, std::string n, double price, std::string m, int quantity,
               std::string propId, double income, double value)
        : FinancialInstrument(id, n, price, m, quantity), propertyID(propId), rentalIncome(income), propertyValue(value) {}

    void displayDetails() {
        FinancialInstrument::displayDetails();
        std::cout << "Property ID: " << propertyID << std::endl;
        std::cout << "Rental Income: " << rentalIncome << std::endl;
        std::cout << "Property Value: " << propertyValue << std::endl;
    }

    void performTrade(User& user, int quantity, bool isBuying);
};

class Commodity : public FinancialInstrument {
private:
    std::string commodityID;
    double commodityPrice;
    std::string commodityType;

public:
    Commodity(std::string id, std::string n, double price, std::string m, int quantity,
              std::string commId, double commPrice, std::string commType)
        : FinancialInstrument(id, n, price, m, quantity), commodityID(commId), commodityPrice(commPrice), commodityType(commType) {}

    void displayDetails() {
        FinancialInstrument::displayDetails();
        std::cout << "Commodity ID: " << commodityID << std::endl;
        std::cout << "Commodity Price: " << commodityPrice << std::endl;
        std::cout << "Commodity Type: " << commodityType << std::endl;
    }

    void performTrade(User& user, int quantity, bool isBuying);
};

void Stock::performTrade(User& user, int quantity, bool isBuying) {
    std::cout << "Executing stock trade..." << std::endl;
    if (isBuying) {
        double totalCost = getCurrentPrice() * quantity;
        if (user.getBalance() >= totalCost) {
            user.reduceBalance(totalCost);
            user.addHolding("Stock", quantity);
            std::cout << "Bought " << quantity << " units of " << getName() << " successfully." << std::endl;
        } else {
            std::cout << "Insufficient balance to buy " << getName() << "." << std::endl;
        }
    } else {
        if (user.hasHolding("Stock", quantity)) {
            double totalValue = getCurrentPrice() * quantity;
            user.increaseBalance(totalValue);
            user.removeHolding("Stock", quantity);
            std::cout << "Sold " << quantity << " units of " << getName() << " successfully." << std::endl;
        } else {
            std::cout << "You do not have enough " << getName() << " to sell." << std::endl;
        }
    }
}

void Bond::performTrade(User& user, int quantity, bool isBuying) {
    std::cout << "Executing bond trade..." << std::endl;
    if (isBuying) {
        double totalCost = getCurrentPrice() * quantity;
        if (user.getBalance() >= totalCost) {
            user.reduceBalance(totalCost);
            user.addHolding("Bond", quantity);
            std::cout << "Bought " << quantity << " units of " << getName() << " successfully." << std::endl;
        } else {
            std::cout << "Insufficient balance to buy " << getName() << "." << std::endl;
        }
    } else {
        if (user.hasHolding("Bond", quantity)) {
            double totalValue = getCurrentPrice() * quantity;
            user.increaseBalance(totalValue);
            user.removeHolding("Bond", quantity);
            std::cout << "Sold " << quantity << " units of " << getName() << " successfully." << std::endl;
        } else {
            std::cout << "You do not have enough " << getName() << " to sell." << std::endl;
        }
    }
}

void MutualFund::performTrade(User& user, int quantity, bool isBuying) {
    std::cout << "Executing mutual fund trade..." << std::endl;
    if (isBuying) {
        double totalCost = getCurrentPrice() * quantity;
        if (user.getBalance() >= totalCost) {
            user.reduceBalance(totalCost);
            user.addHolding("MutualFund", quantity);
            std::cout << "Bought " << quantity << " units of " << getName() << " successfully." << std::endl;
        } else {
            std::cout << "Insufficient balance to buy " << getName() << "." << std::endl;
        }
    } else {
        if (user.hasHolding("MutualFund", quantity)) {
            double totalValue = getCurrentPrice() * quantity;
            user.increaseBalance(totalValue);
            user.removeHolding("MutualFund", quantity);
            std::cout << "Sold " << quantity << " units of " << getName() << " successfully." << std::endl;
        } else {
            std::cout << "You do not have enough " << getName() << " to sell." << std::endl;
        }
    }
}

void CryptoCurrency::performTrade(User& user, int quantity, bool isBuying) {
    std::cout << "Executing cryptocurrency trade..." << std::endl;
    if (isBuying) {
        double totalCost = getCurrentPrice() * quantity;
        if (user.getBalance() >= totalCost) {
            user.reduceBalance(totalCost);
            user.addHolding("CryptoCurrency", quantity);
            std::cout << "Bought " << quantity << " units of " << getName() << " successfully." << std::endl;
        } else {
            std::cout << "Insufficient balance to buy " << getName() << "." << std::endl;
        }
    } else {
        if (user.hasHolding("CryptoCurrency", quantity)) {
            double totalValue = getCurrentPrice() * quantity;
            user.increaseBalance(totalValue);
            user.removeHolding("CryptoCurrency", quantity);
            std::cout << "Sold " << quantity << " units of " << getName() << " successfully." << std::endl;
        } else {
            std::cout << "You do not have enough " << getName() << " to sell." << std::endl;
        }
    }
}

void RealEstate::performTrade(User& user, int quantity, bool isBuying) {
    std::cout << "Executing real estate trade..." << std::endl;
    if (isBuying) {
        double totalCost = getCurrentPrice() * quantity;
        if (user.getBalance() >= totalCost) {
            user.reduceBalance(totalCost);
            user.addHolding("RealEstate", quantity);
            std::cout << "Bought " << quantity << " units of " << getName() << " successfully." << std::endl;
        } else {
            std::cout << "Insufficient balance to buy " << getName() << "." << std::endl;
        }
    } else {
        if (user.hasHolding("RealEstate", quantity)) {
            double totalValue = getCurrentPrice() * quantity;
            user.increaseBalance(totalValue);
            user.removeHolding("RealEstate", quantity);
            std::cout << "Sold " << quantity << " units of " << getName() << " successfully." << std::endl;
        } else {
            std::cout << "You do not have enough " << getName() << " to sell." << std::endl;
        }
    }
}

void Commodity::performTrade(User& user, int quantity, bool isBuying) {
    std::cout << "Executing commodity trade..." << std::endl;
    if (isBuying) {
        double totalCost = getCurrentPrice() * quantity;
        if (user.getBalance() >= totalCost) {
            user.reduceBalance(totalCost);
            user.addHolding("Commodity", quantity);
            std::cout << "Bought " << quantity << " units of " << getName() << " successfully." << std::endl;
        } else {
            std::cout << "Insufficient balance to buy " << getName() << "." << std::endl;
        }
    } else {
        if (user.hasHolding("Commodity", quantity)) {
            double totalValue = getCurrentPrice() * quantity;
            user.increaseBalance(totalValue);
            user.removeHolding("Commodity", quantity);
            std::cout << "Sold " << quantity << " units of " << getName() << " successfully." << std::endl;
        } else {
            std::cout << "You do not have enough " << getName() << " to sell." << std::endl;
        }
    }
}

class TradingAccount {
private:
    User* user;
    Stock stock1;
    Bond bond1;
    MutualFund mutualFund1;
    CryptoCurrency crypto1;
    RealEstate realEstate1;
    Commodity commodity1;

public:
    TradingAccount(User* u)
        : user(u), stock1("STK001", "Company A Stock", 100.0, "NASDAQ", 1000, "A", 2.5, 4.75),
          bond1("BND001", "Company B Bond", 500.0, "NYSE", 500, "B", 3.8, "2025-05-15"),
          mutualFund1("MF001", "Growth Fund", 50.0, "NASDAQ", 200, "GF", 1.5),
          crypto1("CRYPTO001", "Bitcoin", 30000.0, "Crypto Exchange", 5, "BTC", "Blockchain A"),
          realEstate1("RE001", "Luxury Villa", 1000000.0, "Real Estate Market", 2, "LV", 5000.0, 1500000.0),
          commodity1("CM001", "Gold", 1800.0, "Commodity Market", 10, "GLD", 1800.0, "Precious Metal") {}
void displayAvailableInstruments() {
        std::cout << "Available Financial Instruments:" << std::endl;
        stock1.displayDetails();
        bond1.displayDetails();
        mutualFund1.displayDetails();
        crypto1.displayDetails();
        realEstate1.displayDetails();
        commodity1.displayDetails();
    }

    void performTransaction(const std::string& instrumentID, int quantity, bool isBuying);

    void displayTransactionHistory() {
        std::cout << "No transaction history." << std::endl;
    }
};

void TradingAccount::performTransaction(const std::string& instrumentID, int quantity, bool isBuying) {
    if (instrumentID == stock1.getInstrumentID()) {
        stock1.performTrade(*user, quantity, isBuying);
    } else if (instrumentID == bond1.getInstrumentID()) {
        bond1.performTrade(*user, quantity, isBuying);
    } else if (instrumentID == mutualFund1.getInstrumentID()) {
        mutualFund1.performTrade(*user, quantity, isBuying);
    } else if (instrumentID == crypto1.getInstrumentID()) {
        crypto1.performTrade(*user, quantity, isBuying);
    } else if (instrumentID == realEstate1.getInstrumentID()) {
        realEstate1.performTrade(*user, quantity, isBuying);
    } else if (instrumentID == commodity1.getInstrumentID()) {
        commodity1.performTrade(*user, quantity, isBuying);
    } else {
        std::cout << "Invalid instrument ID: " << instrumentID << std::endl;
    }
}

int main() {
    User user1("USER001", 10000.0);
    TradingAccount tradingAccount(&user1);

    tradingAccount.displayAvailableInstruments();
    tradingAccount.performTransaction("STK001", 5, true);
    tradingAccount.performTransaction("BND001", 3, true);
    tradingAccount.performTransaction("MF001", 2, true);
    tradingAccount.performTransaction("CRYPTO001", 1, true);
    tradingAccount.performTransaction("STK001", 2, false);
    tradingAccount.performTransaction("MF001", 1, false);

    user1.displayHoldings();
    std::cout << "User Balance: " << user1.getBalance() << std::endl;

    tradingAccount.displayTransactionHistory();

    return 0;
}
