package Control;


import Hilos.Hilo_Interrupciones;
import Hilos.Hilo_Secuencia1;
import Vista.UI;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Bryan Ramos
 */
public class UIControl{
    private UI user;
    private Hilo_Interrupciones hI;
    
    public UIControl(UI user){
        this.user = user;
    }
    public void mostrarHilo1(String valor){
        user.jTexthilo1.append(valor + "\n");
    }
    public void mostrarHilo2(String valor){
        user.jTexthilo2.append(valor+ "\n");
    }
    public void mostrarInterrupcion1(String valor){
        user.jTextinter1.append(valor+ "\n");
    }
    public void mostrarInterrupcion2(String valor){
        user.jTextinter2.append(valor+ "\n");
    }
}