/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package practica3hilos;

/**
 *
 * @author Monserrat
 */

import java.io.IOException;
import java.util.logging.FileHandler;
import java.util.logging.Formatter;
import java.util.logging.Logger;
import java.util.logging.Level;
import java.util.logging.LogRecord;

public class log {

    Logger log;

    public log(){
        
       
        boolean append = true;
        try {
            FileHandler rol = new FileHandler("Log.log",append);// Un número que el sistema operativo asigna temporalmente a un archivo cuando se abre. El sistema operativo utiliza el identificador de archivo interno al acceder al archivo. Un área especial de la memoria principal está reservado para los identificadores de archivo y el tamaño de esta área determina cuántos archivos pueden ser abiertos a la vez.
            rol.setFormatter(new Formatter() {
                @Override
                public String format(LogRecord record) {
                    StringBuffer buf = new StringBuffer(10000);
                    buf.append(new java.util.Date());
                    buf.append(' ');
                    buf.append(record.getLevel());
                    buf.append(' ');
                    buf.append(formatMessage(record));
                    buf.append("\n\n\n");
                    return buf.toString();
                }
            });
            log = Logger.getLogger("TestLog");
            log.addHandler(rol);
        } catch (IOException ex) {
            Logger.getLogger(log.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SecurityException ex) {
            Logger.getLogger(log.class.getName()).log(Level.SEVERE, null, ex);
        }
        
 
    }

    public Logger getLog() {
        return log;
    }

    public void setLog(Logger log) {
        this.log = log;
    }
    
}