package com.salihaderin;

import java.io.IOException;
import java.util.Scanner;

import static com.salihaderin.Sequence.isSequenceValid;

/**
 * Driver class
 */
public class Test {

    /**
     * Tests all methods of BoardArray1D class
     * Handles its exceptions.
     */
    public static void BoardArray1DTest() {
        /*System.out.print("Enter file name: ");
        Scanner s = new Scanner(System.in);
        String fileName = s.next();*/
        String fileName = "file.txt";

        BoardArray1D b = new BoardArray1D();
        BoardArray1D a = new BoardArray1D();

        /*
         *testing in try-catch block
         */
        try {
            String f;
            Scanner s;
            char m;

            /*
             *testing equals method by reading the same file
             *also testing readFromFile method
             */
            b.readFromFile(fileName);
            a.readFromFile(fileName);
            if(b.Equals(a))
                System.out.println("Board b and board a are equal.");

            /*
             *testing getters and overloaded toString method
             */
            System.out.println("Row number: " + b.getR());
            System.out.println("Column number: " + b.getC());
            System.out.print(b.toString());

            /*
             *testing move method
             *testing my isMoveValid method since move method calls it
             *testing isSolved method as it is a loop condition
             */
            System.out.println("Enter Q to quit.");
            do{
                System.out.print("Move: ");
                s = new Scanner(System.in);
                m = s.next().charAt(0);
                switch (m){
                    case 'R':
                        b.move('R');
                        System.out.print(b.toString());
                        break;
                    case 'L':
                        b.move('L');
                        System.out.print(b.toString());
                        break;
                    case 'U':
                        b.move('U');
                        System.out.print(b.toString());
                        break;
                    case 'D':
                        b.move('D');
                        System.out.print(b.toString());
                        break;
                    case 'Q':
                        break;
                    default:
                        throw new RuntimeException("Invalid move.");
                }
            }while(!b.isSolved() && !(m == 'Q'));

            /*
             *testing isSolved and reset methods
             */
            b.reset();
            if(b.isSolved())
                System.out.println("SOLVED");

            /*
             *testing lastMove, numberOfMoves and static NumberOfBoards methods
             */
            System.out.println("Last move: " + b.lastMove());
            System.out.println("Move count: " + b.numberOfMoves());
            System.out.println("Board count: " + BoardArray1D.NumberOfBoards());

            /*
             *testing equals method again
             */
            if(!b.Equals(a))
                System.out.println("Board b and board a are not equal now.");
            else
                System.out.println("Board b and board a are still equal.");

            /*
             *testing writeToFile method
             */
            /*System.out.println("Enter file name to write the board: ");
            s = new Scanner(System.in);
            f = s.next();*/
            b.writeToFile("newFile.txt");
            s.close();
            b.reset();
            System.out.println(b.toString());
        } catch (RuntimeException | IOException e) {
            System.out.println("Error: " + e.getMessage());
        }

        /*
         *testing cell method
         */
        try {
            for(int i = 1; i <= b.getR(); ++i){
                for (int j = 1; j <= b.getC(); ++j){
                    System.out.println("Cell(" + i + ", " + j + "): " + b.cell(i, j));
                }
            }
            //what happens when cell does not exists
            //System.out.print("Cell(" + 1000 + ", " + 1000 + "): ");
            //b.cell(1000, 1000);
        }catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    /**
     * Tests all methods of BoardArray2D class
     * Handles its exceptions.
     */
    public static void BoardArray2DTest() {
        /*System.out.print("Enter file name: ");
        Scanner s = new Scanner(System.in);
        String fileName = s.next();*/
        String fileName = "file.txt";

        BoardArray2D b = new BoardArray2D();
        BoardArray2D a = new BoardArray2D();

        /*
         *testing in try-catch block
         */
        try {
            String f;
            Scanner s;
            char m;

            /*
             *testing equals method by reading the same file
             *also testing readFromFile method
             */
            b.readFromFile(fileName);
            a.readFromFile(fileName);
            if(b.Equals(a))
                System.out.println("Board b and board a are equal.");

            /*
             *testing getters and overloaded toString method
             */
            System.out.println("Row number: " + b.getR());
            System.out.println("Column number: " + b.getC());
            System.out.print(b.toString());

            /*
             *testing move method
             *testing my isMoveValid method since move method calls it
             *testing isSolved method as it is a loop condition
             */
            System.out.println("Enter Q to quit.");
            do{
                System.out.print("Move: ");
                s = new Scanner(System.in);
                m = s.next().charAt(0);
                switch (m){
                    case 'R':
                        b.move('R');
                        System.out.print(b.toString());
                        break;
                    case 'L':
                        b.move('L');
                        System.out.print(b.toString());
                        break;
                    case 'U':
                        b.move('U');
                        System.out.print(b.toString());
                        break;
                    case 'D':
                        b.move('D');
                        System.out.print(b.toString());
                        break;
                    case 'Q':
                        break;
                    default:
                        throw new RuntimeException("Invalid move.");
                }
            }while(!b.isSolved() && !(m == 'Q'));

            /*
             *testing isSolved and reset methods
             */
            b.reset();
            if(b.isSolved())
                System.out.println("SOLVED");

            /*
             *testing lastMove, numberOfMoves and static NumberOfBoards methods
             */
            System.out.println("Last move: " + b.lastMove());
            System.out.println("Move count: " + b.numberOfMoves());
            System.out.println("Board count: " + BoardArray2D.NumberOfBoards());

            /*
             *testing equals method again
             */
            if(!b.Equals(a))
                System.out.println("Board b and board a are not equal now.");
            else
                System.out.println("Board b and board a are still equal.");

            /*
             *testing writeToFile method
             */
            /*System.out.println("Enter file name to write the board: ");
            s = new Scanner(System.in);
            f = s.next();*/
            b.writeToFile("newFile.txt");
            s.close();
            b.reset();
            System.out.println(b.toString());
        } catch (RuntimeException | IOException e) {
            System.out.println("Error: " + e.getMessage());
        }

        /*
         *testing cell method
         */
        try {
            for(int i = 1; i <= b.getR(); ++i){
                for (int j = 1; j <= b.getC(); ++j){
                    System.out.println("Cell(" + i + ", " + j + "): " + b.cell(i, j));
                }
            }
            //what happens when cell does not exists
            //System.out.print("Cell(" + 1000 + ", " + 1000 + "): ");
            //b.cell(1000, 1000);
        }catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    /**
     * Tests isSequenceValid method for BoardArray1D
     * Handles its exceptions.
     */
    public static void sequenceTest1D() {
        BoardArray1D[] arr1d = new BoardArray1D[10];
        BoardArray1D board1d = new BoardArray1D();
        String fileName;
        /*System.out.println("Enter a file name: ");
        Scanner s = new Scanner(System.in);
        fileName = s.next();*/
        fileName = "file.txt";
        try {
            board1d.readFromFile(fileName);
            arr1d[0] = board1d;
            System.out.println(board1d.toString());
            board1d.move('R');
            BoardArray1D temp;
            temp = new BoardArray1D(board1d);
            System.out.println(board1d.toString());
            arr1d[1] = temp;
            board1d.move('U');
            temp = new BoardArray1D(board1d);
            System.out.println(board1d.toString());
            arr1d[2] = temp;
            board1d.move('R');
            temp = new BoardArray1D(board1d);
            System.out.println(board1d.toString());
            arr1d[3] = temp;
            board1d.move('R');
            temp = new BoardArray1D(board1d);
            System.out.println(board1d.toString());
            arr1d[4] = temp;
            board1d.move('U');
            temp = new BoardArray1D(board1d);
            System.out.println(board1d.toString());
            arr1d[5] = temp;
            board1d.move('R');
            temp = new BoardArray1D(board1d);
            System.out.println(board1d.toString());
            arr1d[6] = temp;
            board1d.move('U');
            temp = new BoardArray1D(board1d);
            System.out.println(board1d.toString());
            arr1d[7] = temp;
            board1d.move('R');
            temp = new BoardArray1D(board1d);
            System.out.println(board1d.toString());
            arr1d[8] = temp;
            board1d.move('D');
            temp = new BoardArray1D(board1d);
            System.out.println(board1d.toString());
            arr1d[9] = temp;

            if(isSequenceValid(arr1d))
                System.out.println("(BoardArray1D) arr1d sequence is valid.");
            else
                System.out.println("(BoardArray1D) arr1d sequence is invalid.");

            board1d.move('U');
            temp = new BoardArray1D(board1d);
            System.out.println("Changing last element to test what happens when array sequence is invalid...");
            System.out.println(board1d.toString());
            arr1d[9] = temp;

            if(isSequenceValid(arr1d))
                System.out.println("(BoardArray1D) arr1d sequence is valid.");
            else
                System.out.println("(BoardArray1D) arr1d sequence is invalid.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Test isSequenceValid method for BoardArray2D
     * Handles its exceptions.
     */
    public static void sequenceTest2D() {
        BoardArray2D[] arr2d = new BoardArray2D[10];
        BoardArray2D board2d = new BoardArray2D();
        String fileName;
        /*System.out.println("Enter a file name: ");
        Scanner s = new Scanner(System.in);
        fileName = s.next();*/
        fileName = "file.txt";
        try {
            board2d.readFromFile(fileName);
            arr2d[0] = board2d;
            System.out.println(board2d.toString());
            board2d.move('R');
            BoardArray2D temp;
            temp = new BoardArray2D(board2d);
            System.out.println(board2d.toString());
            arr2d[1] = temp;
            board2d.move('U');
            temp = new BoardArray2D(board2d);
            System.out.println(board2d.toString());
            arr2d[2] = temp;
            board2d.move('R');
            temp = new BoardArray2D(board2d);
            System.out.println(board2d.toString());
            arr2d[3] = temp;
            board2d.move('R');
            temp = new BoardArray2D(board2d);
            System.out.println(board2d.toString());
            arr2d[4] = temp;
            board2d.move('U');
            temp = new BoardArray2D(board2d);
            System.out.println(board2d.toString());
            arr2d[5] = temp;
            board2d.move('R');
            temp = new BoardArray2D(board2d);
            System.out.println(board2d.toString());
            arr2d[6] = temp;
            board2d.move('U');
            temp = new BoardArray2D(board2d);
            System.out.println(board2d.toString());
            arr2d[7] = temp;
            board2d.move('R');
            temp = new BoardArray2D(board2d);
            System.out.println(board2d.toString());
            arr2d[8] = temp;
            board2d.move('D');
            temp = new BoardArray2D(board2d);
            System.out.println(board2d.toString());
            arr2d[9] = temp;

            if(isSequenceValid(arr2d))
                System.out.println("(BoardArray2D) arr2d sequence is valid.");
            else
                System.out.println("(BoardArray2D) arr2d sequence is invalid.");

            board2d.move('U');
            temp = new BoardArray2D(board2d);
            System.out.println("Changing last element to test what happens when array sequence is invalid...");
            System.out.println(board2d.toString());
            arr2d[9] = temp;

            if(isSequenceValid(arr2d))
                System.out.println("(BoardArray2D) arr2d sequence is valid.");
            else
                System.out.println("(BoardArray2D) arr2d sequence is invalid.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}