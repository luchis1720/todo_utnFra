package repetitivas;

import java.sql.Savepoint;
import java.util.Scanner;

public class main {

	public static void main(String[] args) {
		
		String nombre;
		int edad;
		int num;
		int i = 0;
		
		Scanner lector = new Scanner (System.in);
		
		do{
		
		System.out.println("ingrese un nombre: ");
		nombre= lector.nextLine();
		
		System.out.println("su nombre es : " + nombre);
		
		System.out.println("ingrese su edad: ");
		edad= Integer.parseInt(lector.nextLine());
		
		System.out.println("su edad es : " + edad);
		
		System.out.println("ingrese un numero: ");
		num = Integer.parseInt(lector.nextLine());
		
		if(num>=edad)
		{
			System.out.println("el numero ingresado es mayor a la edad ");
		}
		else
		{
			System.out.println("su edad es mayor al numero ingresado");
		}
		
		i= i+1;
		
		}while(i<3);
	}

}
