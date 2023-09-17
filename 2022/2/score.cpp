#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct move
{
    public:
    char type;
};

int game(move move_1, move move_2)
{
    int score = 0;

    switch (move_2.type)
    {
    case ('S'):
        switch (move_1.type)
        {
            case ('R'): score += 3; break;
            case ('P'): score += 1; break;
            case ('S'): score += 2; break;
        }

        break;
    
    case ('P'):
        score += 3;

        switch (move_1.type)
        {
            case ('R'): score += 1; break;
            case ('P'): score += 2; break;
            case ('S'): score += 3; break;
        }

        break;
    
    case ('V'):
        score += 6;

        switch (move_1.type)
        {
            case ('R'): score += 2; break;
            case ('P'): score += 3; break;
            case ('S'): score += 1; break;
        }

        break;
    }

    return score;
}

move to_game(char c)
{
    move c_move;
    if (c == 'A') {c_move.type = 'R';}
    else if (c == 'B') {c_move.type = 'P';}
    else if (c == 'C') {c_move.type = 'S';}
    return c_move;
}

move to_match(char c)
{
    move c_move;
    if (c == 'X') {c_move.type = 'S';}
    else if (c == 'Y') {c_move.type = 'P';}
    else if (c == 'Z') {c_move.type = 'V';}
    return c_move;
}

std::vector<std::vector<move>> read_data(const char *path)
{
    std::ifstream input;
    input.open(path);

    std::vector<std::vector<move>> data;

    std::string line;
    getline(input, line);
    while (!input.eof())
    {
        data.push_back(std::vector<move>{to_game(line[0]), to_match(line[2])});
        getline(input, line);
    }

    return data;
}

int main()
{
    std::vector<std::vector<move>> data = read_data("input.txt");

    int score = 0;

    for (std::vector<move> match : data)
    {
        score += game(match[0], match[1]);
    }

    std::cout << score << std::endl;
}