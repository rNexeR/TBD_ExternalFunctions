int ctof(int *);
int ctof(celsius)
	int *celsius;
{
    return (9*(*celsius)/5) + 32;
}

int ftoc(int *);
int ftoc(fahrenheit)
	int *fahrenheit;
{
    return (((*fahrenheit) - 32)*5)/9;
}

int factorial(int *);
int factorial(number)
	int *number;
{
    int ret = 1;
    int i;
    for(i = 1; i <= (*number); i++)
        ret *= i;
    return ret;
}