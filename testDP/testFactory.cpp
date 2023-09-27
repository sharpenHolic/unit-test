//
// Created by gqxiong on 2023/9/27.
//
#include <gtest/gtest.h>
#include <utility>

template <typename T, typename... Args>
T Create(Args&&... args)
{
    return T{std::forward<Args>(args)...};
}

class Logger {
   public:
    Logger() = default;
    void log(const std::string& message) { std::cout << "Logging: " << message << std::endl; }
};

class Database {
   public:
    void save(const std::string& data) { std::cout << "Saving to database: " << data << std::endl; }
};

class Interface {
   private:
    Logger _ll;
    Database _dd;

   public:
    Interface() = default;
    Interface(Logger ll, Database dd) : _ll(std::move(ll)), _dd(std::move(dd)) {}

   public:
    void registerUser(const std::string& username)
    {
        _ll.log("Registering user: " + username);
        std::string userData = "User: " + username;
        _dd.save(userData);
        std::cout << "User registration completed." << std::endl;
    }
};

TEST(DesignPatern, Factory)
{
    Logger logger;
    Database db;

    Interface interface = Create<Interface>(logger, db);
    interface.registerUser("hello");
}
