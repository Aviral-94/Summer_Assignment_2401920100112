class Outer {

    void display() {
        System.out.println("Display of Outer Class");
    }

    class Inner {
        void display() {
            System.out.println("Display of Inner Class");
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Outer obj = new Outer();
        obj.display();

        Outer.Inner in = obj.new Inner();
        in.display();
    }
}