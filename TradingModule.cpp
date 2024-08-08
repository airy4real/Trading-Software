#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>


class MarketData {
public:
    MarketData(const std::string& symbol) : symbol(symbol), price(0.0) {}

    void fetchData() {
        // Simulate fetching data from an external source
        price = rand() % 100 + 1; // Random price between 1 and 100
        std::cout << "Fetched data for " << symbol << ": $" << price << std::endl;
    }

    double getPrice() {
        return price;
    }

private:
    std::string symbol;
    double price;
};

class Order {
public:
    enum class OrderType { BUY, SELL };

    Order(OrderType type, double price) : type(type), price(price) {}

    void execute() {
        std::string orderType = (type == OrderType::BUY) ? "Buy" : "Sell";
        std::cout << orderType << " order executed at $" << price << std::endl;
    }

private:
    OrderType type;
    double price;
};

class TradingEngine {
public:
    TradingEngine(const std::string& symbol) : marketData(symbol) {}

    void run() {
        marketData.fetchData();
        double price = marketData.getPrice();

        // Simple trading logic: Buy if price is below 50, sell if above 50
        if (price < 50) {
            Order order(Order::OrderType::BUY, price);
            executeOrder(order);
        } else {
            std::cout << "Price too high, not buying." << std::endl;
        }
    }

private:
    MarketData marketData;

    void executeOrder(Order& order) {
        order.execute();
    }
};

class Logger {
public:
    void log(const std::string& message) {
        std::cout << "[LOG]: " << message << std::endl;
    }
};


class UserInterface {
public:
    void start() {
        std::cout << "Trading Software Started" << std::endl;
        Logger logger;
        logger.log("System initialized.");

        std::string symbol;
        std::cout << "Enter the stock symbol to trade: ";
        std::cin >> symbol;

        TradingEngine engine(symbol);
        engine.run();
    }
};

int main() {
    srand(static_cast<unsigned>(time(0))); 
    UserInterface ui;
    ui.start();
    return 0;
}
