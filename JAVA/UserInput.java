import java.util.Scanner;

public class UserInput {
    public static void main (String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter your name: ");
        String name = scanner.nextLine();
  

        System.out.print("Enter your age: ");
        int age = scanner.nextInt();
        // scanner.nextLine(); // this will clear the input buffer 

        System.out.print("How tall are you ");
        double hight = scanner.nextDouble();
        // scanner.nextLine(); // this will clear the input buffer 
        

        System.out.print("Are you a student? (true/false)");
        boolean isStudent = scanner.nextBoolean();
        scanner.nextLine(); // this will clear the input buffer 

        System.out.println("What is your fav color ");
        String color = scanner.nextLine(); // we need to get red of the previous line char 

      
        System.out.println("Hello "+name+ "You are "+age+" years old and you are "+hight+"foot tall"+" you like "+color+" color");
      
      
        if(isStudent) {
            System.out.println("You are a student");
        }
        else{
            System.out.println("you are not a student");
        }


        scanner.close();
    }
    
}
