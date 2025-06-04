import java.util.Objects;

public class Redis<K,V> {

    private K key;
    private V value;
    private long Ttl;

    public Redis(K k, V v, long ttl) {
        if (ttl <= 0) {
            throw new InvalidTtlException("TTL must be positive");
        }
        this.key = k;
        this.value = v;
        this.Ttl = ttl;
    }

    public K getKey() {
        return this.key;
    }

    public V getVal(long elapsedSeconds) throws TtlExpiredException{
        if(elapsedSeconds >= this.Ttl) {
            throw new TtlExpiredException(this.key + " expired");
        }   
        return this.value;
    }

    public void setKey(K k) {
        this.key = k;
    }

    public void setVal(V v) {
        this.value = v;
    }

    public long getRemainingTtl(long elapsedSeconds) {
        return (this.Ttl < elapsedSeconds) ? 0 : this.Ttl - elapsedSeconds;
    }

    public void refresh(long newTtl) throws InvalidTtlException{
        if(newTtl <= 0) {
            throw new InvalidTtlException("TTL must be positive");
        }
        this.Ttl = newTtl;
    }

    public boolean isEqual(Redis<?, ?> c) {
        return Objects.equals(c.key, this.key) && Objects.equals(c.value, this.value);
    }

    public int nearEQ(Redis<?, ?> c) {
        boolean keyEq = Objects.equals(c.key, this.key);
        boolean valEq = Objects.equals(c.value, this.value);

        if(keyEq && valEq) return 3;
        if(valEq) return 2;
        if(keyEq) return 1;
        return 0;
    }

}
