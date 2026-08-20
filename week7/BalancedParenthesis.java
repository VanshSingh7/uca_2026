import java.util.*;

class BalancedParenthesis{
    static boolean balancedParenthesis(String str){
        Stack<Character> stack = new Stack<>();

        for(char c : str.toCharArray()){
            if(c=='[' || c=='{' || c=='('){
                stack.push(c);
            }
            else{
                if(stack.isEmpty()){
                    return false;
                }
                char check = stack.pop();
                if(!((check == '[' && c ==']') || 
                    (check == '{' && c =='}') || 
                    (check == '(' && c ==')'))
                ){
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }
    public static void main(String[] args){
        String str1 = "[()]{}{()()}";
        boolean res1 = balancedParenthesis(str1);
        System.out.println(str1 + ": " + res1); 

        String str2 = "[(])";
        boolean res2 = balancedParenthesis(str2);
        System.out.println(str2 + ": " + res2);

        String str3 = "((()))";
        boolean res3 = balancedParenthesis(str3);
        System.out.println(str3 + ": " + res3);

        String str4 = "(((";
        boolean res4 = balancedParenthesis(str4);
        System.out.println(str4 + ": " + res4);

        String str5 = "())";
        boolean res5 = balancedParenthesis(str5);
        System.out.println(str5 + ": " + res5);
    }
}