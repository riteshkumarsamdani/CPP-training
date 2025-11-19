#include <iostream>
#include <map>

class User
{
    private:
        std::string name_;
        std::string id_;
    public:
        User(std::string name, std::string id) : name_(name), id_(id) {}
        std::string getName()
        {
            return name_;
        }

        std::string getId()
        {
            return id_;
        }
};

int main()
{
    std::map<std::string, User> users;
    users.insert({"alice", User("alice", "1")});
    std::cout << users.at("alice").getId();
    //std::cout << users["alice"].getId();
    User user("Belle","2");
    users.insert({"Belle", user});
    std::cout << users.at("Belle").getId();
    return 0;
}