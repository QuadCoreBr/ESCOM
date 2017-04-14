/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Hilos;

import java.util.concurrent.Callable;
import static javafx.scene.input.KeyCode.V;

/**
 *
 * @author Bryan Ramos
 */
public class Task implements Callable<String> {

    @Override
    public String call() throws Exception {
        System.out.println("TASK: Started..");
        for (int i = 0; i < Integer.MAX_VALUE; i++) {
            if (Thread.currentThread().isInterrupted()) {
                System.out.println("Interrupted!");
                return null;
            }
        }
        System.out.println("TASK: Finished!");
        return null;
    }
}
