#include <iostream>

class Shape
{
    public:
    virtual void draw() = 0;
};

class Rectangle: public Shape
{
    public:
    void draw() override
    {
        std::cout << "draw() from rectangle class" << std::endl;
    }
};

class Square: public Shape
{
    public:
    void draw() override
    {
        std::cout << "draw() from sqaure class" << std::endl;
    }
};

class Circle: public Shape
{
    public:
    void draw() override
    {
        std::cout << "draw() from circle class" << std::endl;
    }
};

class ShapeFactory
{
    Shape *shape = nullptr;
    public:
    Shape* getShape(std::string shapType)
    {
        if(shapType == "circle")
            shape = new Circle();
        else if(shapType == "square")
            shape = new Square();
        else if(shapType == "rectangle")
            shape = new Rectangle();
        else 
            shape = nullptr;
        return shape;
    }
    ~ShapeFactory()
    {
        delete shape;
    }
};

int main()
{
    Shape *shape = nullptr;
    ShapeFactory* factory = new ShapeFactory();
    shape = factory->getShape("circle");
    shape->draw();

    shape = factory->getShape("square");
    shape->draw();

    return EXIT_SUCCESS;
}