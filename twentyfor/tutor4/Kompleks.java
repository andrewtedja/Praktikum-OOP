
public class Kompleks {
    private int real;
    private int imag;
    private static int n_kompleks;

    // public Kompleks() {
    //     this.real = 0;
    //     this.imag = 0;
    // }
    public Kompleks() {
        this(0,0);
    }

    public Kompleks(int real, int imag) {
        this.real = real;
        this.imag = imag;
    }

    public int getReal() {
        return real;
    }

    public int getImag() {
        return imag;
    }

    public void setReal(int r) {
        this.real = r;
    }

    public void setImaginer(int i) {
        this.imag = i;
    }

    public Kompleks plus(Kompleks b) {
        return new Kompleks(this.real + b.getReal(), this.imag + b.getImag());
    }

    
    public Kompleks minus(Kompleks b) {
        return new Kompleks(this.real - b.getReal(), this.imag - b.getImag());
    }

    // (2 + i)(3 + 2i) = 6 + 4i + 3i + 2i^2
    public Kompleks multiply(Kompleks b) {
        return new Kompleks((this.real * b.getReal() - this.imag * b.getImag()),  (this.imag * b.getReal() + this.real * b.getImag() ));
    }

    public Kompleks multiply (int n){
        return new Kompleks(real * n, imag * n);
    }

    public static int countKompleksInstance() {
        return Kompleks.n_kompleks;
    }

    public void print(){
        if (imag < 0){
            if (real == 0) System.out.println(imag + "i");
            else System.out.println(real + Integer.toString(imag) + "i");
        } else if (imag > 0) {
            if (real == 0) System.out.println(imag + "i");
            else System.out.println(real + "+" + imag + "i");
        } else {
            System.out.println(real);
        }
    }
}