package com.salihaderin;

import java.io.IOException;

/**
 * An abstract class that implements Comparable to be able to compare boards.
 * @author Saliha Derin
 */
public abstract class AbstractBoard implements Comparable<AbstractBoard> {

    /**
     * Static data to count AbstractBoard objects.
     */
    protected static int boardNum = 0;

    /**
     * Last move that executed on the board.
     */
    protected char lastM;

    /**
     * Move number so far.
     */
    protected int numOfMoves;

    /**
     * Row number of the board.
     */
    protected int r;

    /**
     * Column number of the board.
     */
    protected int c;

    /**
     * Overloaded toString method.
     * @return board as a String
     */
    public abstract String toString();

    /**
     * @param fileName is the name of file that will be read.
     * @throws IOException if there is a problem with the file.
     */
    public abstract void readFromFile(String fileName) throws IOException;

    /**
     *
     * @param fileName is the name of file that will be written.
     * @throws IOException if there is a problem with the file writer.
     */
    public abstract void writeToFile(String fileName) throws IOException;

    /**
     * Resets board to the final solution.
     */
    public abstract void reset();

    /**
     * Setter for row and column also allocates memory according to parameters.
     * @param row is the number of rows board has.
     * @param column is the number of the columns board has.
     */
    public abstract void setsize(int row, int column);

    /**
     * @param m is the move to be executed on the board.
     * @throws RuntimeException if move is invalid.
     */
    public abstract void move(char m) throws RuntimeException;

    /**
     * @return true if board equals final solution.
     */
    public abstract boolean isSolved();

    /**
     *
     * @param row index of row to be found
     * @param column index of column to be found
     * @return the String value inside the given indexes.
     * @throws ArrayIndexOutOfBoundsException if indexes are invalid.
     */
    public abstract String cell(int row, int column) throws ArrayIndexOutOfBoundsException;

    /**
     * @param obj is the AbstractBoard to be compared with.
     * @return true if boards are equal.
     */
    public abstract boolean Equals(AbstractBoard obj);

    /**
     * Static method for static data
     * @return protected static int boardNum
     */
    public static int NumberOfBoards() {
        return boardNum;
    }

    /**
     * Accessor method for the last move field.
     * @return protected char lastM
     */
    public abstract char lastMove();

    /**
     * Accessor method for the number of moves field
     * @return protected int numOfMoves
     */
    public abstract int numberOfMoves();

    /**
     * Created to use with toString method.
     * @return board as String.
     */
    public abstract String generateBoardStr();

    /**
     * Accessor method for row field.
     * @return protected int r.
     */
    public abstract int getR();

    /**
     * Accessor method for column field.
     * @return protected int c.
     */
    public abstract int getC();

}

