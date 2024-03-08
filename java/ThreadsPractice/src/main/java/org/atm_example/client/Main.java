package org.atm_example.client;

import org.atm_example.model.Account;
import org.atm_example.worker.AccountHolder;

public class Main {
    public static void main(String[] args) {
        Account account = new Account(6000);
        AccountHolder accountHolder = new AccountHolder(account, 2000);

        Thread t1 = new Thread(accountHolder);
        Thread t2 = new Thread(accountHolder);
        t1.setName("Alex");
        t2.setName("John");

        t1.start();
        t2.start();
    }
}
