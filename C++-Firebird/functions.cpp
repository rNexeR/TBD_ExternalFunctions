#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include <iostream>
#include <math.h>
#include <string>
#include <bitset>

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
    cout<<("Ping: ");
    cout<<(Ping("www.google.com"))<<endl;
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


int Ping(string url)
{
    return 0;
}

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

    for(unsigned int i = 0; i < str.length(); i++)
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
