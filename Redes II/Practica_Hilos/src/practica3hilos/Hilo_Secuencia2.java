package practica3hilos;

import java.util.Random;
import javax.swing.JTextArea;

public class Hilo_Secuencia2 extends Object implements Runnable {

    int bandera;
    int c;
    int par;
    JTextArea areaSecuencia2;
    String Secuencia2;

    public Hilo_Secuencia2(JTextArea textArea) {
        // TODO Auto-generated constructor stub
        bandera = 0;
        c = 0;
        par = 0;
        this.areaSecuencia2 = textArea;
    }

    Hilo_Secuencia2() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    public void numRandom() {
        Random r = new Random();
        int n = r.nextInt(199) + 1;
        areaSecuencia2.append(n+"\n");
    }

    public void Par() {
        par += 2;
        areaSecuencia2.append(par + "\n");
    }

    public void run() {
        while (c < 10) {
            try {
                work2();
            } catch (InterruptedException x) {
                if (bandera == 0) {
                    areaSecuencia2.append("------------------------------------------- \n Secuencia de Números Pares\n-------------------------------------------\n");
                    Secuencia2= "Secuencia Pares\n";
                    bandera = 1;
                } else {
                    areaSecuencia2.append("------------------------------------------- \n Números Aleatorios\n-------------------------------------------\n");
                    Secuencia2="Numeros Aleatorios\n";
                    bandera = 0;
                }
                c++;
                if (c == 10) {
                    areaSecuencia2.append("Hilo2 ha terminado");
                    Secuencia2="Hilo2 Terminado";
                }
            }
        }
    }

    public void work2() throws InterruptedException {
        while (true) {
            if (bandera == 0) {
                numRandom();
            } else {
                Par();
            }
            Thread.sleep(500);
        }
    }
}
