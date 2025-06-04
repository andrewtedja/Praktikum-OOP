package prak5;

public class Queue<T> {
    private static final int MAX_CAPACITY = 20;
    private final T[] data;
    private int head, tail;

    public Queue() {
        this.data = (T[]) new Object[MAX_CAPACITY];

        head = 0;
        tail = -1;
    }

      // Ctor queue terisi dari array dengan alokasi kapasitas maksimum.
    // Copy array dari indeks ke-0 hingga terakhir (data.length)
    // Boleh dilakukan secara copy reference object (bukan reference array)
    public Queue(T[] data) { 
        this.data = (T[]) new Object[MAX_CAPACITY];
        this.head = 0;
        this.tail = -1;
        
        for (int i = 0; i < data.length && i < MAX_CAPACITY; i++ ){ 
            this.data[i] = data[i];
            this.tail++;
        }


    }

    // Mengintip element paling depan pada queue.
    // Jika queue kosong, return null
    public T peek() {
        if (this.size() == 0) {
            return null;
        }

        return this.data[head];
    }

    // Mengeluarkan elemen paling depan dari queue.
    // Jika queue kosong, return null
    public T pop() { 
        if (this.size() == 0) {
            return null;
        }
        T temp = this.data[head];
        this.head++;

        return temp;
    }

    // Menambahkan elemen ke dalam queue.
    // Prekondisi: tail < MAX_CAPACITY - 2 (tidak perlu divalidasi)
    public void push(T o) { 
        this.data[++tail] = o;
    }

    // Menghitung panjang queue.
    public int size() { 
        return (this.tail - this.head + 1);
    }

    // Getter attribute
    public T[] getData() { 
        return this.data;
    }
    public int getHead() { 
        return this.head;
    }
    public int getTail() { 
        return this.tail;
    }


}

