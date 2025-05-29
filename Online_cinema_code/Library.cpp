#include "Library.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>

int Library::lastId = 0;
std::vector<Library> Library::allLibrary;

Library::Library(int userId, int contentId, const std::string& contentName)
    : id(++lastId), userId(userId), contentId(contentId), contentName(contentName) {}

void Library::addToLibrary(int userId, int contentId, const std::string& contentName) {
    allLibrary.emplace_back(userId, contentId, contentName);
    saveAll();
}

void Library::removeFromLibrary(int userId, int contentId) {
    allLibrary.erase(std::remove_if(allLibrary.begin(), allLibrary.end(),
        [userId, contentId](const Library& lib) {
            return lib.userId == userId && lib.contentId == contentId;
        }), allLibrary.end());
    saveAll();
}

void Library::loadAll() {
    std::ifstream file("data/library.txt");
    if (!file) {
        std::cout << "Warning: Could not open library.txt. Starting with empty library.\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string idStr, userIdStr, contentIdStr, contentName;

        if (!std::getline(iss, idStr, '|') ||
            !std::getline(iss, userIdStr, '|') ||
            !std::getline(iss, contentIdStr, '|') ||
            !std::getline(iss, contentName, '|')) {
            std::cerr << "Error: Invalid library entry format: " << line << "\n";
            continue;
        }

        try {
            Library library(std::stoi(userIdStr), std::stoi(contentIdStr), contentName);
            library.id = std::stoi(idStr);
            if (library.id > lastId) lastId = library.id;
            allLibrary.push_back(library);
            std::cout << "Loaded library entry: ID " << library.id << ", User ID: " << library.userId << ", Content ID: " << library.contentId << "\n";
        }
        catch (...) {
            std::cerr << "Error: Invalid library data: " << line << "\n";
        }
    }
    std::cout << "Total library entries loaded: " << allLibrary.size() << ", Last ID: " << lastId << "\n";
}

void Library::saveAll() {
    std::ofstream file("data/library.txt");
    if (!file) {
        std::cerr << "Error: Could not save library data!\n";
        return;
    }

    for (const auto& lib : allLibrary) {
        file << lib.id << "|" << lib.userId << "|"
            << lib.contentId << "|" << lib.contentName << "\n";
    }
    std::cout << "Saved " << allLibrary.size() << " library entries to file.\n";
}

std::vector<Library> Library::getLibraryByUserId(int userId) {
    std::vector<Library> userLibrary;
    for (const auto& entry : allLibrary) {
        if (entry.userId == userId) {
            userLibrary.push_back(entry);
        }
    }
    return userLibrary;
}