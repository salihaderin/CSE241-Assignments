package com.salihaderin;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;
import java.io.IOException;
import java.util.StringTokenizer;

/**
 * Class that creates board as 1D and its operations
 * Extends AbstractBoard
 */
public class BoardArray1D extends AbstractBoard {

    /**
     *Board as String array
     */
    private String[] board;

    /**
     * Board of solution as String array
     */
    private String[] finalBoard;

    /**
     *Default constructor
     */
    public BoardArray1D() {
        numOfMoves = 0;
        lastM = 'S';
        r = 0;
        c = 0;
        int capacity = 1000;
        board = new String[capacity];
        finalBoard = new String[capacity];
        boardNum++;
    }

    /**
     *Constructor with parameters
     * @param row is the row number of board
     * @param column is the column number of board
     */
    public BoardArray1D(int row, int column) {
        numOfMoves = 0;
        lastM = 'S';
        setsize(row, column);
        boardNum++;
    }

    /**
     *Copy constructor
     * @param obj is the object to be copied.
     */
    public BoardArray1D(BoardArray1D obj) {
        this.numOfMoves = obj.numOfMoves;
        this.lastM = obj.lastM;
        this.r = obj.r;
        this.c = obj.c;
        int capacity = obj.r * obj.c;
        this.board = new String[capacity];
        this.finalBoard = new String[capacity];
        for (int i = 0; i < capacity; ++i) {
            this.board[i] = obj.board[i];
            this.finalBoard[i] = obj.finalBoard[i];
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
        return this.r;
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
        return this.c;
    }

    /**
     * Creates solution
     * Copies the 00 elements to exactly the same place
     * Sorts numbers
     */
    private void createFinalBoard() {
        int n = 1, i = 0;
        String temp;
        while (board[i] != null){
            if(board[i].equals("00"))
                finalBoard[i] = "00";
            else if(i == this.r * this.c - 1)
                finalBoard[i] = "bb";
            else{
                if(n < 10){
                    temp = "0" + n;
                    finalBoard[i] = temp;
                }
                else
                    finalBoard[i] = String.valueOf(n);
                n++;
            }
            i++;
        }
    }

    /**
     * @param m is the move to control whether it is valid or not.
     * @param i is the index of the bb element of the board.
     * Control method for the borders and 00's.
     * @return true if move is valid
     * @throws RuntimeException if move is invalid.
     */
    public boolean isMoveValid(char m, int i) throws RuntimeException {
        if(m == 'R'){
            if((i + 1) % this.c == 0)
                throw new RuntimeException("Right move is invalid.");
            else if((board[i + 1]).equals("00"))
                throw new RuntimeException("Right move is invalid.");
            else
                return true;
        }
        else if(m == 'L'){
            if((i - 1) % this.c == (this.c - 1))
                throw new RuntimeException("Left move is invalid.");
            else if(board[i - 1].equals("00"))
                throw new RuntimeException("Left move is invalid.");
            else
                return true;
        }
        else if(m == 'U'){
            if((i / c) < 1)
                throw new RuntimeException("Up move is invalid.");
            else if(board[i - c].equals("00"))
                throw new RuntimeException("Up move is invalid.");
            else
                return true;
        }
        else if(m == 'D'){
            if((i + c) > (this.r * this.c - 1))
                throw new RuntimeException("Down move is invalid.");
            else if(board[i + c].equals("00"))
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
        int i = 0;
        while(board[i] != null)
        {
            boardStr.append(board[i]);
            if(i % this.c == this.c - 1)
                boardStr.append("\n");
            else
                boardStr.append(" ");
            i++;
        }

        return boardStr.toString();
    }

    /**
     *compareTo method of Comparable interface, compares two boards using their string version
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
        return "BoardArray1D:\n" + generateBoardStr();
    }

    /**
     * Method to read board from a file.
     * Scans file line by line, puts elements into board array using string tokenizer
     */
    @Override
    public void readFromFile(String fileName) throws IOException{
        if(Files.notExists(Paths.get(fileName)))
            throw new FileNotFoundException("File could not be found.");
        else{
            File f = new File(fileName);
            Scanner s = new Scanner(f);
            int i = 0;
            while(s.hasNextLine()){
                String line = s.nextLine();
                StringTokenizer token = new StringTokenizer(line);
                if(i == 0){
                    setC(token.countTokens());
                }
                while(token.hasMoreTokens()){
                    board[i] = token.nextToken();
                    i++;
                }
                setR(this.r + 1);
            }
            s.close();
        }
        createFinalBoard();
    }

    /**
     * Method to write the board into the given file
     */
    @Override
    public void writeToFile(String fileName) throws IOException {
        FileWriter f = new FileWriter(fileName);
        int i = 0;
        while(board[i] != null) {
            for(int j = 0; j < this.c; ++j){
                f.write(board[i]);
                i++;
                if(j != this.c - 1)
                    f.write(' ');
            }
            f.write('\n');
        }
        f.close();
    }

    /**
     * Calls method to create solution
     * Assigns final board to the board
     */
    @Override
    public void reset() {
        int i = 0;
        this.createFinalBoard();
        while(board[i] != null)
        {
            board[i] = finalBoard[i];
            i++;
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
        board = new String[row];
        finalBoard = new String[column];
    }

    /**
     * Checks if the move is valid
     * Swaps the relevant elements
     * Updates the number of moves and the last move
     */
    @Override
    public void move(char m) throws RuntimeException {
        String temp;
        int i = 0;
        try {
            while (board[i] != null) {
                if(board[i].equals("bb")){
                    if(m == 'R' && this.isMoveValid('R', i)){
                        temp = board[i + 1];
                        board[i + 1] = board[i];
                        board[i] = temp;
                        numOfMoves++;
                        lastM = 'R';
                        break;
                    }
                    else if(m == 'L' && this.isMoveValid('L', i)){
                        temp = board[i - 1];
                        board[i - 1] = board[i];
                        board[i] = temp;
                        numOfMoves++;
                        lastM = 'L';
                        break;
                    }
                    else if(m == 'U' && this.isMoveValid('U', i)){
                        temp = board[i - c];
                        board[i - c] = board[i];
                        board[i] = temp;
                        numOfMoves++;
                        lastM = 'U';
                        break;
                    }
                    else if(m == 'D' && this.isMoveValid('D', i)){
                        temp = board[i + c];
                        board[i + c] = board[i];
                        board[i] = temp;
                        numOfMoves++;
                        lastM = 'D';
                        break;
                    }
                    else{
                        throw new RuntimeException("Invalid move.");
                    }
                }
                i++;
            }
        } catch (RuntimeException e){
            System.out.println("Error:"+ e.getMessage());
        }
    }

    /**
     * Compares board with final board
     */
    @Override
    public boolean isSolved() {
        for(int i = 0; i < this.r * this.c; ++i){
            if(!board[i].equals(finalBoard[i]))
                return false;
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
            return board[(row - 1) * this.c + column - 1];
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
        return this.lastM;
    }

    /**
     *Accessor method for the number of moves
     */
    @Override
    public int numberOfMoves() {
        return this.numOfMoves;
    }

}