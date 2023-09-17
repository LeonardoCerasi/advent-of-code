#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<char> str_to_vec(std::string line)
{
    std::vector<char> letters;

    for (char c : line)
    {
        letters.push_back(c);
    }

    return letters;
}

std::vector<std::vector<char>> file_to_vec(const char *path)
{
    std::vector<std::vector<char>> file;

    std::ifstream input;
    input.open(path);

    if (!input)
    {
        std::cout << "Error during input file opening" << std::endl;
        return {};
    }
    
    std::string line;

    getline(input, line);
    while (!input.eof())
    {
        file.push_back(str_to_vec(line));
        getline(input, line);
    }

    return file;
}

bool is_nice(std::vector<char> word)
{
    bool flag_1 = false;
    bool flag_2 = false;

    for (int i = 0; (i < word.size() - 2) && (flag_1 == false); i++)
    {
        if (word[i] == word[i+2]) {flag_1 = true;}
    }

    for (int i = 0; (i < word.size() - 3) && (flag_2 == false); i++)
    {
        for (int j = i+2; (j < word.size() - 1) && (flag_2 == false); j++)
        {
            if ((word[i] == word[j]) && (word[i+1] == word[j+1])) {flag_2 = true;}
        }
    }

    return (flag_1 && flag_2);
}

int main()
{
    std::vector<std::vector<char>> input = file_to_vec("input.txt");

    int counter = 0;
    for (std::vector<char> line : input)
    {
        if (is_nice(line))
        {
            counter++;
        }
    }

    std::cout << counter << std::endl;

    return 0;
}