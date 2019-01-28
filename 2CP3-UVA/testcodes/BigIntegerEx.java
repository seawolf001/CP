import java.util.Scanner;
import java.math.BigInteger;

class BigIntegerFactorial{
	public static void main(String args[]){
		// Scanner in = new Scanner(System.in);
		BigInteger b = BigInteger.valueOf(1);
		for(int i=2;i<=25;i++){
			b = b.multiply(BigInteger.valueOf(i));
		}
		System.out.println("25! = "+b);
	}
}