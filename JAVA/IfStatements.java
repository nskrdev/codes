import java.util.Scanner;
public class IfStatements {
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        
        int age;
        String name;

        System.out.print("Enter your name: ");
        name = scanner.nextLine();
        
        System.out.print("Enter your age: ");
        age = scanner.nextInt();

        // don't want name empty variable/check if it is empty
        if (name.isEmpty()){
            System.out.println("You did not enter your name");
        }
        else {
            System.out.println("Hello "+name);
        }

        if (age >= 65) {
            System.out.println("You are a senior citizen!");
        }
        else if (age<0){
            System.out.println("you haven't born yet!");
        }
        else if (age == 0){
            System.out.println("you are a baby!");
        }
        else if (age>=18){
            System.out.println("you are and adult!");
        }
        else {
            System.out.println("You are still a child!");
        }

        scanner.close();
    }
    
}
