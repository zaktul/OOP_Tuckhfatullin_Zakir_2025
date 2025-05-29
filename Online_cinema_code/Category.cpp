#include "Category.h"
#include "Content.h"
#include <fstream>
#include <sstream>
#include <iostream>

int Category::lastId = 0;
std::vector<Category> Category::allCategories;

Category::Category(const std::string& name) : id(++lastId), name(name) {}

void Category::loadAll() {
    std::ifstream file("data/categories.txt");
    if (!file) return;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string idStr, name;

        if (!std::getline(iss, idStr, '|') || !std::getline(iss, name, '|')) {
            std::cerr << "Error: Invalid category entry format: " << line << "\n";
            continue;
        }

        try {
            Category category(name);
            category.id = std::stoi(idStr);
            if (category.id > lastId) lastId = category.id;
            allCategories.push_back(category);
        }
        catch (...) {
            std::cerr << "Error: Invalid category data: " << line << "\n";
        }
    }
}

void Category::saveAll() {
    std::ofstream file("data/categories.txt");
    if (!file) {
        std::cerr << "Error: Could not save categories data!\n";
        return;
    }
    for (const auto& category : allCategories) {
        file << category.id << "|" << category.name << "\n";
    }
}

void Category::deleteCategory(int categoryId) {
    for (const auto& content : Content::allContents) {
        if (content.getCategoryId() == categoryId) {
            std::cout << "Cannot delete category: used by content!\n";
            return;
        }
    }
    auto it = std::find_if(allCategories.begin(), allCategories.end(),
        [categoryId](const Category& cat) { return cat.id == categoryId; });
    if (it != allCategories.end()) {
        allCategories.erase(it);
        saveAll();
        std::cout << "Category deleted successfully!\n";
    }
    else {
        std::cout << "Category not found!\n";
    }
}

void Category::createCategory() {
    std::string name;
    std::cout << "Enter category name: ";
    std::getline(std::cin, name);

    Category newCategory(name);
    allCategories.push_back(newCategory);
    saveAll();
    std::cout << "Category created!\n";
}

std::string Category::getCategoryById(int id) {
    for (const auto& category : allCategories) {
        if (category.id == id) return category.name;
    }
    return "Unknown";
}