/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Sreeram Boyapati
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

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.*;

/**
 * Created by sreeram on 6/4/15.
 */
public class WordNet {

    Digraph graph;
    Map<String, String> syn_meaning_map;
    Map<String, ArrayList<String>> syn_word_map;
    Map<String, String> reverse_syn_word_map;

    // constructor takes the name of the two input files
    public WordNet(String synsets, String hypernyms){
        Path synsetPath = FileSystems.getDefault().getPath("..", synsets);
        Path hypsPath = FileSystems.getDefault().getPath("..", hypernyms);
        syn_meaning_map = new HashMap<String, String>();
        syn_word_map = new HashMap<String, ArrayList<String>>();
        reverse_syn_word_map = new HashMap<String, String>();
        try{
            //Decode strings using UTF-8
            Charset charset = Charset.forName("UTF-8");
            BufferedReader reader = Files.newBufferedReader(synsetPath, charset);
            String str;
            int counter;
            for(counter=0; (str=reader.readLine())!= null; counter++){
                processSynset(str);
            }
            reader.close();

            graph = new Digraph(counter);
            BufferedReader hyp_reader = Files.newBufferedReader(hypsPath, charset);
            for(counter=0; (str=hyp_reader.readLine())!=null; counter++) {
                processHypernym(str);
            }
            reader.close();
        }
        catch(IOException io){
            log("File may not have been found or It might be empty.");
        }

    }

    public Iterable<String> nouns(){
        // returns all WordNet nouns
        return syn_meaning_map.keySet();
    }

    public boolean isNoun(String word){
        // is the word a WordNet noun?
        return syn_meaning_map.get(word) != null ? true: false;
    }

    // distance between nounA and nounB (defined below)
    public int distance(String nounA, String nounB){
        Integer source_id = Integer.parseInt(reverse_syn_word_map.get(nounA));
        Integer dist_id = Integer.parseInt(reverse_syn_word_map.get(nounB));

    }

    private int dfs(Integer source_id){
        Map<Integer, Boolean> marked_vertices = new HashMap<Integer, Boolean>();
        Stack<Integer> vertices = new Stack<Integer>();
        vertices.push(source_id);
        while(!vertices.empty()) {
            Integer vertex = vertices.pop();
            Iterable<Integer> adjacent_vertices = graph.adj(source_id);
            Iterator<Integer> iterator = adjacent_vertices.iterator();
            if (!iterator.hasNext()) {
                return 0;
            }
            while (iterator.hasNext()) {
                Integer sibling_vertex = iterator.next();
                if (!marked_vertices.getOrDefault(sibling_vertex, false)) {
                    continue;
                }
                vertices.push(vertex);
            }
        }
    }

    // a synset (second field of synsets.txt) that is the common ancestor of nounA and nounB
    // in a shortest ancestral path (defined below)
    public String sap(String nounA, String nounB){
        return null;
    }

    private void log(Object s){
        System.out.println(s);
    }

    private void processSynset(String str){
        String[] tokens = str.split(",");
        String id = tokens[0];
        String syns = tokens[1];
        String meaning = tokens[2];
        syn_meaning_map.put(id, meaning);
        String[] synonyms = syns.split(" ");
        ArrayList<String> words = new ArrayList<String>();
        for(String syn: synonyms){
            words.add(syn);
            reverse_syn_word_map.put(syn, id);
        }
        syn_word_map.put(id, words);

    }

    private void processHypernym(String str){
        String[] tokens = str.split(",");
            int v = Integer.parseInt(tokens[0]);
        for(int i=1; i<tokens.length; i++){
            graph.addEdge(v, Integer.parseInt(tokens[i]));
        }
    }

    // do unit testing of this class
    public static void main(String[] args){
        WordNet wordnet = new WordNet("synsets.txt", "hypernyms.txt");
    }
}