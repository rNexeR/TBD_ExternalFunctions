int modulo(int *, int *);

int modulo(a, b) int *a;
int *b;
{
    if (*b == 0)
        return -1; // return something suitably stupid.
    else
        return *a % *b;
}