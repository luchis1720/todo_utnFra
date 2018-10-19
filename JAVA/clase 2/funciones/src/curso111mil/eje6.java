package curso111mil;

import java.util.Scanner;

public class eje6 {

	public static void ej6() {
		//  pedir 5 números e informar la suma acumulada y el promedio

		Scanner lector = new Scanner (System.in);
		int acum=0, dato, promedio, cont=0;
		
		
		
		
		for(int i=0;i<5;i++)
		{
			System.out.println("por favor, ingrese un numero:");
			dato= lector.nextInt();
			
			acum= acum + dato;
			cont++;
		}
		promedio= acum / cont;
		
		System.out.println("la suma acumulada es: " + acum + "\nel promedio es: " + promedio);
		
	}

}
