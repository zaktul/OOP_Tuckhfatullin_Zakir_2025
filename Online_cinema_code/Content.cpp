#include "Content.h"
#include "Rating.h"
#include <fstream>
#include <sstream>
#include <iostream>

int Content::lastId = 0;
std::vector<Content> Content::allContents;

Content::Content(const std::string& name, int makerId, int categoryId)
    : id(++lastId), name(name), makerId(makerId), categoryId(categoryId), rating(0.0) {}

Content::Content(int id, const std::string& name, int makerId, int categoryId, double rating)
    : id(id), name(name), makerId(makerId), categoryId(categoryId), rating(rating) {}

void Content::loadAll() {
    std::ifstream file("data/content.txt");
    if (!file) {
        std::cout << "Warning: Could not open content.txt. Starting with empty content list.\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string idStr, name, makerIdStr, categoryIdStr, ratingStr;

        if (!std::getline(iss, idStr, '|') ||
            !std::getline(iss, name, '|') ||
            !std::getline(iss, makerIdStr, '|') ||
            !std::getline(iss, categoryIdStr, '|') ||
            !std::getline(iss, ratingStr, '|')) {
            std::cerr << "Error: Invalid content entry format: " << line << "\n";
            continue;
        }

        try {
            int id = std::stoi(idStr);
            int makerId = std::stoi(makerIdStr);
            int categoryId = std::stoi(categoryIdStr);
            double rating = std::stod(ratingStr);
            allContents.emplace_back(id, name, makerId, categoryId, rating);
            if (id > lastId) lastId = id;
            std::cout << "Loaded content: ID " << id << ", Name: " << name << ", Maker ID: " << makerId << "\n";
        }
        catch (...) {
            std::cerr << "Error: Invalid data in content entry: " << line << "\n";
        }
    }
    std::cout << "Total contents loaded: " << allContents.size() << ", Last ID: " << lastId << "\n";
}

void Content::saveAll() {
    std::ofstream file("data/content.txt");
    if (!file) {
        std::cerr << "Error: Could not save content data! Check file permissions.\n";
        return;
    }

    for (const auto& content : allContents) {
        file << content.id << "|"
            << content.name << "|"
            << content.makerId << "|"
            << content.categoryId << "|"
            << content.rating << "\n";
    }
    file.close();
    std::cout << "Saved " << allContents.size() << " contents to file.\n";
}

void Content::updateRating(int contentId) {
    auto it = std::find_if(allContents.begin(), allContents.end(),
        [contentId](const Content& c) { return c.getId() == contentId; });
    if (it != allContents.end()) {
        double total = 0.0;
        int count = 0;
        for (const auto& rating : Rating::allRatings) {
            if (rating.contentId == contentId) {
                total += rating.rating;
                count++;
            }
        }
        it->rating = count > 0 ? total / count : 0.0;
        saveAll();
        std::cout << "Updated rating for content ID " << contentId << " to " << it->rating << "\n";
    }
}