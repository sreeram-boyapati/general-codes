/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 HackerEarth
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:*
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.*
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


import java.io.InputStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

/**
 *Created by sreeram on 6/4/15.
 */
public class Digraph {
    public final ArrayList<Integer> vertices = new ArrayList<Integer>();
    public final Map<Integer, ArrayList<Integer>> adjacencyList = new HashMap<Integer, ArrayList<Integer>>();
    int no_edges;
    public Digraph(int V){
        for(int i=0; i<V; i++){
            vertices.add(i);
            adjacencyList.put(new Integer(i), new ArrayList<Integer>());
        }
    }

    public Digraph(InputStream in){
    }

    public void addEdge(int v, int w){
        /**
         * Adds vertex w to the adjacency list of v
         */
        ArrayList<Integer> edges = adjacencyList.get(new Integer(v));
        if(edges == null) {
            throw new NullPointerException("Vertex does not exist");
        }
        edges.add(new Integer(w));
        no_edges++;
        adjacencyList.put(v, edges);
    }

    public Iterable<Integer> adj(int v){
        ArrayList<Integer> list = adjacencyList.get(v);
        if(list == null)
            throw new NullPointerException("Vertex does not exist");
        return list;
    }

    public int V(){
        /**
         * Returns number of vertices
         *
         */
        return vertices.size();
    }

    public int E(){
        /**
         * Returns number of edges
         */
        return no_edges;
    }

    public Digraph reverse(){
        return null;
    }

    public String toString(){
        return "";
    }
}
