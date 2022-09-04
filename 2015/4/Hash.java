import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class Hash {

    public static void main(String[] args) {
        String input = "iwrupvqb";

        for (int n = 1; n > 0; n++) {
            String string = input + Integer.toString(n);

            String[] charc = getMd5(string).split("");

            if (charc[0].equals((String)"0") && charc[1].equals((String)"0") &&
             charc[2].equals((String)"0") && charc[3].equals((String)"0") &&
              charc[4].equals((String)"0") && charc[5].equals((String) "0")) {
                System.out.println(n);
                break;
            }
        }
    }

    public static String getMd5(String input) {
        try {

            // Static getInstance method is called with hashing MD5
            MessageDigest md = MessageDigest.getInstance("MD5");

            // digest() method is called to calculate message digest
            // of an input digest() return array of byte
            byte[] messageDigest = md.digest(input.getBytes());

            // Convert byte array into signum representation
            BigInteger no = new BigInteger(1, messageDigest);

            // Convert message digest into hex value
            String hashtext = no.toString(16);
            while (hashtext.length() < 32) {
                hashtext = "0" + hashtext;
            }
            return hashtext;
        }

        // For specifying wrong message digest algorithms
        catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }
}