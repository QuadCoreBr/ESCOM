package practica3hilos;

import javax.swing.JTextArea;

public class Hilo_Secuencia1 extends Object implements Runnable {

    int bandera;
    int c;
    int f1, f2;
    int primo;
    JTextArea areaSecuencia1;
    String Secuencia1;

    public Hilo_Secuencia1(JTextArea txtArea) {
        // TODO Auto-generated constructor stub
        bandera = 0;
        c = 0;
        f1 = 0;
        f2 = 1;
        primo = 3;
        this.areaSecuencia1 = txtArea;
    }

    Hilo_Secuencia1() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    public void Fibo() {
        int f;
        f = f1 + f2;
        f1 = f2;
        f2 = f;
        areaSecuencia1.append(f + "\n");
    }

    private static boolean esPrimo(int numero) {
        int contador = 2;
        boolean primo = true;
        while ((primo) && (contador != numero)) {
            if (numero % contador == 0) {
                primo = false;
            }
            contador++;
        }
        return primo;
    }

    public void Primo() {
        if (primo < 1000) {
            primo = primo + 2;
        } else {
            areaSecuencia1.append(1 + "\n");
            areaSecuencia1.append(2 + "\n");
            areaSecuencia1.append(3 + "\n");
            primo = 3;
        }
        if (esPrimo(primo)) {
            areaSecuencia1.append(primo + "\n");
        } else {
            Primo();
        }
    }

    public void run() {
        while (c < 10) {
            try {
                work2();
            } catch (InterruptedException x) {
                if (bandera == 0) {
                    areaSecuencia1.append("------------------------------------------- \n Secuencia de Números Primos\n-------------------------------------------\n");
                    Secuencia1="Secuencia números Primos \n";
                    bandera = 1;
                } else {
                    areaSecuencia1.append("------------------------------------------- \n Secuencia Fibonacci\n-------------------------------------------\n");
                    Secuencia1="Secuencia Fibonacci\n";
                    bandera = 0;
                }
                c++;
                if (c == 10) {
                    areaSecuencia1.append("Hilo 1 ha terminado");
                    Secuencia1="Hilo1 terminado";
                }
            }
        }
    }

    public void work2() throws InterruptedException {
        while (true) {
            if (bandera == 0) {
                if (f1 == 0) {
                    areaSecuencia1.append(0 + "\n");
                    Thread.sleep(500);
                    areaSecuencia1.append(1 + "\n");
                    Thread.sleep(500);
                }
                Fibo();
            } else {
                if (primo == 3) {
                    areaSecuencia1.append(1 + "\n");
                    
                    Thread.sleep(500);
                    areaSecuencia1.append(2 + "\n");
                    Thread.sleep(500);
                    areaSecuencia1.append(3 + "\n");
                    Thread.sleep(500);
                }
                Primo();
            }
            Thread.sleep(500);
        }
    }
}
