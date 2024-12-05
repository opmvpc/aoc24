#include <stdio.h>
#include <memory>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <filesystem>

#include "aoc.h"

std::string readFile(const std::string &filename)
{
    try
    {
        std::ifstream file(filename, std::ios::binary); // binary pour éviter les surprises avec les sauts de ligne

        if (!file.is_open())
        {
            throw std::filesystem::filesystem_error(
                "Impossible d'ouvrir le fichier",
                filename,
                std::make_error_code(std::errc::no_such_file_or_directory));
        }

        std::stringstream buffer;
        buffer << file.rdbuf();

        if (file.bad())
        {
            throw std::filesystem::filesystem_error(
                "Erreur pendant la lecture du fichier",
                filename,
                std::make_error_code(std::errc::io_error));
        }

        return buffer.str();
    }
    catch (const std::filesystem::filesystem_error &e)
    {
        // Ici tu peux soit relancer l'exception, soit la logger
        throw; // YEET ! (comme disent les jeunes)
    }
}

int main(int argc, char const *argv[])
{
    std::vector<std::unique_ptr<Solver>> solvers;

    solvers.push_back(std::make_unique<Day1>());
    for (size_t i = 0; i < solvers.size(); i++)
    {
        auto &solver = solvers[i];
        std::stringstream filename;
        filename << "inputs/" << i + 1 << "a.txt";
        solver->parse(readFile(std::filesystem::path(filename.str())));
        std::cout << "\tDay " << i + 1 << " :" << std::endl;
        std::cout << "\t - " << solver->part1() << std::endl;
        std::cout << "\t - " << solver->part2();
    }

    std::cout << std::endl;

    return 0;
}
