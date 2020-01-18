package com.salihaderin;

/**
 * Generic class with one generic parameter.
 * @author Saliha Derin
 * @param <E> is the type of data.
 */
public abstract class GTUContainer<E> {

    /**
     *Array of E elements
     */
    protected E[] arr;

    /**
     * Number of elements in the array.
     */
    protected int sizeVal;

    /**
     * Limit of the array.
     */
    protected int capacity;


    /**
     * Tests whether container is empty.
     * @return true if container does not have any elements.
     */
    public abstract boolean empty();

    /**
     * @return container size.
     */
    public abstract int size();

    /**
     * @return container capacity.
     */
    public abstract int maxsize();

    /**
     * @param o is the element
     * Tests whether there is enough capacity to insert the element.
     * Inserts the element if there is
     * Allocates enough memory then inserts the element if there is not.
     * @throws IllegalArgumentException for any other problem.
     */
    public abstract void insert(Object o) throws IllegalArgumentException;

    /**
     * @param o is the element.
     * Test whether the element exists in container.
     * Erase if it exists.
     * @throws IllegalArgumentException if it does not.
     */
    public abstract void erase(Object o) throws IllegalArgumentException;

    /**
     * Clears al content.
     */
    public abstract void clear();

    /**
     * @return iterator to begin.
     */
    public abstract Iterator<E> iterator();

    /**
     * @param o is the element.
     * @return true if the container contains the element.
     */
    public abstract boolean contains(Object o);
}
