package com.salihaderin;

/**
 * A collection that contains no duplicate elements.
 * More formally, sets contain no pair of elements e1 and e2 such that e1.equals(e2), and at most one null element.
 * @param <E> is the type of elements in the set
 */
public class GTUSet<E> extends GTUContainer<E> {

    /**
     *Constructor
     */
    public GTUSet() {
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

    /**
     * Since a set does not contain any duplicate element,
     * also tests whether this set contains o olement.
     * @throws IllegalArgumentException if it contains.
     *
     */
    @Override
    @SuppressWarnings("unchecked")
    public void insert(Object o) throws IllegalArgumentException {
        int check = this.maxsize() - this.size();
        if (this.contains(o))
            throw new IllegalArgumentException("Element already exist.");
        else {
            if (check == 0)
                this.capacity++;
            E[] newArr = (E[]) new Object[this.capacity];
            if (this.size() > 0)
                System.arraycopy(this.arr, 0, newArr, 0, this.size());
            this.arr = newArr;
            this.arr[this.size()] = (E)o;
            this.sizeVal++;
        }
    }

    /**
     * @param o is the element.
     * Test whether the element exists in container.
     * Erase if it exists.
     * @throws IllegalArgumentException
     * Since a set contains at most one null element, also decreasing capacity here.
     */
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
                    this.capacity--;
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
                erase(iter.next());
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
