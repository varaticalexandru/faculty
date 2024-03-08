package org.atm_example.worker;

import org.atm_example.model.Account;

public class AccountHolder implements Runnable {
    private final Account account;
    private int withdrawAmount;

    public AccountHolder(Account account, int withdrawAmount) {
        this.account = account;
        this.withdrawAmount = withdrawAmount;
    }


    @Override
    public void run() {
        for (int i=0; i<2; i++) {
            makeWithdrawal(withdrawAmount);
            if (account.getBalance() <= 0) {
                System.out.println("Account balance is overdrawn!");
            }
        }
    }

    private synchronized void makeWithdrawal(int amount) {
        if (account.getBalance() >= amount) {
            System.out.println(String.format("\"%s\" is going to withdraw \"%s\".", Thread.currentThread().getName(), amount));
            sleep(3);
            account.withdraw(amount);
            System.out.println(String.format("\"%s\" completed withdrawal of \"%s\".", Thread.currentThread().getName(), amount));

        } else {
            System.out.println(String.format("Account balance: \"%s\" not enough for \"%s\" to withdraw \"%s\".", account.getBalance(), Thread.currentThread().getName(), amount));
        }
    }

    private void sleep(long millis) {
        try {
            Thread.sleep(millis);
        }
        catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
