package tutorial6;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.lang.reflect.*;

public class Reflection{
    //TIDAK BOLEH MENGUBAH NAMA METHOD YANG SUDAH ADA DAN PARAMS SERTA INPUT TYPENYA
    //BOLEH MENAMBAHKAN PRIVATE / PROTECTED METHOD SESUAI DENGAN KEBUTUHAN
    //DI LUAR SANA ADA KELAS YANG NAMANYA Ghost DAN Secret.

    public ArrayList<String> ghostMethods(){
        ArrayList<String> methodNames = new ArrayList<>();
        Class<?> ghostClass;

        try {
            ghostClass = Class.forName("Ghost");
            Method[] methods = ghostClass.getDeclaredMethods();

            for (Method method : methods) {
                methodNames.add(method.getName());
            }

        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

        return methodNames;
    }   

    public Integer sumGhost() throws Exception{
        Class<?> ghostClass = Class.forName("Ghost");
        Object ghostInstance = ghostClass.getDeclaredConstructor().newInstance();
        Method[] methods = ghostClass.getDeclaredMethods();

        int sum = 0;

        for (Method method : methods) {
            method.setAccessible(true);
            Object result = method.invoke(ghostInstance);
            if (result instanceof Integer) {
                sum += (Integer) result;
            }
        } // ignore yang return String
        return sum;
    }

    public String letterGhost() throws Exception{
        Class<?> ghostClass = Class.forName("Ghost");
        Object ghostInstance = ghostClass.getDeclaredConstructor().newInstance();
        Method[] methods = ghostClass.getDeclaredMethods();

        StringBuilder sb = new StringBuilder();

        for (Method method : methods) {
            method.setAccessible(true);
            Object result = method.invoke(ghostInstance);
            if (result instanceof String) {
                sb.append((String) result);
            }
        }
        return sb.toString();
    }

    public String findSecretId(List<Secret> sl, String email) throws Exception {
        for (Secret s : sl) {
            Method isThisMethod = Secret.class.getDeclaredMethod("isThis", String.class);
            isThisMethod.setAccessible(true);
            boolean match = (boolean) isThisMethod.invoke(s, email);
            if (match) {
                Field uniqueIdField = Secret.class.getDeclaredField("uniqueId");
                uniqueIdField.setAccessible(true);
                return (String) uniqueIdField.get(s);
            }
        }
        return "NaN";
    }


}

// public class Secret {
//     private String email;
//     private String nama;
//     public static Integer counter = 0;
//     private String uniqueId;

//     //KELAS SUDAH PATEN, TIDAK BOLEH DIEDIT EDIT

//     public Secret(String email, String nama){
//         //MAGIC HAPPENED THERE.
//         //Intinya konstruktor biasa, cuma ada randomisasi buat uniqueId, dan jangan lupa
//         //counter++ pada bagan akhir konstruktor ini.
//     }

//     public boolean isThis(String email){
//         //GUNAKAN FUNGSI INI UNTUK MENCOCOKAN EMAIL DENGAN EMAIL YANG DIMILIKI KELAS
//         return this.email.equalsIgnoreCase(email);
//     }

// }
