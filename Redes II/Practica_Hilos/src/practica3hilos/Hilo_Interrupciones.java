package practica3hilos;

import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JTextArea;

public class Hilo_Interrupciones extends Thread {

    Hilo1 H1;
    Hilo2 H2;
    int contador,interrupcion;
    public JTextArea txtArea1, txtArea2, txtArea3, txtArea4;
    long id;
    String nombre,estado;

    public Hilo_Interrupciones(JTextArea txt1, JTextArea txt2, JTextArea txt3, JTextArea txt4) {
        // TODO Auto-generated constructor stub

        this.txtArea1 = txt1;
        this.txtArea2 = txt2;
        this.txtArea3 = txt3;
        this.txtArea4 = txt4;
        H1 = new Hilo1(txtArea3);
        H2 = new Hilo2(txtArea4);
    }

    Hilo_Interrupciones(Hilo_Secuencia1 h1, Hilo_Secuencia2 h2) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    
    public class Hilo1 extends Thread {

        JTextArea area3;
        String estado;
        //String interrupcion;
      
        

        private Hilo1(JTextArea txtArea3) {
            area3 = txtArea3;
        }

        @Override
        public void run() {
            
            Hilo_Secuencia1 s1 = new Hilo_Secuencia1(txtArea1);
            Thread t1 = new Thread(s1);
            id= t1.getId();
            nombre= t1.getName();
            t1.start();
            estado= "Estado del Hilo:Corriendo";
             
            for (contador = 1; contador< 11; contador++) {
                try {
                    Thread.sleep(2000);
                } catch (InterruptedException x) {
                    Logger.getLogger(Hilo_Interrupciones.class.getName()).log(Level.SEVERE, null, x);
                }
                area3.append("Interrupcion número: " + contador + "\n");
                t1.interrupt();
                estado= "Estado del Hilo:Interrumpido ";
                interrupcion++;
                
            }
        }
    }

    
    
    public class Hilo2 extends Thread {

        JTextArea area4;
        String estado;

        private Hilo2(JTextArea txtArea4) {
            area4 = txtArea4;
        }

        @Override
        public void run() {
            
            Hilo_Secuencia2 s2 = new Hilo_Secuencia2(txtArea2);
            Thread t2 = new Thread(s2);
            id= t2.getId();
            t2.start();
            for (int i = 1; i < 11; i++) {
                try {
                    Thread.sleep(3000);
                } catch (InterruptedException x) {
                    Logger.getLogger(Hilo_Interrupciones.class.getName()).log(Level.SEVERE, null, x);
                }
                area4.append("Interrupcion número: " + i + "\n");
                t2.interrupt();
                interrupcion++;
            }
        }
    }

    @Override
    public void run() {
        // TODO Auto-generated method stub
        H1.start();
        H2.start();
    }
    

}
