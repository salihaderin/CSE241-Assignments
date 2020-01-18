package com.salihaderin;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;
import java.util.StringTokenizer;

/**
 * Class that creates board as 2D and its operations
 * Extends AbstractBoard
 */
public class BoardArray2D extends AbstractBoard {

    /**
     * Board as 2D String array
     */
    private String[][] board;

    /**
     * Board of solution as 2D String array
     */
    private String[][] finalBoard;

    /**
     * Default constructor
     */
    public BoardArray2D() {
        numOfMoves = 0;
        lastM = 'S';
        r = 0;
        c = 0;
        int capacity = 1000;
        board = new String[capacity/10][capacity/10];
        finalBoard = new String[capacity/10][capacity/10];
        boardNum++;
    }

    /**
     * Constructor with parameters
     * @param row is the row number of board
     * @param column is the column number of board
     */
    public BoardArray2D(int row, int column) {
        numOfMoves = 0;
        lastM = 'S';
        setsize(row, column);
        board = new String[row][column];
        finalBoard = new String[row][column];
        boardNum++;
    }

    /**
     * Copy constructor
     * @param obj is the object to be copied
     */
    public BoardArray2D(BoardArray2D obj) {
        this.numOfMoves = obj.numOfMoves;
        this.lastM = obj.lastM;
        this.r = obj.r;
        this.c = obj.c;
        this.board = new String[obj.r][obj.c];
        this.finalBoard = new String[obj.r][obj.c];
        for (int i = 0; i < obj.r; ++i) {
            for (int j = 0; j < obj.c; ++j) {
                this.board[i][j] = obj.board[i][j];
                this.finalBoard[i][j] = obj.finalBoard[i][j];
            }
        }
        boardNum++;
    }

    /**
     *Mutator method for r element.
     * @param row is the new value of r
     */
    public void setR(int row) {
        this.r = row;
    }

    /**
     * Accessor method for r element
     * @return protected int r
     */
    public int getR() {
        return r;
    }

    /**
     * Mutator method for c element
     * @param column is the new value of c.
     */
    public void setC(int column) {
        this.c = column;
    }

    /**
     * Accessor method for c element.
     * @return protected int c
     */
    public int getC() {
        return c;
    }

    /**
     * Creates solution
     * Copies the 00 elements to exactly the same place
     * Sorts numbers
     */
    private void createFinalBoard() {
        int n = 1, i = 0, j = 0;
        String temp;
        while(board[i][j] != null){
            while(board[i][j] != null) {
                if(board[i][j].equals("00"))
                    finalBoard[i][j] = "00";
                else if(i == (this.r - 1) && j == (this.c - 1))
                    finalBoard[i][j] = "bb";
                else{
                    if(n < 10){
                        temp = "0" + n;
                        finalBoard[i][j] = temp;
                    }
                    else
                        finalBoard[i][j] = String.valueOf(n);
                    n++;
                }
                j++;
            }
            i++;
            j = 0;
        }
    }

    /**
     * @param m is the move to control whether it is valid or not.
     * @param i is the row index of the bb element of the board.
     * @param j is the column index of the bb element of the board.
     * Control method for the borders and 00's.
     * @return true if move is valid
     * @throws RuntimeException if move is invalid.
     */
    public boolean isMoveValid(char m, int i, int j) throws RuntimeException{
        if(m == 'R'){
            if(j == (this.c - 1))
                throw new RuntimeException("Right move is invalid.");
            else if((board[i][j + 1]).equals("00"))
                throw new RuntimeException("Right move is invalid.");
            else
                return true;
        }
        else if(m == 'L'){
            if(j == 0)
                throw new RuntimeException("Left move is invalid.");
            else if(board[i][j - 1].equals("00"))
                throw new RuntimeException("Left move is invalid.");
            else
                return true;
        }
        else if(m == 'U'){
            if((i == 0))
                throw new RuntimeException("Up move is invalid.");
            else if(board[i - 1][j].equals("00"))
                throw new RuntimeException("Up move is invalid.");
            else
                return true;
        }
        else if(m == 'D'){
            if(i == (r - 1))
                throw new RuntimeException("Down move is invalid.");
            else if(board[i + 1][j].equals("00"))
                throw new RuntimeException("Down move is invalid.");
            else
                return true;
        }
        else
            throw new RuntimeException("Invalid move.");
    }

    /**
     * Generates board as a string using String Builder
     * Appends " " and new line
     */
    @Override
    public String generateBoardStr(){
        StringBuilder boardStr = new StringBuilder();
        for (int i = 0; i < this.r; ++i){
            for (int j = 0; j < this.c; ++j){
                boardStr.append(board[i][j]);
                if(j != this.c - 1)
                    boardStr.append(" ");
                else
                    boardStr.append("\n");
            }
        }
        return boardStr.toString();
    }

    /**
     * compareTo method of Comparable interface, compares two boards using their string version
     */
    @Override
    public int compareTo(AbstractBoard o) {
        if(this.generateBoardStr().equals(o.generateBoardStr()))
            return 1;
        else
            return 0;
    }

    /**
     * toString method using another method.
     * @return String of the board.
     */
    @Override
    public String toString() {
        return "BoardArray2D:\n" + generateBoardStr();
    }

    /**
     * Method to read board from a file.
     * Scans file line by line, puts elements into board array using string tokenizer
     */
    @Override
    public void readFromFile(String fileName) throws IOException {
        if(Files.notExists(Paths.get(fileName)))
            throw new FileNotFoundException("File could not be found.");
        else{
            File f = new File(fileName);
            Scanner s = new Scanner(f);
            int i = 0;
            int j = 0;
            while (s.hasNextLine()){
                String line = s.nextLine();
                StringTokenizer token = new StringTokenizer(line);
                if(i == 0)
                    setC(token.countTokens());
                while (token.hasMoreTokens()){
                    board[i][j] = token.nextToken();
                    j++;
                }
                i++;
                j = 0;
                setR(this.r + 1);
            }
        }
    }

    /**
     * Method to write the board into the given file
     */
    @Override
    public void writeToFile(String fileName) throws IOException {
        FileWriter f = new FileWriter(fileName);
        int i = 0, j = 0;
        while (board[i][j] != null){
            while (j < this.c){
                f.write(board[i][j]);
                if(j != this.c - 1)
                    f.write(' ');
                j++;
            }
            j = 0;
            f.write('\n');
            i++;
        }
        f.close();
    }

    /**
     * Calls method to create solution
     * Assigns final board to the board
     */
    @Override
    public void reset() {
        int i = 0, j = 0;
        this.createFinalBoard();
        while(board[i][j] != null)
        {
            while (j != this.c){
                board[i][j] = finalBoard[i][j];
                j++;
            }
            i++;
            j = 0;
        }
        System.out.println("---Board reset---");
        lastM = 'S';
        numOfMoves = 0;
    }

    /**
     * Setter for the sizes
     * Allocates memory for the dynamic arrays
     */
    @Override
    public void setsize(int row, int column) {
        setR(row);
        setC(column);
        board = new String[row][column];
        finalBoard = new String[row][column];
    }

    /**
     * Checks if the move is valid
     * Swaps the relevant elements
     * Updates the number of moves and the last move
     */
    @Override
    public void move(char m) throws RuntimeException {
        String temp;
        int i = 0, j = 0;
        try {
            while(board[i][j] != null) {
                while (board[i][j] != null){
                    if(board[i][j].equals("bb")) {
                        if(m == 'R' && this.isMoveValid(m, i, j)){
                            temp = board[i][j + 1];
                            board[i][j + 1] = board[i][j];
                            board[i][j] = temp;
                            numOfMoves++;
                            lastM = 'R';
                            break;
                        }
                        else if(m == 'L' && this.isMoveValid(m, i, j)){
                            temp = board[i][j - 1];
                            board[i][j - 1] = board[i][j];
                            board[i][j] = temp;
                            numOfMoves++;
                            lastM = 'L';
                            break;
                        }
                        else if(m == 'U' && this.isMoveValid(m, i, j)){
                            temp = board[i - 1][j];
                            board[i - 1][j] = board[i][j];
                            board[i][j] = temp;
                            numOfMoves++;
                            lastM = 'U';
                            break;
                        }
                        else if(m == 'D' && this.isMoveValid(m, i, j)){
                            temp = board[i + 1][j];
                            board[i + 1][j] = board[i][j];
                            board[i][j] = temp;
                            numOfMoves++;
                            lastM = 'D';
                            break;
                        }
                    }
                    j++;
                }
                j = 0;
                i++;
            }

        } catch (RuntimeException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    /**
     * Compares board with final board
     */
    @Override
    public boolean isSolved() {
        for(int i = 0; i < this.r; ++i){
            for(int j = 0; j < this.c; ++j){
                if(!board[i][j].equals(finalBoard[i][j]))
                    return false;
            }
        }
        return true;
    }

    /**
     * Checks if the indexes are valid
     * If it is valid, returns the value
     */
    @Override
    public String cell(int row, int column) throws ArrayIndexOutOfBoundsException{
        if((row < 1) || (row > r) || (column < 1) || (column > c)){
            throw new ArrayIndexOutOfBoundsException("Invalid row and column.");
        }
        else
            return board[row - 1][column - 1];
    }

    /**
     * Checks if two objects are equal using compareTo method
     */
    @Override
    public boolean Equals(AbstractBoard obj) {
        return this.compareTo(obj) > 0;
    }

    /**
     *Accessor method for the last move
     */
    @Override
    public char lastMove() {
        return lastM;
    }

    /**
     *Accessor method for the number of moves
     */
    @Override
    public int numberOfMoves() {
        return numOfMoves;
    }

}

