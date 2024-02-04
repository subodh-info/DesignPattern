#include <iostream>
#include <string>

class PackageInfo {
    std::string size, weight;

    public:
    PackageInfo(std::string size, std::string weight): size(size), weight(weight) {}

    std::string getSize() {
        return this->size;
    }

    std::string getWeight() {
        return this->weight;
    }
};

class ITransport {
    public:
    virtual std::string deliveryWay(PackageInfo *packageInfo) = 0;
};

class Bycycle: public ITransport {
    public:
    std::string deliveryWay(PackageInfo *packageInfo) override {
        return "Package delivery through Bycycle for size " + packageInfo->getSize() + " and weight " + packageInfo->getWeight();
    }
};

class Car: public ITransport {
    public:
    std::string deliveryWay(PackageInfo *packageInfo) override {
        return "Package delivery through Car for size " + packageInfo->getSize() + " and weight " + packageInfo->getWeight();
    }
};

class Track: public ITransport {
    public:
    std::string deliveryWay(PackageInfo *packageInfo) override {
        return "Package delivery through Track for size" + packageInfo->getSize() + " and weight " + packageInfo->getWeight();
    }
};

class TransportManager {
    Bycycle *bycycle;
    Car *car;
    Track *track;

    public:
    std::string deliveryManagerFactory(PackageInfo *package) {
        if(package->getSize() == "small") {
            return (new Bycycle())->deliveryWay(package);
        }

        if(package->getSize() == "medium") {
            return (new Car())->deliveryWay(package);
        }

        if(package->getSize() == "large") {
            return (new Track())->deliveryWay(package);
        }
    }

    ~TransportManager() {
        delete bycycle;
        delete car;
        delete track;
    }
};

int main() {
    PackageInfo *package = new PackageInfo("small", "500gm");
    TransportManager *manager = new TransportManager();
    std::cout << manager->deliveryManagerFactory(package) << std::endl;
    return EXIT_SUCCESS;
}