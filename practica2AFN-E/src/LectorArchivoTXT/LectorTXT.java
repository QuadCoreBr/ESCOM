/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package LectorArchivoTXT;

import AutomatonProperties.AutomataFND;
import AutomatonProperties.Transicion;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import javax.swing.JFileChooser;
import javax.swing.filechooser.FileNameExtensionFilter;

/**
 *
 * @author Brayan Ramos
 */
public class LectorTXT {
    
    private AutomataFND automata = new AutomataFND();
    
    public void leer() throws FileNotFoundException, IOException{
        int contador = 1;
        String archivo = "D:\\Github\\Escolar-Compiladores\\practica2\\archivo.txt";
                //mostarSelector();
        String cadena = new String();
        if ( archivo != null && !archivo.isEmpty()){
        FileReader fileToRead = new FileReader(archivo);
        BufferedReader b = new BufferedReader(fileToRead);
        while((cadena = b.readLine())!=null) {
            if (contador == 1){ //Leer los estados
                String[] estadosLeidos = cadena.split(",");
                ArrayList<Integer> estadosAutomata = new ArrayList<>();
                for(String estadoNuevo : estadosLeidos){
                    estadosAutomata.add(Integer.parseInt(estadoNuevo));
                }
                automata.setQ(estadosAutomata);
            }else if(contador == 2){ //Leer el alfabeto
                String [] alfabetoLeido = cadena.split(",");
                ArrayList<String> alfabetoAutomata = new ArrayList<>();
                for(String letraAlfabeto: alfabetoLeido){
                    alfabetoAutomata.add(letraAlfabeto);
                }
                automata.setE(alfabetoAutomata);
            }else if(contador == 3){ //Leer los estados iniciales
                String [] estadosIniLeidos = cadena.split(",");
                ArrayList<Integer> estadosIniAutomata = new ArrayList<>();
                for(String estadosIni : estadosIniLeidos){
                    estadosIniAutomata.add(Integer.parseInt(estadosIni));
                }
                automata.setEI(estadosIniAutomata);
                
            }else if(contador == 4){//Leer los estados finales
                String [] estadosFinLeidos = cadena.split(",");
                ArrayList<Integer> estadosFinAutomata = new ArrayList<>();
                for(String estadosFin : estadosFinLeidos){
                    estadosFinAutomata.add(Integer.parseInt(estadosFin));
                }
                automata.setEF(estadosFinAutomata);
            }else if(contador > 4){//Leer las transiciones
                String[] transicionLeida = cadena.split(",");
                Transicion transNueva = new Transicion();
                transNueva.setEstadoPrevio(Integer.parseInt(transicionLeida[0]));
                transNueva.setLetra(transicionLeida[1]);
                transNueva.setEstadoSiguiente(Integer.parseInt(transicionLeida[2]));
                automata.getTR().add(transNueva);
                
            }
            else{
                System.out.println("ERROR: El contador en "+ this.getClass().getName() + "tiene un valor invalido");
            }
            contador++;
        }
        b.close();
        //automata.print();
        }
    }
    
    private String mostarSelector(){
        JFileChooser chooser = new JFileChooser();
    FileNameExtensionFilter filter = new FileNameExtensionFilter(
        "Archivos de texto", "txt");
    chooser.setFileFilter(filter);
    int returnVal = chooser.showOpenDialog(null);
    if(returnVal == JFileChooser.APPROVE_OPTION) {
       System.out.println("You chose to open this file: " +
            chooser.getSelectedFile().getName());
       return chooser.getSelectedFile().getAbsolutePath();
    }else{
        return null;
    }
    
    }

    public AutomataFND getAutomata() {
        return automata;
    }
    
}
