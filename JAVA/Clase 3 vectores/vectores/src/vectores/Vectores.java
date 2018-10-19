
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package vectores;

import java.util.Scanner;

/**
 *
 * @author alumno
 */
public class Vectores {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
    
    int[] vector = new int[10];
    int i;
    int contneg=0;
    int contpos=0;
    int contcero=0;
    
    Scanner lector = new Scanner (System.in);
    
    for (i=0;i<10;i++)
    {
        System.out.println("ingrese un numero: ");
        vector[i] = Integer.parseInt(lector.nextLine());
    }
     for (i=0;i<10;i++) 
     {
        
        if(vector[i] == 0)
        {
            contcero++;
        }
        if (vector[i]>0)
        {
            contpos++;
        }
        else 
                {
                    contneg++;
                }
                
        
    }

     System.out.println("los numeros positivos son: " + contpos + " los negativos son: " + contneg + " los iguales a cero: " + contcero);    

    
    }
    
    
    
    
}
