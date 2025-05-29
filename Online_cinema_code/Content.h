#pragma once
#include <string>
#include <vector>

class Content {
private:
    static int lastId;
    int id;
    std::string name;
    int makerId;
    int categoryId;
    double rating;

public:
    Content(const std::string& name, int makerId, int categoryId);
    Content(int id, const std::string& name, int makerId, int categoryId, double rating); // Для загрузки

    int getId() const { return id; }
    std::string getName() const { return name; }
    int getMakerId() const { return makerId; }
    int getCategoryId() const { return categoryId; }
    double getRating() const { return rating; }

    static void updateRating(int contentId);
    static void loadAll();
    static void saveAll();

    static std::vector<Content> allContents;
};