import java.util.Scanner;

public class ShopingCart {
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);


        String item;
        double price;
        int quantity;
        char currency = '₹';
        double total;

        System.out.print("What item would you like to buy: ");
        item = scanner.nextLine();

        System.out.print("What is the price for each: "+currency);
        price = scanner.nextDouble();

        System.out.print("How many do you want: ");
        quantity = scanner.nextInt();

        total = price * quantity;
        System.out.println("\nYour total cart value is "+currency+total);




        scanner.close();
    }

    
    
}
