#pragma once
#include <vector>

class Rating {
public:
    static int lastId;
    int id;
    int userId;
    int contentId;
    int rating; // 1-10
    Rating(int userId, int contentId, int rating);

    static void addRating(int userId, int contentId, int rating);
    static void deleteRating(int userId, int contentId);
    static void loadAll();
    static void saveAll();
    static std::vector<Rating> getRatingsByContentId(int contentId);

    int getRating() const { return rating; }

    static std::vector<Rating> allRatings;
};