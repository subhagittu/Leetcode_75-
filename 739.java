class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int[] answer = new int[temperatures.length];
        Stack<Integer> indices = new Stack<>();  
        for (int i = 0; i < temperatures.length; i++){
            if (i+1 >= temperatures.length){
                answer[i] = 0;  
                while((!indices.isEmpty())){
                    answer[indices.pop()] = 0; 
                }
            }
            else{
                if (temperatures[i] < temperatures[i+1]){
                    while((!indices.isEmpty()) && (temperatures[indices.peek()] < temperatures[i+1])){
                            answer[indices.peek()] = i+1 - indices.pop(); 
                        }
                        answer[i] = 1;
                }
                    
                else{
                    indices.push(i);
                } 
            }
         
        }
        return answer;

    }
}
