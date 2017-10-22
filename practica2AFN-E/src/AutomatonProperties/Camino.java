/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package AutomatonProperties;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Brayan Ramos
 */
public class Camino {
    
    private List<Transicion> transicionesCamino;

    public Camino() {
        transicionesCamino = new ArrayList<>();
    }

    public List<Transicion> getTransicionesCamino() {
        return transicionesCamino;
    }

    public void setTransicionesCamino(List<Transicion> transicionesCamino) {
        this.transicionesCamino = transicionesCamino;
    }
    
    
    
}
