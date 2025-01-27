import java.util.Scanner;

public class PowerConsumption {

    public static void main(String[] args) {
         

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the customer type(domestic/cummercial): ");
        String customerType = scanner.nextLine();

        System.out.print("Enter the number of units to be billed: ");
        double unitsBilled = scanner.nextDouble();

        double totalBilled = 0;
        double Surcharge = 0;
        double fixedRent = 0;
        double rentPerUnit = 0;

        if (customerType.equals("domestic")){
            rentPerUnit = 5;
            fixedRent = 250;
            
        }
        else if (customerType.equals("cummercial")){
            rentPerUnit = 8;
            fixedRent = 1000;

        }
        else {
            System.out.println("Invalid Customer type");
            return;
        }

        totalBilled = (unitsBilled * rentPerUnit)+ fixedRent;

        if (customerType.equals("domestic")&& totalBilled>10000) {
            Surcharge = totalBilled*0.10; 

        }
        else if(customerType.equals("cummercial")&& totalBilled>50000){
            Surcharge = totalBilled*0.10;
        }

        totalBilled += Surcharge;

        System.out.println("Total bill amount Rs."+totalBilled);
        System.out.println("Surcharge: Rs."+Surcharge);

        scanner.close();

    }
}