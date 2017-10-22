/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package AFN_E;

import LectorArchivoTXT.LectorTXT;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

/**
 *
 * @author Brayan Ramos
 */
public class NonFiniteAutomaton {
   
    public static void main(String [] args){
        try {
           LectorTXT lectorArchivo =  new LectorTXT() ;
           lectorArchivo.leer();
           String cadenaPregunta = JOptionPane.showInputDialog(null,"Ingresa la cadena a validar");
           new ValidadorCadena().validarCadenaAutomata(cadenaPregunta,lectorArchivo.getAutomata());
        } catch (IOException ex) {
            Logger.getLogger(NonFiniteAutomaton.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
}
