#ifndef MOVIES_H
#define MOVIES_H

#include <string>
#include <map>
#include <vector>


struct Movie {
    std::string name;
    double rating;

    bool operator<(const Movie& other) const {
        if (rating != other.rating) {
            return rating > other.rating; 
        }
        return name < other.name; 
    }
};


class MovieDatabase {
private:
   
    std::map<std::string, double> movieMap;

public:
    
    MovieDatabase() = default;

    
    void addMovie(const std::string& name, double rating);

    
    void printAllAlphabetically() const;

    
    void processPrefix(const std::string& prefix, std::vector<std::string>& bestMoviesResults) const;
};

#endif
