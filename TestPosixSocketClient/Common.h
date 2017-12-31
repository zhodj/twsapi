#ifndef common_h__INCLUDED
#define common_h__INCLUDED

#include "Contract.h"
#include <string>
#include <map>
using namespace std;

class Stock
{

public:

    Stock();
    ~Stock();

public:

    void setSymbol(string symbol);
    string getSymbol();

    void setMarket(string market);
    string getMarket();

    void setBidPrice(double bidPrice);
    void setAskPrice(double askPrice);

    double getBidPrice();
    double getAskPrice();

    void setHandCnt(int handCnt);
    int getHandCnt();

    void setPosition(int pos);

    int getPosition();
    void setAvgCost(double avgCost);

    double getAvgCost();

private:
    string symbol;
    string market;
    int handCnt;
    double askPrice;
    double bidPrice;
    int position;
    double avgCost;

};

class Account
{
public:
    Account();
    ~Account();

    void setAccount(string account);

    void setBuyingPower(double buyingPower);
    double getBuyingPower();

    void setSMA(double sma);
    double getSMA();
    void addStock(string symbol, Stock& stock);
    Stock getStock(string symbol);

private:
    map<string, Stock> stockMap;
    string account;
    double buyingPower;
    double sma;
};


class TradeOrder
{

public:
    TradeOrder();
    ~TradeOrder();

    void setSymbol(string symbol);
    string getSymbol();

    void setMarket(string market);
    string getMarket();

    void setNum(int num);
    int getNum();

    void setAction(string action);
    string getAction();

    void setPrice(double price);
    double getPrice();

    void setHandCnt(int handCnt);

    void setContract(IB::Contract& contract);
    IB::Contract getContract();

    void setStock(Stock& stock);
    Stock getStock();

private:
    string symbol;
    string market;
    string action;
    int num;
    double price;
    int handCnt;

    IB::Contract contract;
    Stock stock;
};




class MktItem
{

public:
    MktItem(){}
    ~MktItem(){}

};


class Market
{
public:

    Market(){}
    ~Market(){}

    void addMktItem(string name, MktItem& mkt);
    MktItem getMktItem(string name);

private:
    map<string, MktItem> marketMap;
};

#endif
