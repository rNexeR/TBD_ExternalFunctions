gcc -c -Wall -Werror -fpic -Iusr/include -I/usr/lib/firebird/2.5/examples/include  $1.c
gcc -Iusr/include -shared -o $1.so $1.o

sudo rm -rf /usr/lib/firebird/2.5/UDF/$1.so
sudo cp $1.so /usr/lib/firebird/2.5/UDF