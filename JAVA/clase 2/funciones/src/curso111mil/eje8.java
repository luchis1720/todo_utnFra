package curso111mil;

import java.util.Scanner;

public class eje8 {

	public static void ej8() {
		// pedir números hasta que el usuario quiera, sumar los que son positivos y multiplicar los negativos.

		int sumapos=0, multneg=1, dato;
		String seguir;
		Scanner lector = new Scanner(System.in);
		
		do{
			
			System.out.println("ingrese un numero: ");
			dato= lector.nextInt();
			
			if(dato>0 || dato ==0)
			{
				sumapos= sumapos + dato; 
			}
			else
			{
				multneg= multneg * dato;
			}
			
			
			System.out.println("desea continuar? (s/n)");
			seguir= lector.nextLine();
					
					
			
		}while(seguir.equals("s"));
		
		System.out.println("la suma de los positivos es: " + sumapos + "\nel producto de los negativos es: " + multneg);
		
	}

}
