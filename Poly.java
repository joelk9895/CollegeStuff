public class Poly {
    public static void main(String[] args) {
        Shapes square = new Square();
        square.noOfSides();

        Shapes triangle = new Triangle();
        triangle.noOfSides();

        Shapes rectangle = new Rectangle();
        rectangle.noOfSides();
    }
}

abstract class Shapes {
    abstract void noOfSides();
}

class Square extends Shapes {
    void noOfSides() {
        System.out.println("Four sides");
    }
}

class Triangle extends Shapes {
    void noOfSides() {
        System.out.println("Three sides");
    }
}

class Rectangle extends Shapes {
    void noOfSides() {
        System.out.println("Four sides");
    }
}