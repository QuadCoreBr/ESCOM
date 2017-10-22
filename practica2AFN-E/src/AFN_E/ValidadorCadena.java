/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package AFN_E;

import AutomatonProperties.AutomataFND;
import AutomatonProperties.Camino;
import AutomatonProperties.Transicion;
import LectorArchivoTXT.LectorTXT;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Brayan Ramos
 */
public class ValidadorCadena {
    
    private AutomataFND automata;
    private List<Camino> caminosCorrectos = new ArrayList<>();
    private boolean cadenaAlfabetoValida;
    
    public void validarCadenaAutomata(String cadenaValidar,AutomataFND automata){
        automata.print();
        System.out.println("Validando la cadena: " + cadenaValidar);
        if(cadenaValidar != null && !cadenaValidar.isEmpty()){
        this.automata = automata;
        for(int i = 0; i< cadenaValidar.length();i++){ //Validar que los caracteres pertenecen al alfabeto
            if (automata.getE().contains(Character.toString(cadenaValidar.charAt(i)))){
                cadenaAlfabetoValida = true;
            }else{
                System.out.println("La letra: " + cadenaValidar.charAt(i) + " no pertenece al alfabeto");
                cadenaAlfabetoValida = false;
            }
        }
        if (cadenaAlfabetoValida){
            int posicionCadena = 0; //Nos colocamos en el primer carácter
            avanzarTransicion(cadenaValidar,automata.getEI().get(0),posicionCadena,new Camino());
           
        }else{
            System.out.println("La cadena no es valida porque uno de los caracteres no pertenece al alfabeto del automata");
        }
        }
        
    }
    
    private void avanzarTransicion(String cadenaValidar, int estadoActual, int posicionDeCadena, Camino caminoConcat){
        String simboloTransicion = String.valueOf(cadenaValidar.charAt(posicionDeCadena));
        //System.out.println("Validando el simbolo: " + simboloTransicion);
        List<Transicion> transicionesConcat = automata.getTR();
        ArrayList<Transicion> transicionesPosibles = new ArrayList<>();
        ArrayList<Transicion> transicionesPosiblesCE = new ArrayList<>();
        if(posicionDeCadena + 1 == cadenaValidar.length()){ //Si estamos en el último valor de la cadena
            for (Transicion transicionPosible : transicionesConcat){
                if ((transicionPosible.getEstadoPrevio() == estadoActual) && transicionPosible.getLetra().equals(simboloTransicion)){
                    transicionesPosibles.add(transicionPosible);
                    //transicionesPosibles.forEach(t -> {
                      //  t.print();
                    //});
                }
            }
            for(Transicion transicionPosibleCE: transicionesConcat){
                if ((transicionPosibleCE.getEstadoPrevio() == estadoActual) && transicionPosibleCE.getLetra().equals("E")){
                    transicionesPosiblesCE.add(transicionPosibleCE);
                    //System.out.println("Se encontró transición final para el estado " + estadoActual + " con la letra: " + "E");
                    //transicionPosibleCE.print();
                }
            }
            transicionesPosibles.addAll(transicionesPosiblesCE);
            if(!transicionesPosibles.isEmpty()){
                for(Transicion transicionPosibleId: transicionesPosibles){
                    if(automata.getEF().contains(transicionPosibleId.getEstadoSiguiente())){
                        Camino caminoSig = new Camino();
                        caminoSig.getTransicionesCamino().addAll(caminoConcat.getTransicionesCamino());
                        caminoSig.getTransicionesCamino().add(transicionPosibleId);
                        caminosCorrectos.add(caminoSig);
                        System.out.println("Se encontró un camino valido para la cadena");
                        for(Transicion tranCaminoVal: caminoSig.getTransicionesCamino()){
                            tranCaminoVal.print();
                        }
                    }else{
                        if(transicionPosibleId.getLetra().equals("E")){
                            Camino caminoSig = new Camino();
                            caminoSig.getTransicionesCamino().addAll(caminoConcat.getTransicionesCamino());
                            caminoSig.getTransicionesCamino().add(transicionPosibleId);
                            avanzarTransicion(cadenaValidar,transicionPosibleId.getEstadoSiguiente(),posicionDeCadena,caminoSig);
                        }else{
                            System.out.println("El camino no es valido porque ya no hay transiciones con estado final o E");
                            caminoConcat.getTransicionesCamino().forEach(trans ->{
                               trans.print(); 
                            });
                        }
                    }
                }
            }else{
                //System.out.println("El camino no es valido porque no hay transiciones posibles para el estado " + estadoActual + " con la letra: " + simboloTransicion );
                //transicionPosible.print();
            }
        }else{
            ArrayList<Transicion> transicionesPosiblesNF = new ArrayList<>();
            ArrayList<Transicion> transicionesPosiblesNFE = new ArrayList<>();
            //System.out.println("Las transiciones no finales posibles para esta iteración sin E son: ");
            for(Transicion transicionPosibleNF : transicionesConcat){
                if(transicionPosibleNF.getEstadoPrevio() == estadoActual && transicionPosibleNF.getLetra().equals(simboloTransicion)){
                    //System.out.print("Una transicion posible para el estado: " + estadoActual +" (SIN E) es: ");
                    //transicionPosibleNF.print();
                    transicionesPosiblesNF.add(transicionPosibleNF);
                }
            }
            //System.out.println("Las transiciones no finales posibles para esta iteración con E son: ");
            for(Transicion transicionPosibleNFE : transicionesConcat){
                if(transicionPosibleNFE.getEstadoPrevio() == estadoActual && transicionPosibleNFE.getLetra().equals("E")){
                    //System.out.print("Una transicion posible para el estado: " + estadoActual +" (CON E) es: ");
                    //transicionPosibleNFE.print();
                    transicionesPosiblesNFE.add(transicionPosibleNFE);
                }
            }
            
            transicionesPosiblesNF.addAll(transicionesPosiblesNFE);
                if(!transicionesPosiblesNF.isEmpty()){
                    //System.out.println("ENTRE A IF de no vacio en NF");
                    for(Transicion transicionPosibleCamino : transicionesPosiblesNF){
                        if(transicionPosibleCamino.getLetra().equals("E")){
                            Camino caminoSig = new Camino();
                            caminoSig.getTransicionesCamino().addAll(caminoConcat.getTransicionesCamino());
                            caminoSig.getTransicionesCamino().add(transicionPosibleCamino);
                            avanzarTransicion(cadenaValidar,transicionPosibleCamino.getEstadoSiguiente(),posicionDeCadena,caminoSig);
                        }else{
                            //System.out.println("Tomando el siguiente camino posible");
                            Camino caminoSig = new Camino();
                            caminoSig.getTransicionesCamino().addAll(caminoConcat.getTransicionesCamino());
                            caminoSig.getTransicionesCamino().add(transicionPosibleCamino);
                            avanzarTransicion(cadenaValidar,transicionPosibleCamino.getEstadoSiguiente(),++posicionDeCadena,caminoSig);
                        }
                    }
                }else{
                    //System.out.println("El camino no es valido porque no hay transiciones posibles para el estado " + estadoActual + " con la letra: " + simboloTransicion );
                    //transicionPosibleNF.print();
                }
            }
        
        
    }
}
