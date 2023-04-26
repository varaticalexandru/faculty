package creational.builder.phone;

public class MainBuilder {
    public static void main(String[] args) {

        Phone phone = new PhoneBuilder()
                .setCPU("Qualcomm")
                .setBattery(3000)
                .setOS("Android")
                .getPhone();

        System.out.println(phone);
    }
}
