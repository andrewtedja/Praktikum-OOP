public class Main {
    public static void main(String[] args) {
        Enclosure enc1 = new Enclosure();
        Panda panda1 = new Panda("po", 5);
        Panda panda2 = new Panda("po2", 5);
        enc1.addAnimal(panda1);
        enc1.addAnimal(panda2);

        System.out.println(enc1.safeForPetting());
        enc1.describe();

    }
}