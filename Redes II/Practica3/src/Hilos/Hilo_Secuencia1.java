/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Hilos;

import Control.UIControl;
import Vista.UI;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JTextArea;
/**
 *
 * @author Bryan Ramos
 */
public class Hilo_Secuencia1 implements Runnable{
    char letraActual;
    int letraActualNum;
    int valorPrimoActual;
    int bandera;
    int maxInterruptions;
    int contadorInterrupcion;
    UIControl control;
    
    
    public Hilo_Secuencia1(char letraActual, int valorPrimoInicial,int maxInterruptions,UIControl control){
        this.letraActual = letraActual;
        letraActualNum = letraActual;
        valorPrimoActual = valorPrimoInicial;
        this.maxInterruptions = maxInterruptions;
        contadorInterrupcion = 0;
        this.control = control;
    }
    public synchronized void generarABC() {
        //System.out.println("ENTRE A GENERAR");
            while(true){
            try {
                Thread.sleep(200);
                System.out.println(getABCActual());
                control.mostrarHilo1("Letra: " + Character.toString(getABCActual()));

                //letraActualNum = getABCActual();
                //System.out.println(letraActualNum);
                setABCActual((char) (letraActual+1));
                if (getABCActual() == 'Z'+1){
                    setABCActual('A');
                }
            } catch (InterruptedException ex) {
                control.mostrarHilo1("---------INTERRUPCIÓN-------");
                System.out.println("Interrumpido imprimiendo abc:");
                setBandera(1);
                increaseInterruptions();
                //System.out.println("VALOR CONTADOR:" + getInterruptionsCounter());
                break;
               // Logger.getLogger(Hilo_Secuencia1.class.getName()).log(Level.SEVERE, null, ex);
            }
            }
    }
    public void generarPrimos() {
        /*if (primo < 1000) {
            primo = primo + 2;
        } else {
            //areaSecuencia1.append(1 + "\n");
            //areaSecuencia1.append(2 + "\n");
            //areaSecuencia1.append(3 + "\n");
            primo = 3;
        }
        if (esPrimo(primo)) {
            areaSecuencia1.append(primo + "\n");
        } else {
            Primo();
        }*/
        for(int i = getPrimoActual()+1; i<1000; i++){
            if(esPrimo(i)){
                try {
                    Thread.sleep(200);
                    control.mostrarHilo1("Número primo: "+Integer.toString(i));
                    System.out.println("Numero primo: " + i);
                    setPrimoActual(i);
                } catch (InterruptedException ex) {
                    control.mostrarHilo1("---------INTERRUPCIÓN-------");
                    System.out.println("Interrumpido Imprimiendo Primos");
                    setBandera(0);
                    increaseInterruptions();
                    //System.out.println("VALOR CONTADOR PRIMO:" + getInterruptionsCounter());
                    break;
                    //Logger.getLogger(Hilo_Secuencia1.class.getName()).log(Level.SEVERE, null, ex);
                }
                
            }
        }
    }
    private boolean esPrimo(int number) {
        for(int check = 2; check < number; ++check) {
            if(number % check == 0) {
                return false;
            }
        }
        return true;
    }
    public void setPrimoActual(int i){
        valorPrimoActual = i;
    }
    public int getPrimoActual(){
        return valorPrimoActual;
    }
    public void initValorPrimoActual(int initPrimo){
        valorPrimoActual = initPrimo;
    }
    public void setABCActual(char letra){
        letraActual = letra;
    }
    public char getABCActual(){
        return letraActual;
    }
    public synchronized void setBandera(int bandera){
        this.bandera = bandera;
    }
    public synchronized int getBandera(){
        return bandera;
    }
    public synchronized void increaseInterruptions(){
        contadorInterrupcion++;
    }
    public synchronized int getInterruptionsCounter(){
        return contadorInterrupcion;
    }
    @Override
    public void run() {
        try {
            //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
            Thread.sleep(100);
            while(true){
                if(getInterruptionsCounter()== maxInterruptions){
                    control.mostrarHilo1("FIN HILO 1");
                    System.out.println("Finalizando Hilo 1");
                    break;
                }
                if(getBandera() == 0){
                    //System.out.println("Imprimiendo ABC");
                    generarABC();
                }
                if(getBandera() == 1){
                    //System.out.println("Imprimiendo Primos");
                    generarPrimos();
                }
            }
        } catch (InterruptedException ex) {
            System.out.println("Terminando hilo");
            //Logger.getLogger(Hilo_Secuencia1.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
