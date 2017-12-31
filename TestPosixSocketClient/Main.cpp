/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#include <unistd.h>
#include <pthread.h>
#include <iostream>

#include "PosixTestClient.h"
#include "Common.h"

using namespace std;

const unsigned MAX_ATTEMPTS = 1;
const unsigned SLEEP_TIME = 10;

const char* host = "127.0.0.1";
unsigned int port = 7496;

void initData(Account& account, Stock& stock, IB::Contract& contract, TradeOrder& tradeOrder)
{
    string mainAcc = "U9369878";
    string tradeSymbol = "981";
    string tradeMarket = "SEHK";
    int handCnt = 500;

    account.setAccount(mainAcc);

    stock.setSymbol(tradeSymbol);
    stock.setMarket(tradeMarket);
    stock.setHandCnt(handCnt);

    contract.symbol = tradeSymbol;
    contract.secType = "STK";
    contract.currency = "HKD";
    contract.exchange = tradeMarket;

    tradeOrder.setContract(contract);
    tradeOrder.setStock(stock);
    tradeOrder.setAction("BUY");

}

void* worker(void* ptr)
{
    unsigned attempt = 0;
    cout << "Start of POSIX Socket Client Test " << attempt << endl;

    Account mainAcc;
    Stock stock;
    IB::Contract contract;
    TradeOrder tradeOrder;

    initData(mainAcc, stock, contract, tradeOrder);

    for (;;) {
        ++attempt;
        cout << "Attempt " << attempt << " of " << MAX_ATTEMPTS << endl;

        int clientId = 0;
        IB::PosixTestClient client;

        client.connect( host, port, clientId);

        client.initTradeData(mainAcc, stock, contract, tradeOrder);

        while( client.isConnected()) {
            client.processMessages();
        }

        if(attempt >= MAX_ATTEMPTS)
            break;

        cout << "Sleeping " << SLEEP_TIME << " seconds before next attempt" << endl;
        sleep( SLEEP_TIME);
    }

}

int main(int argc, char** argv)
{
	pthread_t thread1, thread2;

	int ret = pthread_create(&thread1, NULL, worker, NULL);
    if (ret)
    {
        cout << "Create pthread error!" << endl;
        return 1;
    }


    /*
	ret = pthread_create(&thread1, NULL, worker, NULL);
    if (ret)
    {
        cout << "Create pthread error!" << endl;
        return 1;
    }
    */

	pthread_join(thread1, NULL);
    //pthread_join(thread2, NULL);

	cout << "End of POSIX Socket Client Test" << endl;
}

