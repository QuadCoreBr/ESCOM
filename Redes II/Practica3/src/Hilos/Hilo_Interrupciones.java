/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Hilos;

import Control.UIControl;

/**
 *
 * @author Bryan Ramos
 */
public class Hilo_Interrupciones extends Thread{
    Hilo1 h1;
    Hilo2 h2;
    Thread hilo1;
    Thread hilo2;
    Hilo_Secuencia1 hs1;
    Hilo_Secuencia2 hs2;
    UIControl control;
    
    public Hilo_Interrupciones(UIControl control){
        this.control = control;
        h1 = new Hilo1();
        h2 = new Hilo2();
        hilo1 = new Thread(h1);
        hilo2 = new Thread(h2);
        //hs2 = new Hilo_Secuencia2(10,control);
        //hs1 = new Hilo_Secuencia1('A',1,10,control);
        
    }
    private class Hilo1 extends Thread{
        /*UIControl control;
        public Hilo1(UIControl control){
            this.control = control;
        }*/
        Hilo_Secuencia1 hsec1 = new Hilo_Secuencia1('A',1,10,control);
        Thread t1 = new Thread(hsec1);
        @Override
        public void run() {
            t1.start();
            for(int i = 0; i<10;i++){
                try {
                    Thread.sleep(2000);
                } catch (InterruptedException ex) {
                    System.out.println("ESPERANDO EN MAIN");
                }
                //System.out.println("------Interrupcion H1:---------- " + (i+1));
                control.mostrarInterrupcion1("Interrupción " +(i+1)+" en H1");
                t1.interrupt();
            }
            try {
                t1.join(1000);
            } catch (InterruptedException ex) {
                System.out.println("Interrupcion en JOIN");
            }
        }
    }
    private class Hilo2 extends Thread{
        Hilo_Secuencia2 hs2 = new Hilo_Secuencia2(10,control);
        Thread t2 = new Thread(hs2);
        @Override
        public void run() {
            t2.start();
            for(int i = 0; i<10;i++){
                try {
                    Thread.sleep(3000);
                } catch (InterruptedException ex) {
                    System.out.println("ESPERANDO EN MAIN");
                }
                control.mostrarInterrupcion2("Interrupción " +(i+1)+" en H1");
                System.out.println("------Interrupcion H2:---------- " + (i+1));
                t2.interrupt();

            }
            try {
                t2.join(1000);
            } catch (InterruptedException ex) {
                System.out.println("Interrupcion en JOIN");
            }
        }
    }
    @Override
    public void run() {
        hilo1.start();
        hilo2.start();
    }
} 

