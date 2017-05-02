/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Hilos;

import java.io.IOException;
import java.util.logging.FileHandler;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;

/**
 *
 * @author Bryan Ramos
 */
public class LoggerHilos {
    volatile Logger logger = Logger.getLogger("MyLog");
    FileHandler file;
    
    public LoggerHilos(){
        try {
            file = new FileHandler("D:\\Documents\\GitHub\\ESCOM\\Redes II\\Practica3\\log\\app.log");
            logger.addHandler(file);
            SimpleFormatter formater = new SimpleFormatter();
            file.setFormatter(formater);
        } catch (IOException ex) {
            Logger.getLogger(LoggerHilos.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SecurityException ex) {
            Logger.getLogger(LoggerHilos.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    public void agregarLog(String log){
        logger.log(Level.SEVERE, log);
    }
}
