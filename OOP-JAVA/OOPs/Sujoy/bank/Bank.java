package bank;

class Account {
    public String name;
    protected String email;
    private String password;

    // getters & setters
    public String getPassword(){
        setPassword("1234"); // random password by own
        return this.password;
    }
    private void setPassword(String pass){
        this.password = pass;
    }
}

public class Bank{
    public static void main(String[] args) {
        Account account1 = new Account();
        account1.name = "makaut";
        account1.email = "makaut.ac.in";
        System.out.println(account1.getPassword());
    }
}