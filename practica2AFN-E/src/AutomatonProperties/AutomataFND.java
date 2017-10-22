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
public class AutomataFND {
    
    private List<Integer> Q; //Estados
    private List<String> E; // Alfabeto
    private List<Integer> EI; //Estado inicial
    private List<Integer> EF; //Estados Finales
    private List<Transicion> TR; // Transiciones

    public AutomataFND() {
        Q = new ArrayList<>();
        E = new ArrayList<>();
        EI = new ArrayList<>();
        EF = new ArrayList<>();
        TR = new ArrayList<>();
    }

    public List<Integer> getQ() {
        return Q;
    }

    public void setQ(List<Integer> Q) {
        this.Q = Q;
    }

    public List<String> getE() {
        return E;
    }

    public void setE(List<String> E) {
        this.E = E;
    }

    public List<Integer> getEI() {
        return EI;
    }

    public void setEI(List<Integer> EI) {
        this.EI = EI;
    }

    public List<Integer> getEF() {
        return EF;
    }

    public void setEF(List<Integer> EF) {
        this.EF = EF;
    }

    public List<Transicion> getTR() {
        return TR;
    }

    public void setTR(List<Transicion> TR) {
        this.TR = TR;
    }


    
    public void print() {
        System.out.println("Se han encontrado los estados: ");
        Q.forEach(estado -> System.out.print(" " + estado));
        System.out.println("\n Se ha encontrado el alfabeto: ");
        E.forEach(simbolo -> System.out.print(" " + simbolo));
        System.out.println("\n Se ha identificado como estado inicial : ");
        EI.forEach(estado -> System.out.print(" " + estado));
        System.out.println("\n Se ha nidentificado como estados finales : ");
        EF.forEach(estado -> System.out.print(" " + estado));
        System.out.println("\n Se han identificado las transiciones : ");
        TR.forEach(transicion -> {
            System.out.print(" " + transicion.getEstadoPrevio());
            System.out.print(" " + transicion.getLetra());
            System.out.print(" " + transicion.getEstadoSiguiente());
            System.out.print("\n");
        });
    }
}
