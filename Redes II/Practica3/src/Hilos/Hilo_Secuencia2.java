/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Hilos;

import Control.UIControl;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Bryan Ramos
 */
public class Hilo_Secuencia2 implements Runnable{
    long fiboActual;
    int parActual;
    int maxInterruptions;
    int interruptionsCounter;
    long fiboAnterior1;
    long fiboAnterior2;
    int bandera;
    UIControl control;

    public Hilo_Secuencia2 (int maxInterruptions,UIControl control) {
        fiboActual = 0;
        fiboAnterior1 = 0;
        fiboAnterior2 = 1;
        this.maxInterruptions = maxInterruptions;
        this.control = control;
    }
    public void generarFibo(){
        while(true){
            try {
                Thread.sleep(300);
                if (getFiboActual() == 0){
                    control.mostrarHilo2("Fibo: " + "0");
                    System.out.println("0");
                }
                if(getFiboAnterior1() == 1){
                    control.mostrarHilo2("Fibo: "+"1");
                    System.out.println("Fibo: "+ "1");
                } 
                setFiboActual(getFiboAnterior1()+getFiboAnterior2());
                setFiboAnterior1(getFiboAnterior2());
                setFiboAnterior2(getFiboActual());
                control.mostrarHilo2("Fibo: " +Long.toString(getFiboActual()));
                System.out.println("Fibo: " + getFiboActual());
                
            } catch (InterruptedException ex) {
                control.mostrarHilo2("-----------INTERRUPCIÓN---------");
                System.out.println("Interrupcion generando Fibo");
                setBandera(1);
                increaseInterruptionsCounter();
                break;
                //Logger.getLogger(Hilo_Secuencia2.class.getName()).log(Level.SEVERE, null, ex);
            }
        }   
    }    
    public void generarPares(){
        while(true){
            try {
                Thread.sleep(200);
                control.mostrarHilo2("Numero par: "+Integer.toString(parActual));
                System.out.println("Número Par: " + parActual);
                setParActual(parActual+2);
            } catch (InterruptedException ex) {
                control.mostrarHilo2("-----------INTERRUPCIÓN---------");
                System.out.println("Interrupcion generando pares");
                setBandera(0);
                increaseInterruptionsCounter();
                break;
                //Logger.getLogger(Hilo_Secuencia2.class.getName()).log(Level.SEVERE, null, ex);
            }
        }        
    }
    public synchronized long getFiboAnterior1(){
        
        return fiboAnterior1;
    }
    public synchronized void setFiboAnterior1(long fiboAnt){
        fiboAnterior1 = fiboAnt;
    }
    public synchronized long getFiboAnterior2(){
        
        return fiboAnterior2;
    }
    public synchronized void setFiboAnterior2(long fiboAnt){
        fiboAnterior2 = fiboAnt;
    }
    public synchronized long getFiboActual() {
        return fiboActual;
    }

    public synchronized void setFiboActual(long fiboActual) {
        this.fiboActual = fiboActual;
    }

    public synchronized int getParActual() {
        return parActual;
    }

    public synchronized void setParActual(int parActual) {
        this.parActual = parActual;
    }
    public synchronized void setBandera(int bandera){
        this.bandera = bandera;
    }
    public synchronized int getBandera(){
        return bandera;
    }
    public synchronized int getMaxInterruptions() {
        return maxInterruptions;
    }

    public synchronized void setMaxInterruptions(int maxInterruptions) {
        this.maxInterruptions = maxInterruptions;
    }

    public synchronized int getInterruptionsCounter() {
        return interruptionsCounter;
    }

    public synchronized void increaseInterruptionsCounter() {
        interruptionsCounter++;
    }
    
    
    @Override
    public void run(){
        try {
            //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
            Thread.sleep(100);
            while(true){
                if(getInterruptionsCounter()== maxInterruptions){
                    control.mostrarHilo2("FIN HILO 2");
                    System.out.println("Finalizando Hilo 2");
                    break;
                }
                if(getBandera() == 0){
                    //System.out.println("Imprimiendo ABC");
                    generarFibo();
                }
                if(getBandera() == 1){
                    //System.out.println("Imprimiendo Primos");
                    generarPares();
                }
            }
        } catch (InterruptedException ex) {
            System.out.println("Terminando hilo");
            //Logger.getLogger(Hilo_Secuencia1.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
