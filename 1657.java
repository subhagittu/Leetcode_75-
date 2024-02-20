class Solution {
    public boolean closeStrings(String word1, String word2) { 
        int n = word1.length();
        int m = word2.length();
        
        if(n!=m) return false;
        
        int freq1[] = new int[26];
        int freq2[] = new int[26];
        HashMap<Integer,Integer> mp1 = new HashMap<>();
        
        for(char ch:word1.toCharArray()) {
            int charIdx = (int)(ch-'a');
            freq1[charIdx]++;
        }
        for(int i=0;i<26;i++) {
            if(freq1[i]!=0) {
                mp1.put(freq1[i],mp1.getOrDefault(freq1[i],0)+1);
            }
        }
        
        for(char ch:word2.toCharArray()) {
            int charIdx = (int)(ch-'a');
            
            if(freq1[charIdx]==0) return false; 
            
            freq2[charIdx]++;
        }
        
        for(int i=0;i<26;i++) {
            if(freq2[i]!=0) {
                
                if(!mp1.containsKey(freq2[i])) {
                    return false;
                }

                int countFreq = mp1.get(freq2[i]);
                countFreq--;
                if(countFreq==0) {
                    mp1.remove(freq2[i]);
                } 
                else{
                    mp1.put(freq2[i],countFreq);
                }
            }
        }
       
        
       
        return true;
    }
}
