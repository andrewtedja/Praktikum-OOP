package prak6;
class Couple<K, V>{
    private K key;
    private V value;

    public Couple(K key, V value) {
        this.key = key;
        this.value = value;
    }

    //getter setter
    public K getKey() {
        return this.key;
    }

    public V getVal() {
        return this.value;
    }

    public void setKey(K newKey) {
        this.key = newKey;
    }

    public void setVal(V newVal) {
        this.value = newVal;
    }

    public boolean isEqual(Couple c) {
        if (this.key == c.getKey() && this.value == c.getVal()) {
            return true;
        }
        return false;
    }

    public int nearEQ(Couple couple) {
        if (this.key != couple.getKey() && this.value != couple.getVal()) {
            return 0;
        } else if (this.key == couple.getKey() && this.value != couple.getVal()) {
            return 1;
        } else if (this.key != couple.getKey() && this.value == couple.getVal()) {
            return 2;
        } else {
            return 3;
        }
    }
}