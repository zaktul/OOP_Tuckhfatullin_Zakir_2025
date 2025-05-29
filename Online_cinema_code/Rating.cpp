#include "Rating.h"
#include <fstream>
#include <sstream>
#include <iostream>

int Rating::lastId = 0;
std::vector<Rating> Rating::allRatings;

Rating::Rating(int userId, int contentId, int rating)
    : id(++lastId), userId(userId), contentId(contentId), rating(rating) {}

void Rating::addRating(int userId, int contentId, int rating) {
    allRatings.emplace_back(userId, contentId, rating);
    saveAll();
}

void Rating::deleteRating(int userId, int contentId) {
    allRatings.erase(std::remove_if(allRatings.begin(), allRatings.end(),
        [userId, contentId](const Rating& rating) {
            return rating.userId == userId && rating.contentId == contentId;
        }), allRatings.end());
    saveAll();
    std::cout << "Rating deleted successfully!\n";
}

void Rating::loadAll() {
    std::ifstream file("data/ratings.txt");
    if (!file) return;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string idStr, userIdStr, contentIdStr, ratingStr;

        if (!std::getline(iss, idStr, '|') ||
            !std::getline(iss, userIdStr, '|') ||
            !std::getline(iss, contentIdStr, '|') ||
            !std::getline(iss, ratingStr, '|')) {
            std::cerr << "Error: Invalid rating entry format: " << line << "\n";
            continue;
        }

        try {
            Rating rating(std::stoi(userIdStr), std::stoi(contentIdStr), std::stoi(ratingStr));
            rating.id = std::stoi(idStr);
            if (rating.id > lastId) lastId = rating.id;
            allRatings.push_back(rating);
        }
        catch (...) {
            std::cerr << "Error: Invalid rating data: " << line << "\n";
        }
    }
}

void Rating::saveAll() {
    std::ofstream file("data/ratings.txt");
    if (!file) {
        std::cerr << "Error: Could not save ratings data!\n";
        return;
    }
    for (const auto& rating : allRatings) {
        file << rating.id << "|" << rating.userId << "|"
            << rating.contentId << "|" << rating.rating << "\n";
    }
}

std::vector<Rating> Rating::getRatingsByContentId(int contentId) {
    std::vector<Rating> contentRatings;
    for (const auto& rating : allRatings) {
        if (rating.contentId == contentId) {
            contentRatings.push_back(rating);
        }
    }
    return contentRatings;
}