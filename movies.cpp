#include "movies.h"
#include <iostream>
#include <algorithm>

void MovieDatabase::addMovie(const std::string& name, double rating) {
    movieMap[name] = rating;
}

void MovieDatabase::printAllAlphabetically() const {
    for (auto it = movieMap.begin(); it != movieMap.end(); ++it) {
        std::cout << it->first << ", " << it->second << "\n";
    }
}

void MovieDatabase::processPrefix(const std::string& prefix, 
                                  std::vector<std::string>& bestMoviesResults) const {
    auto it = movieMap.lower_bound(prefix);
    std::vector<Movie> matchedMovies;

    while (it != movieMap.end()) {
        std::string movieName = it->first;
        
        if (movieName.length() < prefix.length() || movieName.substr(0, prefix.length()) != prefix) {
            break;
        }

        Movie m;
        m.name = movieName;
        m.rating = it->second;
        matchedMovies.push_back(m);
        
        it++;
    }

    if (matchedMovies.empty()) {
        std::cout << "No movies found with prefix " << prefix << "\n";
        bestMoviesResults.push_back("");
    } else {
        std::sort(matchedMovies.begin(), matchedMovies.end());

        for (size_t i = 0; i < matchedMovies.size(); ++i) {
            std::cout << matchedMovies[i].name << ", " << matchedMovies[i].rating << "\n";
        }
        std::cout << "\n"; 

        bestMoviesResults.push_back(matchedMovies[0].name + " with rating " + std::to_string(matchedMovies[0].rating).substr(0, 3));
    }
}
