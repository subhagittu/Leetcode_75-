public class Solution {
    public String reverseWords(String s) {
       
        int i = 0, j = s.length() - 1;
        while (i <= j && s.charAt(i) == ' ') i++;  
        while (j >= i && s.charAt(j) == ' ') j--;   
        s = s.substring(i, j + 1);                  
        String[] words = s.split("\\s+");           

       
        StringBuilder out = new StringBuilder();

      
        for (int k = words.length - 1; k > 0; k--) {
          
            out.append(words[k]).append(" ");
        }

        
        return out.append(words[0]).toString();     
    }
}
