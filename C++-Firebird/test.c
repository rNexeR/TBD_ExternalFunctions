

#include <iostream>
#include <math.h>
#include <string>
#include <bitset>

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
    cout << ("Repeat: ");
    cout << (Repeat("Nexer ", 5)) << endl;
    cout << ("Ping: ");
    cout << (Ping("www.google.com")) << endl;
    cout << ("Str Compare: ");
    cout << (Comparestring("c", "b")) << endl;
    cout << ("Factorial: ");
    cout << (Factorial(10)) << endl;
    cout << ("C2F: ");
    cout << (C2F(30)) << endl;
    cout << ("F2C: ");
    cout << (F2C(86)) << endl;
    cout << ("Trim: ");
    cout << (Trim("aaaaaHolasaaaaa", 'a')) << endl;
    cout << ("PMT: ");
    cout << (PMT(0.5, 10, 10000)) << endl;
    cout << ("BIN2DEC: ");
    cout << (BIN2DEC("111")) << endl;
    cout << ("DEC2BIN: ");
    cout << (DEC2BIN(7)) << endl;
    cout << ("DEC2HEX: ");
    cout << (DEC2HEX(15)) << endl;
    cout << ("HEX2DEC: ");
    cout << (HEX2DEC("10")) << endl;
    return 0;
}

int Ping(string url)
{
    return 0;
}

double PMT(double tasa, int n_periodos, double prestamo)
{
    return (prestamo * tasa) / (1 - pow((1 + tasa), (-n_periodos)));
}

int BIN2DEC(char* binary)
{
    char *start = &binaryCharArray[0];
    int total = 0;
    while (*start)
    {
        total *= 2;
        if (*start++ == '1')
            total += 1;
    }
}

char *DEC2BIN(int number)
{
    return bitset<8>(number).to_string();
}
