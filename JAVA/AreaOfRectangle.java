import java.util.Scanner;

public class AreaOfRectangle {
    public static void main (String[] args){


        // calculating the area of circle
        double width = 0;
        double hight = 0;
        double area = 0;

        Scanner scanner = new Scanner(System.in);
        

        System.out.print("Enter the width ");
        width = scanner.nextDouble();

        System.out.print("Enter the hight ");
        hight = scanner.nextDouble();

        area = width * hight;
        System.out.println("The area is: "+area+" cm²");


        scanner.close();
    }
    
}
