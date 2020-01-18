import com.salihaderin.Test;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        int run;
        boolean check = true;
        Scanner s;
        do {
            System.out.println("Which one to test?");
            System.out.println("Press 1 to test GTUVector for Integer type.");
            System.out.println("Press 2 to test GTUVector for String type.");
            System.out.println("Press 3 to test GTUSet for Integer type.");
            System.out.println("Press 4 to test GTUSet for String type.");
            System.out.println("Press 0 to exit.");
            s = new Scanner(System.in);
            run = s.nextInt();

            switch (run) {
                case 0:
                    check = false;
                    break;
                case 1:
                    Test.GTUVectorIntegerTest();
                    System.out.println("\n--------------");
                    break;
                case 2:
                    Test.GTUVectorStringTest();
                    System.out.println("\n--------------");
                    break;
                case 3:
                    Test.GTUSetIntegerTest();
                    System.out.println("\n--------------");
                    break;
                case 4:
                    Test.GTUSetStringTest();
                    System.out.println("\n--------------");
                    break;
                default:
                    System.out.println("Invalid choice. Try again.");
                    break;
            }
        } while(check);
    }
}
