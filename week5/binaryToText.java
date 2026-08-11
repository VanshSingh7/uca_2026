package week5;
import java.util.*;

public class binaryToText {

    static String encodeBase64(String str){
        
        // 26 + 26 + 10 + 2 = 64 
        String base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"+
                        "abcdefghijklmnopqrstuvwxyz"+
                        "0123456789"+
                        "+/";
        
        // convert to Binary
        StringBuilder binary = new StringBuilder();

        for(char ch:str.toCharArray()){
            String bits = Integer.toBinaryString(ch);
            
            // 8 bits
            while(bits.length() < 8){
                bits = "0" + bits;
            }

            binary.append(bits);
        }

        while(binary.length()%6 != 0){
            binary.append("0");
        }

        // groups into 6 bits
        StringBuilder res = new StringBuilder();

        for(int i=0; i<binary.length(); i+=6){
            String sixBits = binary.substring(i, i+6);

            int val = Integer.parseInt(sixBits, 2);

            // using base64
            res.append(base64.charAt(val));
        }

        // padding
        int remainder = str.length()%3;

        if(remainder==1){
            res.append("==");
        }
        else if(remainder==2){
            res.append("=");
        }

        return res.toString();
    }


    public static void main(String[] args) {
        String s1 = "Cat";
        String s2 = "Hello World";
        String s3 = "A";
        String s4 = "";

        String res1 = encodeBase64(s1);
        System.out.println("Base64 of " + s1 + ": " + res1);
        
        String res2 = encodeBase64(s2);
        System.out.println("Base64 of " + s2 + ": " + res2);

        String res3 = encodeBase64(s3);
        System.out.println("Base64 of " + s3 + ": " + res3);
    
        String res4 = encodeBase64(s4);
        System.out.println("Base64 of " + s4 + ": " + res4);
    }
}
