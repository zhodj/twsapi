#include "Utility.h"

namespace Utility
{
        std::string getLocalHostIp()
        {
                int fd, intrface;
                long ip = -1;
                char szBuf[128] = {0};
                struct ifreq buf[16];
                struct ifconf ifc;

                if((fd=socket (AF_INET, SOCK_DGRAM, 0)) >= 0)
                {
                        ifc.ifc_len = sizeof buf;
                        ifc.ifc_buf = (caddr_t) buf;
                        if (!ioctl(fd, SIOCGIFCONF, (char*)&ifc))
                        {
                                intrface = ifc.ifc_len / sizeof(struct ifreq);
                                while(intrface-- > 0)
                                {
                                        if (!(ioctl (fd, SIOCGIFADDR, (char *) &buf[intrface])))
                                        {
                                                ip=inet_addr(inet_ntoa(((struct sockaddr_in*)(&buf[intrface].ifr_addr))->sin_addr));
                                                break;
                                        }
                                }
                        }
                        close (fd);
                }

                // 转换为.格式
                unsigned char* pIp = (unsigned char*)(&ip);
                snprintf(szBuf, sizeof(szBuf), "%u.%u.%u.%u", pIp[0], pIp[1], pIp[2], pIp[3]);

                return szBuf;
        }
}
