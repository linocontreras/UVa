/**---------------------------------------------------------
 * 
 * Actividad de programación: Problema 787 de UVA
 * Fecha: 26-Nov-2017
 * Autor: A01700457 - Lino Contreras
 * 
 * ---------------------------------------------------------*/

import java.util.ArrayList;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        ArrayList<BigInteger> numbers = new ArrayList<BigInteger>(200);
        BigInteger max, tmp, end = new BigInteger("-999999");
        while(input.hasNext()){
            tmp = input.nextBigInteger();
            max = tmp;
            while(true){
                if(tmp.equals(end))
                    break;
                numbers.add(tmp);
                tmp = input.nextBigInteger();
                if(tmp.compareTo(max) > 0)
                    max = tmp;
            }
            int size = numbers.size();
            BigInteger mat[][] = new BigInteger[size+1][size];
            for(int i = 0; i < size; i++){
                mat[1][i] = numbers.get(i);
            }

            for(int i = 0; i < size; i++){
                for(int j = 2; i + j <= size; j++ ){
                    tmp = mat[j-1][i].multiply(numbers.get(j + i - 1));
                    mat[j][i] = tmp;
                    if(tmp.compareTo(max) > 0)
                        max = tmp;
                }
            }
            System.out.println(max);
            numbers.clear();
        }

    }
}