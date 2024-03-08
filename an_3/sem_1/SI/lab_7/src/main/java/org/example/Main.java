package org.example;


import javax.crypto.*;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.PBEKeySpec;
import javax.crypto.spec.SecretKeySpec;
import java.io.UnsupportedEncodingException;
import java.math.BigInteger;
import java.security.*;
import java.security.spec.InvalidKeySpecException;

public class Main {
    public static void main(String[] args) throws NoSuchPaddingException, NoSuchAlgorithmException, ShortBufferException, IllegalBlockSizeException, BadPaddingException, InvalidKeyException, UnsupportedEncodingException, InvalidAlgorithmParameterException, InvalidKeySpecException {
        ex2();
    }

    public static void ex1() throws NoSuchPaddingException, NoSuchAlgorithmException, ShortBufferException, IllegalBlockSizeException, BadPaddingException, InvalidAlgorithmParameterException, InvalidKeyException {
        // cipher block chaining (mod de criptare) cu padding

        byte[] keyBytes = new byte[16];
        // declare secure PRNG
        SecureRandom myPRNG = new SecureRandom();
        // seed the key
        myPRNG.nextBytes(keyBytes);
        // build the key from random key bytes
        SecretKeySpec myKey = new SecretKeySpec(keyBytes, "AES");
        // instantiate AES object for ECB with no padding
        Cipher myAES = Cipher.getInstance("AES/CBC/PKCS5Padding");
        // initialize AES objecy to encrypt mode
        myAES.init(Cipher.ENCRYPT_MODE, myKey, new IvParameterSpec(new byte[16]));
        // initialize plaintext
        byte[] plaintext = new byte[16];
        String plain = "aaaabbbbccccdddd";// 16B
        plaintext = plain.getBytes();
        //initialize ciphertext
        byte[] ciphertext = new byte[32];
        // update cipher with the plaintext
        int cLength = myAES.update(plaintext, 0, plaintext.length, ciphertext,
                0);
        // process remaining blocks of plaintext
        cLength += myAES.doFinal(ciphertext, cLength);
        // print plaintext and ciphertext
        System.out.println("plaintext: " +
                new BigInteger(1, plaintext).toString(16));
        System.out.println("ciphertext: " +
                new BigInteger(1, ciphertext).toString(16));

        // initialize AES for decryption
        myAES.init(Cipher.DECRYPT_MODE, myKey, new IvParameterSpec(new byte[16]));
        // initialize a new array of bytes to place the decryption
        byte[] dec_plaintext = new byte[16];
        cLength = myAES.update(ciphertext, 0, ciphertext.length, dec_plaintext,
                0);
        // process remaining blocks of ciphertext
        cLength += myAES.doFinal(dec_plaintext, cLength);
        // print the new plaintext (hopefully identical to the initial one)
        System.out.println("decrypted: " +
                new BigInteger(1, dec_plaintext).toString(16));
    }

    public static void ex2() throws NoSuchPaddingException, NoSuchAlgorithmException, IllegalBlockSizeException, BadPaddingException, InvalidKeyException, InvalidKeySpecException {

        SecureRandom myPRNG = new SecureRandom();
        byte[] plaintext = new byte[16];
        byte[] ciphertext = new byte[16];
        byte[] keyBytes = new byte[16];


        // get a Cipher instance for RSA with PKCS1 padding
        Cipher myRSA = Cipher.getInstance("RSA/ECB/PKCS1Padding");
        // get an instance for the Key Generator
        KeyPairGenerator myRSAKeyGen = KeyPairGenerator.getInstance("RSA");
        // generate an 1024 bit key
        myRSAKeyGen.initialize(1024, myPRNG);
        KeyPair myRSAKeyPair = myRSAKeyGen.generateKeyPair();
        // store the public and private key individually
        Key pbKey = myRSAKeyPair.getPublic();
        Key pvKey = myRSAKeyPair.getPrivate();
        // init cipher for encryption
        myRSA.init(Cipher.ENCRYPT_MODE, pbKey, myPRNG);
        // encrypt, as expected we encrypt a symmetric key with RSA rather than
//        a file or some longer stream which should be encrypted with AES
        ciphertext = myRSA.doFinal(keyBytes);
        // init cipher for decryption
        myRSA.init(Cipher.DECRYPT_MODE, pvKey);
        // decrypt
        plaintext = myRSA.doFinal(ciphertext);
        System.out.println("plaintext: " +
                new BigInteger(1, plaintext).toString(16));
        System.out.println("ciphertext: " +
                new BigInteger(1, ciphertext).toString(16));
        System.out.println("keybytes: " +
                new BigInteger(1, keyBytes).toString(16));



        char[] password = "short_password".toCharArray();
        byte[] salt = new byte[16];
//        salt = "aaaabbbbccccdddd".getBytes();
        int iteration_count = 10000;

        int key_size = 128;
        // set salt values to random
        myPRNG.nextBytes(salt);

        // initialize key factory for HMAC-SHA1 derivation
        SecretKeyFactory keyFactory =
                SecretKeyFactory.getInstance("PBKDF2WithHmacSHA1");
        // set key specification
        PBEKeySpec pbekSpec = new PBEKeySpec(password, salt, iteration_count,
                key_size);
        // generate the key
        SecretKey myAESPBKey = new SecretKeySpec(
                keyFactory.generateSecret(pbekSpec).getEncoded(), "AES");
        // print the key

        System.out.println();

        System.out.println("AES key: " +
                new BigInteger(1, myAESPBKey.getEncoded()).toString(16));
    }
}