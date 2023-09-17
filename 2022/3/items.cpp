#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

std::map<char, int> priority = {
    {'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}, {'h', 8}, {'i', 9}, {'j', 10}, {'k', 11}, {'l', 12}, {'m', 13}, {'n', 14}, {'o', 15}, {'p', 16}, {'q', 17}, {'r', 18}, {'s', 19}, {'t', 20}, {'u', 21}, {'v', 22}, {'w', 23}, {'x', 24}, {'y', 25}, {'z', 26}, {'A', 27}, {'B', 28}, {'C', 29}, {'D', 30}, {'E', 31}, {'F', 32}, {'G', 33}, {'H', 34}, {'I', 35}, {'J', 36}, {'K', 37}, {'L', 38}, {'M', 39}, {'N', 40}, {'O', 41}, {'P', 42}, {'Q', 43}, {'R', 44}, {'S', 45}, {'T', 46}, {'U', 47}, {'V', 48}, {'W', 49}, {'X', 50}, {'Y', 51}, {'Z', 52}
};

char common_item(std::vector<char> vec_1, std::vector<char> vec_2, std::vector<char> vec_3)
{
    char c;

    for (int i = 0; i < vec_1.size(); i++)
    {
        for (int j = 0; j < vec_2.size(); j++)
        {
            for (int k = 0; k < vec_3.size(); k++)
            {
                if (vec_1[i] == vec_2[j] && vec_1[i] == vec_3[k]) {c = vec_1[i];}
            }
        }
    }

    return c;
}

std::vector<std::vector<char>> read_data(const char *path)
{
    std::ifstream input;
    input.open(path);

    std::vector<std::vector<char>> data;

    std::string line;
    getline(input, line);
    while (!input.eof())
    {
        data.push_back(std::vector<char>(line.begin(), line.end()));
        getline(input, line);
    }

    return data;
}

int main()
{
    std::vector<std::vector<char>> data = read_data("input.txt");

    int prio = 0;

    for (int i = 0; i < data.size() - 2; i += 3)
    {
        char c = common_item(data[i], data[i + 1], data[i + 2]);
        prio += priority[c];
    }

    std::cout << prio << std::endl;
}