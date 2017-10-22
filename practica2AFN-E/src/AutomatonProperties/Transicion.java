/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package AutomatonProperties;

/**
 *
 * @author Brayan Ramos
 */
public class Transicion {
    
    int estadoPrevio;
    String letra;
    int estadoSiguiente;

    public Transicion() {
    }

        
    public Transicion(int estadoPrevio, String letra, int estadoSiguiente) {
        this.estadoPrevio = estadoPrevio;
        this.letra = letra;
        this.estadoSiguiente = estadoSiguiente;
    }

    public int getEstadoPrevio() {
        return estadoPrevio;
    }

    public void setEstadoPrevio(int estadoPrevio) {
        this.estadoPrevio = estadoPrevio;
    }

    public String getLetra() {
        return letra;
    }

    public void setLetra(String letra) {
        this.letra = letra;
    }

    public int getEstadoSiguiente() {
        return estadoSiguiente;
    }

    public void setEstadoSiguiente(int estadoSiguiente) {
        this.estadoSiguiente = estadoSiguiente;
    }
    
    public void print() {
        System.out.println(this.estadoPrevio + "[" + this.letra + "] -> " + this.estadoSiguiente);
    }
    
    
    
    
}
