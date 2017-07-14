/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#ifdef _WIN32
# include <windows.h>
# define sleep( seconds) Sleep( seconds * 1000);
#else
# include <unistd.h>
#endif

#include "PosixTestClient.h"

const unsigned MAX_ATTEMPTS = 1;
const unsigned SLEEP_TIME = 10;
const unsigned IBCONTROLLER_PORT = 7462;
const unsigned IB_PORT = 7496;

int main(int argc, char** argv)
{
	//Init glog
	FLAGS_log_dir = "/tmp/PosixTestClient/";
	google::InitGoogleLogging(argv[0]);

	const char* host = argc > 1 ? argv[1] : "";
	unsigned int port = argc > 2 ? atoi(argv[2]) : IB_PORT;
	int clientId = 0;

	unsigned attempt = 0;
	LOG(INFO) << "Start of POSIX Socket Client Test " << attempt;

	for (;;) {
		++attempt;
		LOG(INFO) << "Attempt " << attempt << " of " << MAX_ATTEMPTS;

		IB::PosixTestClient client;

		client.connect( host, port, clientId);
		client.setMktDataType(IB::DELAYED);

		while( client.isConnected()) {
			client.processMessages();
		}

		if( attempt >= MAX_ATTEMPTS) {
			break;
		}
		LOG(INFO) << "Sleeping " << SLEEP_TIME << " seconds before next attempt";
		sleep( SLEEP_TIME);
	}

	LOG(INFO) << "End of POSIX Socket Client Test";
}

