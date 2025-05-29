#include "RegularUser.h"
#include "Content.h"
#include "History.h"
#include "Library.h"
#include "Rating.h"
#include "Category.h"
#include "Comment.h"
#include <iostream>
#include <limits>

RegularUser::RegularUser(const std::string& username, const std::string& password)
    : User(username, password, "user") {}

void RegularUser::showMenu() {
    while (true) {
        std::cout << "\n=== USER MENU ===\n"
            << "1. View Content\n"
            << "2. Watch Content\n"
            << "3. Add to Library\n"
            << "4. Remove from Library\n"
            << "5. View History\n"
            << "6. Delete History Entry\n"
            << "7. View Library\n"
            << "8. Rate Content\n"
            << "9. Add Comment\n"
            << "10. Delete Comment\n"
            << "11. View Comments\n"
            << "12. Logout\n"
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
        case 1: viewContent(); break;
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
            watchContent(id);
            break;
        }
        case 3: {
            int id;
            std::cout << "Enter Content ID: ";
            if (!(std::cin >> id)) {
                std::cout << "Invalid ID!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            addToLibrary(id);
            break;
        }
        case 4: {
            int id;
            std::cout << "Enter Content ID: ";
            if (!(std::cin >> id)) {
                std::cout << "Invalid ID!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            removeFromLibrary(id);
            break;
        }
        case 5: viewHistory(); break;
        case 6: {
            int id;
            std::cout << "Enter Content ID: ";
            if (!(std::cin >> id)) {
                std::cout << "Invalid ID!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            deleteHistory(id);
            break;
        }
        case 7: viewLibrary(); break;
        case 8: {
            int id, rating;
            std::cout << "Enter Content ID: ";
            if (!(std::cin >> id)) {
                std::cout << "Invalid ID!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cout << "Enter Rating (1-10): ";
            if (!(std::cin >> rating)) {
                std::cout << "Invalid rating!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            rateContent(id, rating);
            break;
        }
        case 9: {
            int id;
            std::string text;
            std::cout << "Enter Content ID: ";
            if (!(std::cin >> id)) {
                std::cout << "Invalid ID!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter your comment: ";
            std::getline(std::cin, text);
            addComment(id, text);
            break;
        }
        case 10: {
            int id;
            std::cout << "Enter Comment ID to delete: ";
            if (!(std::cin >> id)) {
                std::cout << "Invalid ID!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            deleteComment(id);
            break;
        }
        case 11: {
            int id;
            std::cout << "Enter Content ID to view comments: ";
            if (!(std::cin >> id)) {
                std::cout << "Invalid ID!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            viewComments(id);
            break;
        }
        case 12: return;
        default: std::cout << "Invalid choice!\n";
        }
    }
}

void RegularUser::viewContent() {
    std::cout << "\n=== AVAILABLE CONTENT ===\n";
    if (Content::allContents.empty()) {
        std::cout << "No content available.\n";
        return;
    }
    for (const auto& content : Content::allContents) {
        std::string categoryName = Category::getCategoryById(content.getCategoryId());
        std::cout << "ID: " << content.getId()
            << " | Name: " << content.getName()
            << " | Category: " << categoryName
            << " | Rating: " << content.getRating() << "/10\n";
    }
}

void RegularUser::watchContent(int contentId) {
    for (const auto& content : Content::allContents) {
        if (content.getId() == contentId) {
            History::addToHistory(this->getId(), contentId, content.getName());
            std::cout << "Watching: " << content.getName() << "\n";
            return;
        }
    }
    std::cout << "Content not found!\n";
}

void RegularUser::addToLibrary(int contentId) {
    for (const auto& content : Content::allContents) {
        if (content.getId() == contentId) {
            for (const auto& lib : Library::allLibrary) {
                if (lib.getContentId() == contentId && lib.userId == this->getId()) {
                    std::cout << "Content already in library!\n";
                    return;
                }
            }
            Library::addToLibrary(this->getId(), contentId, content.getName());
            std::cout << "Added to library: " << content.getName() << "\n";
            return;
        }
    }
    std::cout << "Content not found!\n";
}

void RegularUser::removeFromLibrary(int contentId) {
    for (const auto& content : Content::allContents) {
        if (content.getId() == contentId) {
            Library::removeFromLibrary(this->getId(), contentId);
            std::cout << "Removed from library: " << content.getName() << "\n";
            return;
        }
    }
    std::cout << "Content not found!\n";
}

void RegularUser::viewHistory() {
    std::cout << "\n=== VIEWING HISTORY ===\n";
    auto userHistory = History::getHistoryByUserId(this->getId());
    if (userHistory.empty()) {
        std::cout << "No history found.\n";
        return;
    }
    for (const auto& entry : userHistory) {
        std::cout << "Content ID: " << entry.getContentId()
            << " | Name: " << entry.getContentName() << "\n";
    }
}

void RegularUser::deleteHistory(int contentId) {
    History::deleteHistory(this->getId(), contentId);
}

void RegularUser::viewLibrary() {
    std::cout << "\n=== MY LIBRARY ===\n";
    auto userLibrary = Library::getLibraryByUserId(this->getId());
    if (userLibrary.empty()) {
        std::cout << "No content in library. Total library entries: " << Library::allLibrary.size() << "\n";
        return;
    }
    for (const auto& entry : userLibrary) {
        std::string categoryName = Category::getCategoryById(
            [entry]() {
                for (const auto& content : Content::allContents) {
                    if (content.getId() == entry.getContentId()) {
                        return content.getCategoryId();
                    }
                }
                return 0;
            }()
                );
        std::cout << "Content ID: " << entry.getContentId()
            << " | Name: " << entry.getContentName()
            << " | Category: " << categoryName << "\n";
    }
}

void RegularUser::rateContent(int contentId, int rating) {
    if (rating < 1 || rating > 10) {
        std::cout << "Rating must be between 1 and 10!\n";
        return;
    }
    for (auto& content : Content::allContents) {
        if (content.getId() == contentId) {
            Rating::addRating(this->getId(), contentId, rating);
            Content::updateRating(contentId);
            std::cout << "Rated: " << content.getName() << " with " << rating << "/10\n";
            return;
        }
    }
    std::cout << "Content not found!\n";
}

void RegularUser::addComment(int contentId, const std::string& text) {
    bool contentExists = false;
    for (const auto& content : Content::allContents) {
        if (content.getId() == contentId) {
            contentExists = true;
            break;
        }
    }
    if (!contentExists) {
        std::cout << "Content not found!\n";
        return;
    }
    Comment::addComment(this->getId(), contentId, text, this->getUsername());
    std::cout << "Comment added successfully!\n";
}

void RegularUser::deleteComment(int commentId) {
    Comment::deleteComment(this->getId(), commentId);
    std::cout << "Comment deleted successfully!\n";
}

void RegularUser::viewComments(int contentId) {
    std::cout << "\n=== COMMENTS FOR CONTENT ID " << contentId << " ===\n";
    auto comments = Comment::getCommentsByContentId(contentId);
    if (comments.empty()) {
        std::cout << "No comments found for this content.\n";
        return;
    }
    for (const auto& comment : comments) {
        std::cout << "Comment ID: " << comment.getId()
            << " | User: " << comment.getUsername()
            << " | Text: " << comment.getText() << "\n";
    }
}