
interface D {
    int div(int a, int b);
}

interface C {
    int mul(int a, int b);
}

class B {
    int sub(int a, int b) {
        return a - b;
    }
}

public class A extends B implements C, D {

    int add(int a, int b) {
        return a + b;
    }

    public static void main(String[] args) {
        int a = 10, b = 5;

        A obj = new A();
        int add = obj.add(a, b);
        int sub = obj.sub(a, b);
        int mul = obj.mul(a, b);
        int div = obj.div(a, b);

        System.out.println("a+b = " + add);
        System.out.println("a-b = " + sub);
        System.out.println("a*b = " + mul);
        System.out.println("a/b = " + div);
    }

    @Override
    public int div(int a, int b) {
        return a / b;
    }

    @Override
    public int mul(int a, int b) {
        return a * b;
    }
}