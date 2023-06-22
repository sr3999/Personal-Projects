/* Shannon Rhatigan
sr3999
Prof. Blaer*/

import java.util.*;
import java.io.*;

public class SpellChecker implements SpellCheckerInterface {

    //declare instance variables below
    HashSet<String> dictionary;
    Set<String> suggested;
    List<String> incorrect;

    public SpellChecker(String filename) {
        dictionary = new HashSet <String>();

        try{
            
            File theFile = new File(filename);
            Scanner input = new Scanner(theFile);

            while(input.hasNext()) { //where next exists, get next
                String theWord = input.next();
                theWord = theWord.toLowerCase();
                theWord = theWord.replaceAll("[^a-zA-Z0-9]+", "");
                dictionary.add(theWord);
            }
        }

        catch(FileNotFoundException e) {
            System.out.println("File: " + filename + "is unable to open. Please try again!");
        }
    
    }

    public List<String> getIncorrectWords(String filename) {
        incorrect = new ArrayList<>();

        try{
            
            File theFile = new File(filename);
            Scanner input = new Scanner(theFile);

            while(input.hasNext()) { //where next exists, get next
                String theWord = input.next();
                theWord = theWord.toLowerCase();
                theWord = theWord.replaceAll("[^a-zA-Z0-9]+", "");

                if(!dictionary.contains(theWord)){
                    incorrect.add(theWord);
                }
            }
        }

        catch(FileNotFoundException e) {
            System.out.println("File: " + filename + "is unable to open. Please try again!");
        }

        return incorrect;
    }

    public Set<String> getSuggestions(String theWord){
        suggested = new HashSet<>();

        // adding a char.
        for(int i = 0; i<=theWord.length(); i++) {
            for(char j = 'a'; j <='z'; j++){
                String suggestedWord = theWord.substring(0, i) + j + theWord.substring(i);

                if(dictionary.contains(suggestedWord)){
                    suggested.add(suggestedWord);
                }
            }
        }

        // subtracting a char.
        for(int i = 0; i < theWord.length(); i++){
            String suggestedWord = theWord.substring(0, i) + theWord.substring(i + 1);

            if(dictionary.contains(suggestedWord)){
                suggested.add(suggestedWord);
            }
        }

        char[] characters = theWord.toCharArray();

        // swapping adj. chars.
        for(int i = 0;i < theWord.length() - 1; i++) {
            char temp = characters[i];
            characters[i] = characters[i+1];
            characters[i+1] = temp;

            String suggestedWord = new String(characters);
            if(dictionary.contains(suggestedWord)){
                suggested.add(suggestedWord);
            }

            characters[i+1] = characters[i];
            characters[i] = temp;
        }

        return suggested;

    }
}