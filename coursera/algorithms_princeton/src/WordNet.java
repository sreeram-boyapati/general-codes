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
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Map;

/**
 * Created by sreeram on 6/4/15.
 */
public class WordNet {

    Digraph graph;
    Map<String, String> syn_meaning_map;
    Map<String, ArrayList<String>> syn_word_map;

    // constructor takes the name of the two input files
    public WordNet(String synsets, String hypernyms){
        Path synsetPath = FileSystems.getDefault().getPath("..", synsets);
        Path hypsPath = FileSystems.getDefault().getPath("..", hypernyms);
        try{
            BufferedReader reader = Files.newBufferedReader(synsetPath);
            String str = "";
            int counter;
            for(counter=0; (str=reader.readLine())!= null; counter++){
                processSynset(str);
            }
            reader.close();
            graph = new Digraph(counter);
            BufferedReader hyp_reader = Files.newBufferedReader(hypsPath);
            for(counter=0; (str=hyp_reader.readLine())!=null; counter++) {
                processHypernym();
            }
        }
        catch(IOException io){
            log("File may not have been found or It might be empty.");
        }

    }

    // returns all WordNet nouns
    public Iterable<String> nouns(){
        return null;
    }

    // is the word a WordNet noun?
    public boolean isNoun(String word){
        return false;
    }

    // distance between nounA and nounB (defined below)
    public int distance(String nounA, String nounB){
        return 0;
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
        }
        syn_word_map.put(id, words);

    }

    private void Hypernym(String str){
        String[] tokens = str.split(",");
        int v = (int)tokens[0];
        graph.addEdge();
    }

    // do unit testing of this class
    public static void main(String[] args){
        WordNet wordnet = new WordNet("synsets.txt", "hypernyms.txt");
    }
}
