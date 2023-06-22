/* Shannon Rhatigan
sr3999
Prof. Blaer*/

import java.util.PriorityQueue;
import java.util.*;
import java.io.*;

public class KBestCounter<T extends Comparable<? super T>> implements KBest<T> {

    // instance variables
    public int value; // amount
    public PriorityQueue<T> PQ; //PriorityQueue
    

    public KBestCounter(int k) {
        PQ = new PriorityQueue<>(k);
        value = k;
    }

    public void count(T x) {
        PQ.offer(x);
        if(PQ.size() > value) {
            PQ.poll();
        }
    }

    public List<T> kbest() {
        List<T> OL = new ArrayList<>(); //ordered List
        while(!PQ.isEmpty()){
            OL.add(PQ.poll());
        }

        return OL;
    }


}