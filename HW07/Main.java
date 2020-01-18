import com.salihaderin.Test;

import java.util.Scanner;

/**
 * Created to run tests
 */
public class Main {

    public static void main(String[] args) {
        int run;
        boolean check = true;
        Scanner s;
        do {
            System.out.println("Which one to test?");
            System.out.println("Press 1 to test 1D Board");
            System.out.println("Press 2 to test 2D Board");
            System.out.println("Press 3 to test Sequence for 1D Board");
            System.out.println("Press 4 to test Sequence for 2D Board");
            s = new Scanner(System.in);
            run = s.nextInt();
        } while(run != 1 && run != 2 && run != 3 && run != 4);

        switch (run) {
            case 1:
                Test.BoardArray1DTest();
                break;
            case 2:
                Test.BoardArray2DTest();
                break;
            case 3:
                Test.sequenceTest1D();
                break;
            case 4:
                Test.sequenceTest2D();
                break;
        }
    }
}