package org.example;

import javax.crypto.*;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.PBEKeySpec;
import javax.crypto.spec.SecretKeySpec;
import java.math.BigInteger;
import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;
import java.security.spec.InvalidKeySpecException;

public class Main {
    public static void main(String[] args) throws NoSuchPaddingException, NoSuchAlgorithmException, ShortBufferException, IllegalBlockSizeException, BadPaddingException, InvalidAlgorithmParameterException, InvalidKeyException, InvalidKeySpecException {

        SecureRandom myPRNG = new SecureRandom();
        char[] password = "password123".toCharArray();
        byte[] salt = new byte[18];
        int iteration_count = 100;

        int key_size = 64;
        // set salt values to random
        myPRNG.nextBytes(salt);

        // initialize key factory for HMAC-SHA1 derivation
        SecretKeyFactory keyFactory =
                SecretKeyFactory.getInstance("PBKDF2WithHmacSHA1");
        // set key specification
        PBEKeySpec pbekSpec = new PBEKeySpec(password, salt, iteration_count, key_size);
        // generate the key
        SecretKey myDESPVKey = new SecretKeySpec(
                keyFactory.generateSecret(pbekSpec).getEncoded(), "DES");

        System.out.println("DES key: " +
                new BigInteger(1, myDESPVKey.getEncoded()).toString(16));


        // get a Cipher instance for DES with CBC, PKCS5 padding
        Cipher myDES = Cipher.getInstance("DES/CBC/PKCS5Padding");

        // encrypt and decrypt a 18B message, having the secret password derived key

        byte[] plaintext = new byte[18];
        byte[] ciphertext = new byte[24];


        myDES.init(Cipher.ENCRYPT_MODE, myDESPVKey, new IvParameterSpec(new byte[8]));
        myDES.doFinal(plaintext, 0, 18, ciphertext, 0);

        // update cipher with the plaintext
        int cLength = myDES.update(plaintext, 0, plaintext.length, ciphertext,
                0);
        // process remaining blocks of plaintext
        cLength += myDES.doFinal(ciphertext, cLength);

        // print plaintext and ciphertext
        System.out.println("plaintext: " +
                new BigInteger(1, plaintext).toString(16));
        System.out.println("ciphertext: " +
                new BigInteger(1, ciphertext).toString(16));


        // initialize AES for decryption
        myDES.init(Cipher.DECRYPT_MODE, myDESPVKey, new IvParameterSpec(new byte[8]));
        // initialize a new array of bytes to place the decryption
        byte[] dec_plaintext = new byte[18];
        cLength = myDES.update(ciphertext, 0, ciphertext.length, dec_plaintext,
                0);
        // process remaining blocks of ciphertext
        cLength += myDES.doFinal(dec_plaintext, cLength);
        // print the new plaintext (hopefully identical to the initial one)
        System.out.println("decrypted: " +
                new BigInteger(1, dec_plaintext).toString(16));

    }
}