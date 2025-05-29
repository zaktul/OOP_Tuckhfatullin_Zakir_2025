#pragma once
#include <string>
#include <vector>
#include <memory>

class User {
protected:
    static int lastId;
    int id;
    std::string username;
    std::string password;
    std::string role;

public:
    User(const std::string& username, const std::string& password, const std::string& role);
    virtual ~User() = default;

    virtual void showMenu() = 0;

    static void loadUsers();
    static void saveUsers();
    static std::unique_ptr<User> login();
    static std::unique_ptr<User> registerUser();
    static void deleteUser(int userId);

    int getId() const { return id; }
    std::string getUsername() const { return username; }
    std::string getRole() const { return role; }
    bool checkPassword(const std::string& pass) const { return password == pass; }

protected:
    static std::vector<std::unique_ptr<User>> userList;
    static bool usernameExists(const std::string& username);
};