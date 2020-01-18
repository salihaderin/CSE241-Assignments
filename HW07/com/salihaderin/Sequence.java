package com.salihaderin;

/**
 * Created for isSequenceValid method
 */
public class Sequence {

    /**
     * Starts from last element
     * According to last move checks the previous board
     * @param arr is an array of AbstractBoard
     * @return false if sequence is invalid.
     * @throws RuntimeException if there is a problem with the method.
     */
    public static boolean isSequenceValid(AbstractBoard[] arr) throws RuntimeException{
        for (int i = arr.length - 1; i > 1; --i) {
            for (int j = 1; j < arr[i].getR(); ++j) {
                for (int k = 1; k < arr[i].getC(); ++k) {
                    if(arr[i].cell(j, k).equals("bb")) {
                        switch (arr[i].lastMove()) {
                            case 'R':
                                if(!arr[i - 1].cell(j, (k - 1)).equals("bb"))
                                    return false;
                                break;
                            case 'L':
                                if(!arr[i - 1].cell(j, (k + 1)).equals("bb"))
                                    return false;
                                break;
                            case 'U':
                                if(!arr[i - 1].cell((j + 1), k).equals("bb"))
                                    return false;
                                break;
                            case 'D':
                                if(!arr[i - 1].cell((j - 1), k).equals("bb"))
                                    return false;
                                break;
                            default:
                                throw new RuntimeException("Invalid last move.");
                        }
                    }
                }
            }
        }
        return true;
    }
}
