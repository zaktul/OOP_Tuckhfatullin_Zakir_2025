#include "ContentMaker.h"
#include "Content.h"
#include "Category.h"
#include "Rating.h"
#include "Comment.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>

ContentMaker::ContentMaker(const std::string& username, const std::string& password)
    : User(username, password, "contentmaker") {}

void ContentMaker::showMenu() {
    while (true) {
        std::cout << "\n=== CONTENT MAKER MENU ===\n"
            << "1. Add Content\n"
            << "2. Delete Content\n"
            << "3. View My Contents\n"
            << "4. Manage Categories\n"
            << "5. View Comments for My Content\n"
            << "6. Logout\n"
            << "Choice: ";

        int choice;
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input! Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1: addContent(); break;
        case 2: {
            int id;
            std::cout << "Enter Content ID: ";
            if (!(std::cin >> id)) {
                std::cout << "Invalid ID!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            deleteContent(id);
            break;
        }
        case 3: viewMyContents(); break;
        case 4: manageCategories(); break;
        case 5: viewCommentsForMyContent(); break;
        case 6: return;
        default: std::cout << "Invalid choice!\n";
        }
    }
}

void ContentMaker::addContent() {
    std::string name;
    int categoryId;

    std::cout << "Enter content name: ";
    std::getline(std::cin, name);

    std::cout << "Available categories:\n";
    if (Category::allCategories.empty()) {
        std::cout << "No categories available. Create one first.\n";
        return;
    }
    for (const auto& category : Category::allCategories) {
        std::cout << "ID: " << category.getId() << " | Name: " << category.getName() << "\n";
    }
    std::cout << "Enter category ID: ";
    if (!(std::cin >> categoryId)) {
        std::cout << "Invalid category ID!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    bool categoryExists = false;
    for (const auto& category : Category::allCategories) {
        if (category.getId() == categoryId) {
            categoryExists = true;
            break;
        }
    }
    if (!categoryExists) {
        std::cout << "Category not found!\n";
        return;
    }

    Content newContent(name, this->getId(), categoryId);
    Content::allContents.push_back(newContent);
    Content::saveAll();
    std::cout << "Content added successfully! ID: " << newContent.getId() << "\n";
}

void ContentMaker::deleteContent(int contentId) {
    auto it = std::find_if(Content::allContents.begin(), Content::allContents.end(),
        [this, contentId](const Content& content) {
            return content.getId() == contentId && content.getMakerId() == this->getId();
        });
    if (it != Content::allContents.end()) {
        // Удаление всех рейтингов для этого контента
        Rating::allRatings.erase(
            std::remove_if(Rating::allRatings.begin(), Rating::allRatings.end(),
                [contentId](const Rating& rating) { return rating.contentId == contentId; }),
            Rating::allRatings.end());
        Rating::saveAll();

        // Удаление всех комментариев для этого контента
        Comment::allComments.erase(
            std::remove_if(Comment::allComments.begin(), Comment::allComments.end(),
                [contentId](const Comment& comment) { return comment.getContentId() == contentId; }),
            Comment::allComments.end());
        Comment::saveAll();

        Content::allContents.erase(it);
        Content::saveAll();
        std::cout << "Content deleted successfully!\n";
    }
    else {
        std::cout << "Content not found or you don't have permission!\n";
    }
}

void ContentMaker::viewMyContents() {
    std::cout << "\n=== MY CONTENTS ===\n";
    std::cout << "Current Maker ID: " << this->getId() << "\n";
    bool found = false;
    for (const auto& content : Content::allContents) {
        std::cout << "Checking content ID " << content.getId() << " with Maker ID " << content.getMakerId() << "\n";
        if (content.getMakerId() == this->getId()) {
            std::string categoryName = Category::getCategoryById(content.getCategoryId());
            std::cout << "ID: " << content.getId()
                << " | Name: " << content.getName()
                << " | Category: " << categoryName
                << " | Rating: " << content.getRating() << "/10\n";
            found = true;
        }
    }
    if (!found) std::cout << "No content found. Total contents in system: " << Content::allContents.size() << "\n";
}

void ContentMaker::manageCategories() {
    while (true) {
        std::cout << "\n=== MANAGE CATEGORIES ===\n"
            << "1. Add Category\n"
            << "2. Delete Category\n"
            << "3. View Categories\n"
            << "4. Back\n"
            << "Choice: ";

        int choice;
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input! Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            Category category("");
            category.createCategory();
            break;
        }
        case 2: {
            int categoryId;
            std::cout << "Enter Category ID to delete: ";
            if (!(std::cin >> categoryId)) {
                std::cout << "Invalid ID!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Category::deleteCategory(categoryId);
            break;
        }
        case 3: {
            std::cout << "\n=== CATEGORIES ===\n";
            if (Category::allCategories.empty()) {
                std::cout << "No categories found.\n";
            }
            else {
                for (const auto& category : Category::allCategories) {
                    std::cout << "ID: " << category.getId() << " | Name: " << category.getName() << "\n";
                }
            }
            break;
        }
        case 4: return;
        default: std::cout << "Invalid choice!\n";
        }
    }
}

void ContentMaker::viewCommentsForMyContent() {
    std::cout << "\n=== COMMENTS FOR MY CONTENT ===\n";
    bool foundContent = false;
    for (const auto& content : Content::allContents) {
        if (content.getMakerId() == this->getId()) {
            foundContent = true;
            std::cout << "\nContent ID: " << content.getId() << " | Name: " << content.getName() << "\n";
            auto comments = Comment::getCommentsByContentId(content.getId());
            if (comments.empty()) {
                std::cout << "No comments for this content.\n";
            }
            else {
                for (const auto& comment : comments) {
                    std::cout << "  Comment ID: " << comment.getId()
                        << " | User: " << comment.getUsername()
                        << " | Text: " << comment.getText() << "\n";
                }
            }
        }
    }
    if (!foundContent) {
        std::cout << "No content found for this maker.\n";
    }
}