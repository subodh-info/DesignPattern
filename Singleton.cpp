#include <iostream>
using namespace std;

class Singleton
{
    private:
    Singleton(){}

    public:
    static Singleton* object;

    static Singleton* getSingleton()
    {
        if(object == nullptr)
        {
            object = new Singleton();
        }
        return object;
    }
};

Singleton* Singleton::object = nullptr;

int main()
{
    // create object 1st time
    Singleton* object = Singleton::getSingleton();

    // create 2nd object
    Singleton* object2 = Singleton::getSingleton();

    if(object == object2)
        std::cout << "Both are same object" << std::endl;
    else
        std::cout << "Both are not same object" << std::endl;
}