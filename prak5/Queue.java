package prak5;

public class Queue<T> {
    private static final int MAX_CAPACITY = 20;
    private int head, tail;
    private T[] data;

    public Queue() {
        this.data = (T[]) new Object[MAX_CAPACITY];
        this.head = 0;
        this.tail = -1;
    }


    public Queue(T[] data) {
        this.data = (T[]) new Object[MAX_CAPACITY]



        this.head = 0;
        this.tail = -1;


        for (int i = 0; i < data.length && i < MAX_CAPACITY; i++) {
            this.data[i] = data[i];
            this.tail++;
        }
    }

    public T peek() {
        if (this.size() == 0) {
            return null;
        }

        return this.data[head];
    }


    public T pop() {
        if (this.size() == 0) {
            return null;
        }
        T temp = this.data[head];
        head++;

        return temp;
    }
    
    public void push(T o) {
        this.data[++tail] = o;
    }


    public int size() {
        return this.tail - this.head + 1;
    }

    
}
