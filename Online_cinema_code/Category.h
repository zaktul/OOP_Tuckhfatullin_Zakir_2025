#pragma once
#include <string>
#include <vector>

class Category {
private:
    static int lastId;
    int id;
    std::string name;

public:
    Category(const std::string& name);

    static void loadAll();
    static void saveAll();
    static void deleteCategory(int categoryId);
    void createCategory();
    static std::string getCategoryById(int id);

    int getId() const { return id; }
    std::string getName() const { return name; }

    static std::vector<Category> allCategories;
};