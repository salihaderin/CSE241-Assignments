package com.salihaderin;

import java.util.NoSuchElementException;

/**
 *An iterator over GTUContainer
 * @author Saliha Derin
 *
 * @param <E> is the type of elements returned by iterator
 */
public class Iterator<E> {

    private int index;
    private E[] arr;

    /**
     * Constructor
     * @param arrE is an array of E
     */
    public Iterator(E[] arrE) {
        index = 0;
        arr = arrE;
    }

    /**
     * @return true if the iteration has more elements.
     */
    public boolean hasNext() {
        if (index < (arr.length - 1))
            return arr[index + 1] != null;
        return false;
    }

    /**
     * @return the next element in the iteration.
     */
    public E next() throws NoSuchElementException {
        if(this.hasNext()) {
            index++;
        }
        else
            throw new NoSuchElementException("Iteration has no more elements.");
        return arr[index];
    }
}
