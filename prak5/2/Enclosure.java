import java.io.*;
import java.util.*;

public class Enclosure {
    private ArrayList<Animal> animals;

    public Enclosure() {
        this.animals = new ArrayList<>();
    } 

    public int getAnimalCount() {
        return this.animals.size();
    }

    public void addAnimal(Animal animal) {
        // menambahkan seekor hewan ke dalam this.animals
        this.animals.add(animal);
    }

    public Animal getAnimalAt(int i) {
        // mengembalikan hewan dalam this.animals pada index i (tidak mengubah this.animals)
        return this.animals.get(i);
    }

    public void removeAnimalAt(int i) {
        // menghapus hewan pada this.animals pada index i
        this.animals.remove(i);
    }

    public boolean isEmpty() {
        // mengembalikan boolean yang menyatakan apakah this.animals kosong atau tidak
        return this.animals.isEmpty();
    }

    public void describe() {
        // Menuliskan output berikut apabila this.animals kosong:
        // Kandang ini kosong...
        // Apabila tidak kosong menuliskan output serupa dengan output berikut:
        // Kandang berisi 2 ekor hewan:
        // 1. po, spesies Pandamus Maximus, umur 5 tahun
        // 2. po2, spesies Pandamus Maximus, umur 5 tahun
        if (!this.isEmpty()) {
            System.out.println("Kandang berisi " + this.getAnimalCount() + " ekor hewan:");
            for (int i = 0; i < this.getAnimalCount(); i++) {
                System.out.println((i+1) + ". " + this.getAnimalAt(i).getName() + ", spesies " + this.getAnimalAt(i).getSpecies() + ", umur " + this.getAnimalAt(i).getAge() + " tahun");
            }
        } else {
            System.out.println("Kandang ini kosong...");
        }
    }

    public void feed() {
        // Menuliskan output berikut apabila this.animals kosong:
        // Kandang ini kosong...
        // Apabila tidak kosong maka akan memanggil method eat pada tiap animal dalam this.animals
        if (this.isEmpty()) {
            System.out.println("Kandang ini kosong...");
        } else {
            this.animals.forEach((animal -> animal.eat()));
        }
    }

    public boolean safeForPetting() {
        // mengembalikan true apabila semua hewan dalam this.animals bersifat friendly
        for (int i = 0; i < this.getAnimalCount(); i++) {
            if (this.animals.get(i).isFriendly() == false) {
                return false;
            }
        }
        return true;
    }
}