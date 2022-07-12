/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-alexis.picard
** File description:
** this is an epitech project
*/

#pragma once
#include <string>
#include <vector>

class Utils {
private:

public:

    Utils() = default;
    ~Utils() = default;

    static std::vector<std::string> readDirectory(std::string const &dirPath);

    static std::vector<std::string> readFile(std::string const &filepath);

    static std::vector<std::string> split(std::string const &str, std::string const &regex);

};