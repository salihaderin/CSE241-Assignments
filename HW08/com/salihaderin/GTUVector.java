package com.salihaderin;

/**
 * The Vector class implements a growable array of objects.
 * Like an array, it contains components that can be accessed using an integer index.
 * @param <E> is the type of elements in the vector
 */

public class GTUVector<E> extends GTUContainer<E> {

    /**
     * Constructor
     */
    public GTUVector() {
        sizeVal = 0;
        capacity = 0;
    }

    @Override
    public boolean empty() {
        return this.sizeVal <= 0;
    }

    @Override
    public int size() {
        return this.sizeVal;
    }

    @Override
    public int maxsize() {
        return this.capacity;
    }

    @Override
    @SuppressWarnings("unchecked")
    public void insert(Object o) {
        int check = this.maxsize() - this.size();
        if (check == 0)
            this.capacity++;
        E[] temp = (E[]) new Object[this.capacity];
        if (this.size() > 0)
            System.arraycopy(this.arr, 0, temp, 0, this.size());
        temp[this.size()] = (E)o;
        this.arr = temp;
        this.sizeVal++;
    }

    @Override
    @SuppressWarnings("unchecked")
    public void erase(Object o) throws IllegalArgumentException {
        if (!this.contains(o))
            throw new IllegalArgumentException("The element you've tried to erase cannot be found.");
        else {
            for (int i = 0; i < this.sizeVal; ++i) {
                if (this.arr[i].equals(o)) {
                    E[] temp = (E[])new Object[arr.length - 1];
                    System.arraycopy(this.arr, 0, temp, 0, i);
                    System.arraycopy(this.arr, i + 1, temp, i, (temp.length - i));
                    this.arr = temp;
                    this.sizeVal--;
                }
            }
        }
    }

    @Override
    public void clear() {
        Iterator<E> iter = this.iterator();
        if (!this.empty()) {
            this.erase(this.arr[0]);
            while (iter.hasNext())
                this.erase(iter.next());
        }
    }

    @Override
    public Iterator<E> iterator() {
        return new Iterator<E>(arr);
    }

    @Override
    public boolean contains(Object o) {
        for (int i = 0; i < this.size(); ++i) {
            if (this.arr[i].equals(o))
                return true;
        }
        return false;
    }
}
