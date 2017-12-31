#include "Common.h"

Stock::Stock()
{
}

Stock::~Stock()
{
}

void Stock::setMarket(string market)
{
        this->market = market;
}

string Stock::getMarket()
{
        return this->market;
}

void Stock::setSymbol(string symbol)
{
        this->symbol = symbol;
}

string Stock::getSymbol()
{
        return this->symbol;
}

void Stock::setBidPrice(double bidPrice)
{
        this->bidPrice = bidPrice;
}

void Stock::setAskPrice(double askPrice)
{
        this->askPrice = askPrice;
}

double Stock::getBidPrice()
{
        return this->bidPrice;
}

double Stock::getAskPrice()
{
        return this->askPrice;
}

void Stock::setHandCnt(int handCnt)
{
        this->handCnt = handCnt;
}

int Stock::getHandCnt()
{
        return this->handCnt;
}

void Stock::setPosition(int pos)
{
        this->position = pos;
}

int Stock::getPosition()
{
        return this->position;
}

void Stock::setAvgCost(double avgCost)
{
        this->avgCost = avgCost;
}

double Stock::getAvgCost()
{
        return this->avgCost;
}


Account::Account()
{
}

Account::~Account()
{
}

void Account::setAccount(string account)
{
        this->account = account;
}

void Account::setBuyingPower(double buyingPower)
{
        this->buyingPower = buyingPower;
}

double Account::getBuyingPower()
{
        return this->buyingPower;
}

void Account::setSMA(double sma)
{
        this->sma = sma;
}

double Account::getSMA()
{
        return this->sma;
}

void Account::addStock(string symbol, Stock& stock)
{
        stockMap.insert(pair<string, Stock>(symbol, stock));
}

Stock Account::getStock(string symbol)
{
        return stockMap[symbol];
}

TradeOrder::TradeOrder()
{
}

TradeOrder::~TradeOrder()
{
}

void TradeOrder::setSymbol(string symbol)
{
        this->symbol = symbol;
}

string TradeOrder::getSymbol()
{
        return this->symbol;
}

void TradeOrder::setMarket(string market)
{
        this->market = market;
}

string TradeOrder::getMarket()
{
        return this->market;
}

void TradeOrder::setNum(int num)
{
        this->num = num;
}

void TradeOrder::setPrice(double price)
{
        this->price = price;
}

void TradeOrder::setAction(string action)
{
        this->action = action;
}

string TradeOrder::getAction()
{
        return this->action;
}

int TradeOrder::getNum()
{
        return this->num;
}

double TradeOrder::getPrice()
{
        return this->price;
}

void TradeOrder::setHandCnt(int handCnt)
{
        this->handCnt = handCnt;
}

void TradeOrder::setContract(IB::Contract& contract)
{
        this->contract = contract;
}

IB::Contract TradeOrder::getContract()
{
        return this->contract;
}

void TradeOrder::setStock(Stock& stock)
{
        this->stock = stock;
}

Stock TradeOrder::getStock()
{
        return this->stock;
}

void Market::addMktItem(string name, MktItem& mkt)
{
        marketMap.insert(pair<string, MktItem>(name, mkt));
}

MktItem Market::getMktItem(string name)
{
        return marketMap[name];
}
