package curso111mil;

import java.util.Scanner;

public class eje3 {

	public static void ej3() {
		//  PEDIR LA CLAVE (UTNFRA) "WHILE"
		
		String clave; 
		Scanner lector = new Scanner (System.in);
		
		
		System.out.println("ingrese la clave: ");
			
		clave = lector.nextLine();
		
		while (!clave.equals("UTNFRA")){ // while (clave != UTNFRA)
			
			System.out.println("ERROR. Re-ingrese la clave: ");
			
				
			clave = lector.nextLine();
		}
		
		System.out.println("Clave correcta");
		

	}

}
