/*
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <sys/file.h>
#include <sys/time.h>
#include <netinet/in_systm.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <stdint.h>
*/
#include <iostream>
#include <math.h>
#include <string>
#include <bitset>#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define	DEFDATALEN	(64-ICMP_MINLEN)
#define	MAXIPLEN	60
#define	MAXICMPLEN	76
#define	MAXPACKET	(65536 - 60 - ICMP_MINLEN)

using namespace std;

int Ping(string url);
double PMT(double tasa, int n_periodos, double prestamo);
int BIN2DEC(string binary);
string DEC2BIN(int number);
double C2F(int celsius);
double F2C(int fahrenheit);
int Factorial(int number);
string DEC2HEX(int number);
int HEX2DEC(string hex);
int Comparestring(string str1, string str2);
string Trim(string str, char caracter);
string Repeat(string repetir, int cantidad);

int main()
{
    cout<<("Repeat: ");
    cout<<(Repeat("Nexer ", 5))<<endl;
    //cout<<("Ping: ");
    //cout<<(Ping("www.google.com"))<<endl;
    cout<<("Str Compare: ");
    cout<<(Comparestring("c", "b"))<<endl;
    cout<<("Factorial: ");
    cout<<(Factorial(10))<<endl;
    cout<<("C2F: ");
    cout<<(C2F(30))<<endl;
    cout<<("F2C: ");
    cout<<(F2C(86))<<endl;
    cout<<("Trim: ");
    cout<<(Trim("aaaaaHolasaaaaa", 'a'))<<endl;
    cout<<("PMT: ");
    cout<<(PMT(1, 10, 10000))<<endl;
    cout<<("BIN2DEC: ");
    cout<<(BIN2DEC("111"))<<endl;
    cout<<("DEC2BIN: ");
    cout<<(DEC2BIN(7))<<endl;
    cout<<("DEC2HEX: ");
    cout<<(DEC2HEX(15))<<endl;
    cout<<("HEX2DEC: ");
    cout<<(HEX2DEC("10"))<<endl;
    return 0;
}

/*
uint16_t in_cksum(uint16_t *addr, unsigned len)
{
    uint16_t answer = 0;
    uint32_t sum = 0;
    while (len > 1)
    {
        sum += *addr++;
        len -= 2;
    }

    if (len == 1)
    {
        *(unsigned char *)&answer = *(unsigned char *)addr ;
        sum += answer;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = ~sum;
    return answer;
}

int Ping(string url)
{
    int s, i, cc, packlen, datalen = DEFDATALEN;
    struct hostent *hp;
    struct sockaddr_in to, from;
    struct ip *ip;
    u_char *packet, outpack[MAXPACKET];
    char hnamebuf[MAXHOSTNAMELEN];
    string hostname;
    struct icmp *icp;
    int ret, fromlen, hlen;
    fd_set rfds;
    struct timeval tv;
    int retval;
    struct timeval start, end;
    int end_t;
    bool cont = true;

    to.sin_family = AF_INET;

    to.sin_addr.s_addr = inet_addr(url.c_str());
    if (to.sin_addr.s_addr != (u_int)-1)
        hostname = url;
    else
    {
        hp = gethostbyname(url.c_str());
        if (!hp)
        {
            return 0;
        }
        to.sin_family = hp->h_addrtype;
        bcopy(hp->h_addr, (caddr_t)&to.sin_addr, hp->h_length);
        strncpy(hnamebuf, hp->h_name, sizeof(hnamebuf) - 1);
        hostname = hnamebuf;
    }
    packlen = datalen + MAXIPLEN + MAXICMPLEN;
    if ( (packet = (u_char *)malloc((u_int)packlen)) == NULL)
    {
        return 0;
    }


    if ( (s = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
    {
        return 0;
    }

    icp = (struct icmp *)outpack;
    icp->icmp_type = ICMP_ECHO;
    icp->icmp_code = 0;
    icp->icmp_cksum = 0;
    icp->icmp_seq = 12345;
    icp->icmp_id = getpid();


    cc = datalen + ICMP_MINLEN;
    icp->icmp_cksum = in_cksum((unsigned short *)icp,cc);

    gettimeofday(&start, NULL);

    i = sendto(s, (char *)outpack, cc, 0, (struct sockaddr*)&to, (socklen_t)sizeof(struct sockaddr_in));
    if (i < 0 || i != cc)
    {
        if (i < 0)
            perror("sendto error");
    }

    FD_ZERO(&rfds);
    FD_SET(s, &rfds);
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    while(cont)
    {
        retval = select(s+1, &rfds, NULL, NULL, &tv);
        if (retval == -1)
        {
            return 0;
        }
        else if (retval)
        {
            fromlen = sizeof(sockaddr_in);
            if ( (ret = recvfrom(s, (char *)packet, packlen, 0,(struct sockaddr *)&from, (socklen_t*)&fromlen)) < 0)
            {
                return 0;
            }

            // Check the IP header
            ip = (struct ip *)((char*)packet);
            hlen = sizeof( struct ip );
            if (ret < (hlen + ICMP_MINLEN))
            {
                return 0;
            }

            // Now the ICMP part
            icp = (struct icmp *)(packet + hlen);
            if (icp->icmp_type == ICMP_ECHOREPLY)
            {
                if (icp->icmp_seq != 12345)
                {
                    continue;
                }
                if (icp->icmp_id != getpid())
                {
                    continue;
                }
                cont = false;
            }
            else
            {
                cout << "Recv: not an echo reply" << endl;
                continue;
            }

            gettimeofday(&end, NULL);
            end_t = 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);

            if(end_t < 1)
                end_t = 1;

            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
*/
double PMT(double tasa, int n_periodos, double prestamo)
{
    return (prestamo*tasa) / (1 - pow((1 + tasa),(-n_periodos)));
}

int BIN2DEC(string binary)
{
    return bitset<8>(binary).to_ulong();
}

string DEC2BIN(int number)
{
    return bitset<8>(number).to_string();
}

double C2F(int celsius)
{
    return (9*celsius/5) + 32;
}

double F2C(int fahrenheit)
{
    return ((fahrenheit - 32)*5)/9;
}

int Factorial(int number)
{
    int ret = 1;
    for(int i = 1; i <= number; i++)
        ret *= i;
    return ret;
}

string DEC2HEX(int number)
{
    char ret[20];
    sprintf(ret,"%x",number);
    return (string)ret;
}

int HEX2DEC(string hex_val)
{
    int number = (int)strtol(hex_val.c_str(), NULL, 16);
    return number;
}

int Comparestring(string str1, string str2)
{
    return str1.compare(str2);
}

string Trim(string str, char caracter)
{
    string temp = "";
    string ret = "";
    bool check = true;

    for(int i = 0; i < str.length(); i++)
    {
        if(check && str[i] == caracter)
            continue;
        temp += str[i];
        check = false;
    }
    ret = temp;

    for(int i = temp.length() -1; i >= 0; i--)
    {
        if(temp[i] == caracter)
        {
            ret = ret.substr(0, i);
            continue;
        }
        break;
    }
    return ret;
}

string Repeat(string repetir, int cantidad)
{
    string ret = "";
    for(int i = 0; i < cantidad; i++)
        ret += repetir;
    return ret;
}
