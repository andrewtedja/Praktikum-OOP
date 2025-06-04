package tutorial6;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class IntegerListProcessor {
    private static void printList(List<Integer> list) {
        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i));
            if (i < list.size() - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        List<Integer> list1 = new ArrayList<>();


        // 1. Baca N. N adalah jumlah input
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        // System.out.println(N);

        // 2. Baca N bilangan dan simpan ke List<Integer>
        for (int i = 0; i < N; i++) {
            list1.add(scanner.nextInt());
        }
        
        // 3. Hapus semua elemen genap
        list1.removeIf(num -> num % 2 == 0);
        // printList(list1);
        // 7 5 3

        // 4. Jika panjang list sekarang ganjil, sort ascending; else sort descending
        if (list1.size() % 2 == 1) {
            Collections.sort(list1);
        } else {
            Collections.sort(list1, Collections.reverseOrder());
        }
        // printList(list1);

        // 3 5 7

        // 5. Untuk setiap elemen, kalikan dengan tiga
        for (int i = 0; i < list1.size(); i++) {
            list1.set(i, list1.get(i) * 3);
        }

        // 6. Cetak elemen menggunakan method printList
        printList(list1);

        scanner.close();
    }
}
