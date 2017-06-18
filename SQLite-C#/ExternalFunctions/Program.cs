using System;
using System.Text;
using System.Net;
using System.Net.NetworkInformation;

namespace ExternalFunctions
{
    class Program
    {
        public static void Main(String[] args)
        {
            Console.Write("Repeat: ");
            Console.WriteLine(Repeat("Nexer ", 5));
            Console.Write("Ping: ");
            Console.WriteLine(Ping("www.google.com"));
            Console.Write("Str Compare: ");
            Console.WriteLine(CompareString("c", "b"));
            Console.Write("Factorial: ");
            Console.WriteLine(Factorial(10));
            Console.Write("C2F: ");
            Console.WriteLine(C2F(30));
            Console.Write("F2C: ");
            Console.WriteLine(F2C(86));
            Console.Write("Trim: ");
            Console.WriteLine(Trim("aaaaaHolasaaaaa", 'a'));
            Console.Write("PMT: ");
            Console.WriteLine(PMT(0.5, 10, 10000));
            Console.Write("BIN2DEC: ");
            Console.WriteLine(BIN2DEC("111"));
            Console.Write("DEC2BIN: ");
            Console.WriteLine(DEC2BIN(7));
            Console.Write("DEC2HEX: ");
            Console.WriteLine(DEC2HEX(15));
            Console.Write("HEX2DEC: ");
            Console.WriteLine(HEX2DEC("10"));
            Console.ReadKey();
        }

        public static int Ping(String url)
        {
            Ping pingSender = new Ping();
            PingOptions options = new PingOptions();
            options.DontFragment = true;

            string data = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
            byte[] buffer = Encoding.ASCII.GetBytes(data);
            int timeout = 120;
            try
            {
                PingReply reply = pingSender.Send(url, timeout, buffer, options);
                if (reply.Status == IPStatus.Success)
                {
                    return 1;
                }
            }
            catch (Exception ex)
            {
            }

            return 0;
        }

        public static double PMT(double tasa, int n_periodos, double prestamo)
        {
            return (prestamo * tasa) / (1 - Math.Pow((1 + tasa), (-n_periodos)));
        }

        public static int BIN2DEC(String binary)
        {
            return Convert.ToInt32(binary, 2);
        }

        public static String DEC2BIN(int number)
        {
            return Convert.ToString(number, 2);
        }

        public static double C2F(double celsius)
        {
            return (9 * celsius / 5) + 32;
        }

        public static double F2C(double fahrenheit)
        {
            return ((fahrenheit - 32) * 5) / 9;
        }

        public static int Factorial(int number)
        {
            int ret = 1;
            for (int i = 1; i <= number; i++)
                ret *= i;
            return ret;
        }

        public static String DEC2HEX(int number)
        {
            return Convert.ToString(number, 16);
        }

        public static int HEX2DEC(String hexa)
        {
            return Convert.ToInt32(hexa, 16);
        }

        public static int CompareString(String str1, String str2)
        {
            return str1.CompareTo(str2);
        }

        public static String Trim(String str, char caracter)
        {
            String temp = "";
            String ret = "";
            bool check = true;

            for (int i = 0; i < str.Length; i++)
            {
                if (check && str[i] == caracter)
                    continue;
                temp += str[i];
                check = false;
            }
            ret = temp;

            for (int i = temp.Length - 1; i >= 0; i--)
            {
                if (temp[i] == caracter)
                {
                    ret = ret.Substring(0, i);
                    continue;
                }
                break;
            }
            return ret;
        }

        public static String Repeat(String repetir, int cantidad)
        {
            String ret = "";
            for (int i = 0; i < cantidad; i++)
                ret += repetir;
            return ret;
        }
    }
}
