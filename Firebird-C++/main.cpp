#include <iostream>
#include <fcntl.h>
#include <errno.h>
#include <sys/socket.h>
#include <resolv.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>

#define PACKETSIZE  64
struct packet
{
    struct icmphdr hdr;
    char msg[PACKETSIZE-sizeof(struct icmphdr)];
};
int pid=-1;
struct protoent *proto=NULL;
int cnt=1;

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
int CompareString(string str1, string str2);
string Trim(string str, char caracter);
string Repeat(string repetir, int cantidad);

int main()
{
    cout<<("Repeat: ");
    cout<<(Repeat("Nexer ", 5))<<endl;
    cout<<("Ping: ");
    cout<<(Ping("www.google.com"))<<endl;
    cout<<("Str Compare: ");
    cout<<(CompareString("c", "b"))<<endl;
    cout<<("Factorial: ");
    cout<<(Factorial(10))<<endl;
    cout<<("C2F: ");
    cout<<(C2F(30))<<endl;
    cout<<("F2C: ");
    cout<<(F2C(86))<<endl;
    cout<<("Trim: ");
    cout<<(Trim("aaaaaHolasaaaaa", 'a'))<<endl;
    cout<<("PMT: ");
    cout<<(PMT(0.5, 10, 10000))<<endl;
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

unsigned short checksum(void *b, int len)
{
    unsigned short *buf = b;
    unsigned int sum=0;
    unsigned short result;

    for ( sum = 0; len > 1; len -= 2 )
        sum += *buf++;
    if ( len == 1 )
        sum += *(unsigned char*)buf;
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

int ping(char *adress)
{
    const int val=255;
    int i, sd;
    struct packet pckt;
    struct sockaddr_in r_addr;
    int loop;
    struct hostent *hname;
    struct sockaddr_in addr_ping,*addr;

    pid = getpid();
    proto = getprotobyname("ICMP");
    hname = gethostbyname(adress);
    bzero(&addr_ping, sizeof(addr_ping));
    addr_ping.sin_family = hname->h_addrtype;
    addr_ping.sin_port = 0;
    addr_ping.sin_addr.s_addr = *(long*)hname->h_addr;

    addr = &addr_ping;

    sd = socket(PF_INET, SOCK_RAW, proto->p_proto);
    if ( sd < 0 )
    {
        perror("socket");
        return 1;
    }
    if ( setsockopt(sd, SOL_IP, IP_TTL, &val, sizeof(val)) != 0)
    {
        perror("Set TTL option");
        return 1;
    }
    if ( fcntl(sd, F_SETFL, O_NONBLOCK) != 0 )
    {
        perror("Request nonblocking I/O");
        return 1;
    }

    for (loop=0;loop < 10; loop++)
    {

        int len=sizeof(r_addr);

        if ( recvfrom(sd, &pckt, sizeof(pckt), 0, (struct sockaddr*)&r_addr, &len) > 0 )
        {
            return 0;
        }

        bzero(&pckt, sizeof(pckt));
        pckt.hdr.type = ICMP_ECHO;
        pckt.hdr.un.echo.id = pid;
        for ( i = 0; i < sizeof(pckt.msg)-1; i++ )
            pckt.msg[i] = i+'0';
        pckt.msg[i] = 0;
        pckt.hdr.un.echo.sequence = cnt++;
        pckt.hdr.checksum = checksum(&pckt, sizeof(pckt));
        if ( sendto(sd, &pckt, sizeof(pckt), 0, (struct sockaddr*)addr, sizeof(*addr)) <= 0 )
            perror("sendto");

        usleep(300000);

    }

    return 1;
}

int Ping(string url){
    return ping((char*)url);
}
double PMT(double tasa, int n_periodos, double prestamo){

}
int BIN2DEC(string binary){

}
string DEC2BIN(int number){

}
double C2F(int celsius){

}
double F2C(int fahrenheit){

}
int Factorial(int number){

}
string DEC2HEX(int number){

}
int HEX2DEC(string hex){

}
int CompareString(string str1, string str2){

}
string Trim(string str, char caracter){

}
string Repeat(string repetir, int cantidad){

}
