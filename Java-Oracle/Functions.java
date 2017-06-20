import java.net.Socket;
import java.net.InetSocketAddress;
import java.io.IOException;

public class Functions{
    public static void main(String[] args){
        System.out.print("Repeat: ");
        System.out.println(Repeat("Nexer ", 5));
        System.out.print("Ping: ");
        System.out.println(Ping("www.google.com"));
        System.out.print("Str Compare: ");
        System.out.println( CompareString("c", "b"));
        System.out.print("Factorial: ");
        System.out.println( Factorial(10));
        System.out.print("C2F: ");
        System.out.println( C2F(30));
        System.out.print("F2C: ");
        System.out.println( F2C(86));
        System.out.print("Trim: ");
        System.out.println( StrTrim("aaaaaHolasaaaaa", "a"));
        System.out.print("PMT: ");
        System.out.println( PMT(0.5, 10, 10000));
        System.out.print("BIN2DEC: ");
        System.out.println( BIN2DEC("111"));
        System.out.print("DEC2BIN: ");
        System.out.println( DEC2BIN(7));
        System.out.print("DEC2HEX: ");
        System.out.println( DEC2HEX(15));
        System.out.print("HEX2DEC: ");
        System.out.println( HEX2DEC("10"));

        // System.out.print(": ");
        // System.out.println( ());
    }

    public static int Ping(String url){
        try {
            new Socket().connect(new InetSocketAddress(url, 80), 5000);
            return 1;
        }
        catch(IOException ex) {
            return 0;
        }
    }

    public static double PMT(double tasa, int n_periodos, double prestamo){
        return (prestamo*tasa) / (1 - Math.pow((1 + tasa),(-n_periodos)));
    }

    public static int BIN2DEC(String binary){
        return Integer.parseInt(binary, 2);
    }

    public static String DEC2BIN(int number){
        return Integer.toBinaryString(number);
    }

    public static double C2F(double celsius){
        return (9*celsius/5) + 32;
    }

    public static double F2C(double fahrenheit){
        return ((fahrenheit - 32)*5)/9;
    }

    public static int Factorial(int number){
        int ret = 1;
        for(int i = 1; i <= number; i++)
            ret *= i;
        return ret;
    }

    public static String DEC2HEX(int number){
        return Integer.toHexString(number);
    }

    public static int HEX2DEC(String hexa){
        return Integer.parseInt(hexa, 16);
    }

    public static int CompareString(String str1, String str2){
        return str1.compareTo(str2);
    }

    public static String StrTrim(String str, String trim){
        char caracter = trim.charAt(0);
        String temp = "";
        String ret = "";
        Boolean check = true;

        for(int i = 0; i < str.length(); i++){
            if(check && str.charAt(i) == caracter)
                continue;
            temp += str.charAt(i);
            check = false;
        }
        ret = temp;

        for(int i = temp.length() -1; i >= 0; i--){
            if(temp.charAt(i) == caracter){
                ret = ret.substring(0, i);
                continue;
            }
            break;
        }
        return ret;
    }

    public static String Repeat(String repetir, int cantidad){
        String ret = "";
        for(int i = 0; i < cantidad; i++)
            ret += repetir;
        return ret;
    }   
}