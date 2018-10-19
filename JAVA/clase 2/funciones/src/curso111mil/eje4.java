package curso111mil;

import java.util.Scanner;

public class eje4 {

	public static void ej4() {
		// pedir un numero del cero al nueve inclusive

		int num;
		
		Scanner lector = new Scanner (System.in);
		
		System.out.println("ingrese un numero:");
		num = lector.nextInt();
		
		
		while(num<0 || num>9)
		{
			System.out.println("Error ingrese un valor entre cero y nueve inclusive");
			num = lector.nextInt();
			
		
		}
		
		System.out.println("el numero ingresado es: " + num);
		
	}

	

	

}
