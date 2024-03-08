package org.endava;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.*;
import java.util.stream.Collectors;

public class StringOccurrence {
    public static int getOccurrenceCount(String toSearch, InputStream stream) throws Exception {

        String s = new BufferedReader(new InputStreamReader(stream, StandardCharsets.UTF_8))
                .lines()
                .collect(Collectors.joining("\n"));

        int occurences = 0;

        char[] toSearchCharArr = toSearch.toCharArray();
        char[] stringCharArr = s.toCharArray();

         for (int i=0; i<stringCharArr.length; i++
        ) {
            boolean equals = true;

            for (int j=0; j<toSearchCharArr.length;  j++) {
                if (toSearchCharArr[j] != stringCharArr[i+j]) {
                    equals = false;
                    break;
                }
            }

            if (equals)
                occurences++;
        }

        /*return s.split(toSearch, -1).length-1;*/

        return occurences;
    }

    public static void main(String[] args) throws Exception {
        String msg = "Hey! How are you?\nI am good, how about you?\nI am good too.";

        try (InputStream stream = new ByteArrayInputStream(msg.getBytes())) {
            System.out.println(StringOccurrence.getOccurrenceCount("you?\nI", stream));
        }
    }
}