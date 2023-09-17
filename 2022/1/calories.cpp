#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int max(std::vector<int> vec)
{
    int max = vec[0];

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > max) {max = vec[i];}
    }

    return max;
}

int sum_top_three(std::vector<int> vec)
{
    std::vector<int> top = {vec[0]};

    for (int i = 1; i < vec.size(); i++)
    {
        int curr = vec[i];

        if (curr > top[0]) {top.insert(top.begin(), curr);}
        if (curr > top[1] && curr != top[0]) {top.insert(top.begin() + 1, curr);}
        if (curr > top[2] && curr != top[1] && curr != top[0]) {top.insert(top.begin() + 2, curr);}
    }

    return (top[0] + top[1] + top[2]);
}

std::vector<int> read_data(const char *path)
{
    std::ifstream input;
    input.open(path);

    std::vector<int> file;

    std::string line;
    getline(input, line);
    while (!input.eof())
    {
        if (line.size() > 0)
        {
            file.push_back(stoi(line));
        }
        else
        {
            file.push_back(0);
        }
        getline(input, line);
    }

    input.close();

    return file;
}

int main()
{
    std::vector<int> data = read_data("input.txt");

    std::vector<int> calories;

    int temp = 0;
    for (int i = 0; i < data.size(); i++)
    {
        temp += data[i];

        if (data[i] == 0)
        {
            calories.push_back(temp);
            temp = 0;
        }
    }
    calories.push_back(temp);

    std::cout << sum_top_three(calories) << std::endl;
}