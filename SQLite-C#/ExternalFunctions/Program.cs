using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SQLite;
using System.Net.NetworkInformation;

namespace ExternalFunctions
{
    class Program
    {
        [SQLiteFunction(Name = "TRIM", Arguments = 2, FuncType = FunctionType.Scalar)]
        public class TrimSQLiteFunction : SQLiteFunction
        {
            public override object Invoke(object[] args)
            {
                String str = args[0].ToString();
                char caracter = args[1].ToString()[0];
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
        }

        [SQLiteFunction(Name = "REPEAT", Arguments = 2, FuncType = FunctionType.Scalar)]
        public class RepeatSQLiteFunction : SQLiteFunction
        {
            public override object Invoke(object[] args)
            {
                string repetir = args[0].ToString();
                int cantidad = int.Parse(args[1].ToString());

                String ret = "";
                for (int i = 0; i < cantidad; i++)
                    ret += repetir;
                return ret;
            }
        }

        [SQLiteFunction(Name = "COMPARESTRING", Arguments = 2, FuncType = FunctionType.Scalar)]
        public class CompareStringSQLiteFunction : SQLiteFunction
        {
            public override object Invoke(object[] args)
            {
                string str1 = args[0].ToString();
                string str2 = args[1].ToString();

                return str1.CompareTo(str2);
            }
        }

        [SQLiteFunction(Name = "DEC2HEX", Arguments = 1, FuncType = FunctionType.Scalar)]
        public class Dec2HexSQLiteFunction : SQLiteFunction
        {
            public override object Invoke(object[] args)
            {
                int number = int.Parse(args[0].ToString());
                return Convert.ToString(number, 16);
            }
        }

        [SQLiteFunction(Name = "HEX2DEC", Arguments = 1, FuncType = FunctionType.Scalar)]
        public class Hex2DecSQLiteFunction : SQLiteFunction
        {
            public override object Invoke(object[] args)
            {
                string value = args[0].ToString();
                int decValue = int.Parse(value, System.Globalization.NumberStyles.HexNumber);
                return decValue.ToString();
            }
        }

        [SQLiteFunction(Name = "FACTORIAL", Arguments = 1, FuncType = FunctionType.Scalar)]
        public class FactorialSQLiteFunction : SQLiteFunction
        {
            public override object Invoke(object[] args)
            {
                int number = int.Parse(args[0].ToString());
                int ret = 1;
                for (int i = 1; i <= number; i++)
                    ret *= i;
                return ret;
            }
        }

        [SQLiteFunction(Name = "C2F", Arguments = 1, FuncType = FunctionType.Scalar)]
        public class C2FSQLiteFunction : SQLiteFunction
        {
            public override object Invoke(object[] args)
            {
                double celsius = Convert.ToDouble(args[0].ToString());
                return (9 * celsius / 5) + 32;
            }
        }

        [SQLiteFunction(Name = "F2C", Arguments = 1, FuncType = FunctionType.Scalar)]
        public class F2CSQLiteFunction : SQLiteFunction
        {
            public override object Invoke(object[] args)
            {
                double fahrenheit = Convert.ToDouble(args[0].ToString());
                return ((fahrenheit - 32) * 5) / 9;
            }
        }

        [SQLiteFunction(Name = "DEC2BIN", Arguments = 1, FuncType = FunctionType.Scalar)]
        public class Dec2BinSQLiteFunction : SQLiteFunction
        {
            public override object Invoke(object[] args)
            {
                int number = int.Parse(args[0].ToString());
                return Convert.ToString(number, 2);
            }
        }

        [SQLiteFunction(Name = "BIN2DEC", Arguments = 1, FuncType = FunctionType.Scalar)]
        public class Bin2DecSQLiteFunction : SQLiteFunction
        {
            public override object Invoke(object[] args)
            {
                String binary = args[0].ToString();
                return Convert.ToInt32(binary, 2);
            }
        }

        [SQLiteFunction(Name = "PMT", Arguments = 3, FuncType = FunctionType.Scalar)]
        public class PmtSQLiteFunction : SQLiteFunction
        {
            public override object Invoke(object[] args)
            {
                double tasa = Double.Parse(args[0].ToString());
                int n_periodos = int.Parse(args[1].ToString());
                double prestamo = Double.Parse(args[2].ToString());
                return (prestamo * tasa) / (1 - Math.Pow((1 + tasa), (-n_periodos)));
            }
        }

        [SQLiteFunction(Name = "PING", Arguments = 1, FuncType = FunctionType.Scalar)]
        public class PingSQLiteFunction : SQLiteFunction
        {
            public override object Invoke(object[] args)
            {
                String url = args[0].ToString();
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
        }

        static void BindFunction(SQLiteConnection connection, SQLiteFunction function)
        {
            var attributes = function.GetType().GetCustomAttributes(typeof(SQLiteFunctionAttribute), true).Cast<SQLiteFunctionAttribute>().ToArray();
            if (attributes.Length == 0)
            {
                throw new InvalidOperationException("SQLiteFunction doesn't have SQLiteFunctionAttribute");
            }
            connection.BindFunction(attributes[0], function);
        }

        static void Main(string[] args)
        {

            var conn = new SQLiteConnection("Data Source=C:\\sqlite\\test.db");
            conn.Open();

            BindFunction(conn, new PmtSQLiteFunction());
            BindFunction(conn, new PingSQLiteFunction());
            BindFunction(conn, new Bin2DecSQLiteFunction());
            BindFunction(conn, new Dec2BinSQLiteFunction());
            BindFunction(conn, new F2CSQLiteFunction());
            BindFunction(conn, new C2FSQLiteFunction());
            BindFunction(conn, new FactorialSQLiteFunction());
            BindFunction(conn, new Dec2HexSQLiteFunction());
            BindFunction(conn, new Hex2DecSQLiteFunction());
            BindFunction(conn, new Hex2DecSQLiteFunction());
            BindFunction(conn, new CompareStringSQLiteFunction());
            BindFunction(conn, new RepeatSQLiteFunction());
            BindFunction(conn, new TrimSQLiteFunction());

            while (true)
            {
                try
                {
                    string sql = Console.ReadLine().ToLower();

                    string[] split = sql.Split(null);

                    if (split.Length == 0)
                        continue;

                    SQLiteCommand command = new SQLiteCommand(sql, conn);
                    if (split[0] == "select")
                    {
                        SQLiteDataReader reader = command.ExecuteReader();
                        PrintReader(reader);
                    }
                    else
                        command.ExecuteNonQuery();


                }
                catch (Exception e)
                {

                }
            }
        }

        private static void PrintReader(SQLiteDataReader reader)
        {
            while (reader.Read())
            {
                for (int i = 0; i < reader.FieldCount; ++i)
                {
                    var column_name = reader.GetName(i).ToString();
                    Console.Write(column_name + ": " + reader[column_name] + " ");
                }
                Console.WriteLine();
            }


            Console.Read();
        }


    }
}
