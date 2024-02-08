#include <iostream>
#include <cmath>
#include <vector>

#define M_PI 3.14
class Circle;
class Square;
class Rectangle;

class ShapeVisitor {
    public:
    virtual void visit(Circle *circle) = 0;
    virtual void visit(Square *square) = 0;
    virtual void visit(Rectangle *rectangle) = 0;
};

class Shape {
    public:
    virtual void accept(ShapeVisitor *visitor) = 0;
};

class Circle: public Shape {
    double radius;
    public:
    Circle(const double radius): radius(radius) {}

    double getRadius() {
        return this->radius;
    }

    void accept(ShapeVisitor *visitor) override {
        visitor->visit(this);
    }
};

class Square: public Shape {
    double length;
    
    public:
    Square(const double length): length(length) {}

    double getLength() {
        return this->length;
    }

    void accept(ShapeVisitor *visitor) override {
        visitor->visit(this);
    }
};


class Rectangle: public Shape {
    double length, width;

    public:
    Rectangle(double length, double width): length(length), width(width) {}

    double getLength() {
        return this->length;
    }

    double getWidth() {
        return this->width;
    }

    void accept(ShapeVisitor *visitor) override {
        visitor->visit(this);
    }
};

class AreaVisitor: public ShapeVisitor {
    double area;

    public:
    void visit(Circle *circle) override {
        area = M_PI * pow(circle->getRadius(), 2);
    }

    void visit(Square *square) override {
        area = pow(square->getLength(), 2);
    }

    void visit(Rectangle *rectangle) {
        area = rectangle->getLength() * rectangle->getWidth();
    }

    double get() {
        return area;
    }
};

// if we need to add more functionality
// like calculating parameter for all shapes
// then we can create another class
// the main aim of this is
// to follow open-close principle
class PerimeterVisitor: public ShapeVisitor {
    double perimeter;

    public:
    void visit(Circle *circle) override {
        perimeter = 2 * M_PI * circle->getRadius();
    }

    void visit(Square *square) override {
        perimeter = 4 * square->getLength();
    }

    void visit(Rectangle *rectangle) override {
        perimeter = 2 * (rectangle->getLength() + rectangle->getWidth());
    }

    double get() {
        return perimeter;
    }
};

int main() {
    // list of shapes
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(10));
    shapes.push_back(new Square(10));
    shapes.push_back(new Square(5));
    shapes.push_back(new Rectangle(10, 2));

    // area of each shapes
    AreaVisitor *areavisitor = new AreaVisitor();
    std::cout << "Area of each shape stored in the vector => " << std::endl;
    for(auto _shape : shapes) {
        _shape->accept(areavisitor);
        double area = areavisitor->get();
        std::cout << "Area : " << area << std::endl;
    }

    PerimeterVisitor *perimeterVisitor = new PerimeterVisitor();
    std::cout << "\nPerimeter of each shape stored in the vector => " << std::endl;
    for(auto _shape : shapes) {
        _shape->accept(perimeterVisitor);
        double area = perimeterVisitor->get();
        std::cout << "Perimeter : " << area << std::endl;
    }
    return EXIT_SUCCESS;
}
