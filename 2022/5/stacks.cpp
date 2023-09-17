#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<char> read_stack(std::string line)
{
    std::vector<char> stack;

    for (char c : line)
    {
        if (c != ' ')
        {
            stack.push_back(c);
        }
    }

    return stack;
}

std::vector<std::vector<char>> read_stacks(const char *path)
{
    std::ifstream input;
    input.open(path);

    std::vector<std::vector<char>> stacks;

    std::string line;
    getline(input, line);
    while (!input.eof())
    {
        stacks.push_back(read_stack(line));
        getline(input, line);
    }

    return stacks;
}

std::vector<int> read_move(std::string line)
{
    std::vector<int> move;

    std::stringstream line_stream (line);

    std::string temp;
    while (!line_stream.eof())
    {
        line_stream >> temp;

        if ((temp != "move") && (temp != "from") && (temp != "to"))
        {
            move.push_back(std::stoi(temp));
        }
    }

    return move;
}

std::vector<std::vector<int>> read_moves(const char *path)
{
    std::ifstream input;
    input.open(path);

    std::vector<std::vector<int>> moves;

    std::string line;
    getline(input, line);
    while (!input.eof())
    {
        moves.push_back(read_move(line));
        getline(input, line);
    }

    return moves;
}

void move_stacks(std::vector<std::vector<char>> &stacks, int n, int stack_1, int stack_2)
{
    std::vector<char> temp;

    for (int i = 1; i <= n; i++)
    {
        temp.push_back(stacks[stack_1].back());
        stacks[stack_1].pop_back();
    }

    for (int i = 1; i <= n; i++)
    {
        stacks[stack_2].push_back(temp[n - i]);
    }
}

int main()
{
    std::vector<std::vector<char>> stacks = read_stacks("input.txt");
    std::vector<std::vector<int>> moves = read_moves("moves.txt");

    for (std::vector<char> stack : stacks)
    {
        for (char c : stack)
        {
            std::cout << "\t" << c;
        }
        std::cout << std::endl;
    }
    std::cout << "\n\n\n\n" << std::endl;

    for (std::vector<int> move : moves)
    {
        move_stacks(stacks, move[0], (move[1] - 1), (move[2] - 1));
    }

    for (std::vector<char> stack : stacks)
    {
        for (char c : stack)
        {
            std::cout << "\t" << c;
        }
        std::cout << std::endl;
    }
}