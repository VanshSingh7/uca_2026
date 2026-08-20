import java.util.*;

public class PostfixExpression {

    static int postfixEvaluation(String str) {
        Stack<Integer> stack = new Stack<>();
        String[] tokens = str.split(" ");

        for (String token : tokens) {
            // token contains one or more digit
            if (token.matches("\\d+")) {
                stack.push(Integer.parseInt(token));
            } 
            else {
                int b = stack.pop();
                int a = stack.pop();

                switch (token) {
                    case "+":
                        stack.push(a + b);
                        break;

                    case "-":
                        stack.push(a - b);
                        break;

                    case "*":
                        stack.push(a * b);
                        break;

                    case "/":
                        if (b == 0) {
                            throw new ArithmeticException("Division by zero");
                        }
                        stack.push(a / b);
                        break;
                }
            }
        }

        return stack.pop();
    }

    public static void main(String[] args) {

        String str1 = "2 3 1 * + 9 -";
        System.out.println(str1 + " : " + postfixEvaluation(str1));

        String str2 = "5 2 + 8 3 - *";
        System.out.println(str2 + " : " + postfixEvaluation(str2));

        String str3 = "12 3 + 5 *";
        System.out.println(str3 + " : " + postfixEvaluation(str3));

        String str4 = "20 10 - 3 *";
        System.out.println(str4 + " : " + postfixEvaluation(str4));

        String str5 = "100 20 + 5 /";
        System.out.println(str5 + " : " + postfixEvaluation(str5));
    }
}