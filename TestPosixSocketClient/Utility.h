#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <net/if.h>

#include <string.h>
#include <string>

#include <unistd.h>
#include <sys/ioctl.h>
#include <stdio.h>

namespace Utility
{
        std::string getLocalHostIp();
}
