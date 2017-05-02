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
public class Hilo_Interrupciones implements Runnable{
    public Hilo1 h1;
    public Hilo2 h2;
    public Thread hilo1;
    public Thread hilo2;
    Hilo_Secuencia1 hs1;
    Hilo_Secuencia2 hs2;
    UIControl control;
    LoggerHilos logger;
    
    public Hilo_Interrupciones(UIControl control){
        this.control = control;
        h1 = new Hilo1();
        h2 = new Hilo2();
        hilo1 = new Thread(h1);
        hilo2 = new Thread(h2);
        logger = new LoggerHilos();
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
            
            //System.out.println("Hilo 1 - ID: " + t1.getName());
            logger.agregarLog("Hilo 1 - ID:" + t1.getId());
            logger.agregarLog("Hilo 1 - Estado: " + "Iniciado");
            t1.start();
            for(int i = 0; i<10;i++){
                try {
                    //System.out.println("Hilo 1 - Estado Actual: " + t1.getState());
                    
                    Thread.sleep(2000);
                    logger.agregarLog("Hilo 1 - Número interrupción: " + (i+1));
                    logger.agregarLog("Hilo 1 - Estado: "+ "Interrumpido");
                    
                } catch (InterruptedException ex) {
                    System.out.println("ESPERANDO EN MAIN");
                }
                //System.out.println("------Interrupcion H1:---------- " + (i+1));
                //System.out.println("Hilo 1 - Estado Actual: " + t1.getState());
                control.mostrarInterrupcion1("Interrupción " +(i+1)+" en H1");
                logger.agregarLog("Hilo 1 - Estado: " + "Dormido");
                t1.interrupt();
                
            }
            //logger.agregarLog("Hilo 1 - Estado: " + "Finalizado");
            /*try {
                t1.join(100);
            } catch (InterruptedException ex) {
                System.out.println("Interrupcion en JOIN");
            }*/
            while(true){
                if(t1.isAlive() == false){
                    logger.agregarLog("Hilo 1 - Estado: " + "Finalizado");
                    break;
                }
            }
        }
    }
    private class Hilo2 extends Thread{
        Hilo_Secuencia2 hs2 = new Hilo_Secuencia2(10,control);
        Thread t2 = new Thread(hs2);
        @Override
        public void run() {
            
            logger.agregarLog("Hilo 2 - ID: " + t2.getId());
            logger.agregarLog("Hilo 2 - Estado: " + "Iniciado");
            t2.start();
            //System.out.println("Hilo 2 - ID: " + t2.getId());
            
            for(int i = 0; i<10;i++){
                try {
                    //System.out.println("Hilo 2 - Estado Actual: " + t2.getState());
                    
                    Thread.sleep(3000);
                    logger.agregarLog("Hilo 2 - Número interrupción: " + (i+1));
                    logger.agregarLog("Hilo 2 - Estado: "+ "Interrumpido");
                    
                } catch (InterruptedException ex) {
                    System.out.println("ESPERANDO EN MAIN");
                }
                control.mostrarInterrupcion2("Interrupción " +(i+1)+" en H2");
                //System.out.println("------Interrupcion H2:---------- " + (i+1));
                logger.agregarLog("Hilo 2 - Estado: " + "Dormido");
                t2.interrupt();
                //System.out.println("Hilo 2 - Estado Actual: " + t2.getState());             
                
            }
            /*try {
                t2.join(100);
            } catch (InterruptedException ex) {
                Logger.getLogger(Hilo_Interrupciones.class.getName()).log(Level.SEVERE, null, ex);
            }*/
            while(true){
                if(t2.isAlive() == false){
                    logger.agregarLog("Hilo 2 - Estado: " + "Finalizado");
                    break;
                }
            }
           /* try {
                t2.join(1000);
            } catch (InterruptedException ex) {
                System.out.println("Interrupcion en JOIN");
            }*/
        }
    }
    @Override
    public void run() {
        hilo1.start();
        hilo2.start();
        while(true){
            if(hilo1.isAlive() || hilo2.isAlive()){
                //System.out.println("Siguen vivos");
                /*if(hilo2.isAlive())
                    System.out.println("HILO 2 VIVO");
                if(hilo1.isAlive())
                    System.out.println("HILO 1 VIVO");
                    */
            }
            else{
                System.out.println("Estan Muertos xD");
                logger.agregarLog("Hilo Principal (MAIN) - Terminado");
                try {
                    Thread.currentThread().join(100);
                } catch (InterruptedException ex) {
                    Logger.getLogger(Hilo_Interrupciones.class.getName()).log(Level.SEVERE, null, ex);
                }
                break;
            }
        }
    }
} 

