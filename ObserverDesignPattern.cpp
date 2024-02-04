#include <iostream>
#include <string>
#include <list>

class Subscriber {
    std::string name;
    std::size_t id;

    public:
    Subscriber(std::string name, std::size_t id): name(name), id(id) {}

    void notify(std::string msg) {
        std::cout << "Hi, " << this->name << std::endl;
        std::cout << "User Id : " << this->id << std::endl;
        std::cout << msg << std::endl;
        std::cout << std::endl;
    }
};

class Channel {
    std::string name;
    std::list<Subscriber*> subscribers;

    public:
    Channel(std::string name): name(name) {}

    void Subscribe(Subscriber *user) {
        subscribers.push_back(user);
    }

    void unSubscribe(Subscriber *user) {
        subscribers.remove(user);
    }

    void sendMessage(std::string msg) {
        for(auto user: subscribers) {
            user->notify(msg);
        }
    }
};

int main() {
    Channel channel("Youtube");
    
    Subscriber *sub1 = new Subscriber("Subodh", 101);
    Subscriber *sub2 = new Subscriber("Rahul", 102);
    Subscriber *sub3 = new Subscriber("Sagar", 103);

    // subscriber to channel
    channel.Subscribe(sub1);
    channel.Subscribe(sub2);
    channel.Subscribe(sub3);
    // get notification of all subscriber 
    channel.sendMessage("Welcome to the Design Pattern workshop");

    // unsubscriber by sagar
    channel.unSubscribe(sub3);

    // after unsubscibe the channel 
    // show users by getting the notification
    std::cout << std::endl;
    std::cout << "After unsubscribe =======> " << std::endl;
    channel.sendMessage("We are learning Obserber Design pattern");

    return EXIT_SUCCESS;
}

