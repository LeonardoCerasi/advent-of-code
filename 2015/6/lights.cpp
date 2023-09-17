#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct light
{
    public:
    int light = 0;
    void turn_on() {this->light++;}
    void turn_off()
    {
        this->light--;
        if (this->light < 0)
        {
            this->light = 0;
        }
    }
    void toggle() {this->light += 2;}
};

std::vector<int> read_line(std::string line)
{
    std::vector<int> parsed_line;

    if (line.find("turn off") != std::string::npos) {
        parsed_line.push_back(0);
        line.erase(0, 8);
    }
    else if (line.find("turn on") != std::string::npos) {
        parsed_line.push_back(1);
        line.erase(0, 7);
    }
    else if (line.find("toggle") != std::string::npos) {
        parsed_line.push_back(2);
        line.erase(0, 6);
    }

    std::stringstream line_stream(line);

    std::string temp;
    while (!line_stream.eof())
    {
        line_stream >> temp;

        if (temp != "through")
        {
            std::stringstream temp_stream(temp);

            for (int i; temp_stream >> i;)
            {
                parsed_line.push_back(i);
                
                if (temp_stream.peek() == ',') {temp_stream.ignore();}
            }
        }
    }

    return parsed_line;
}

std::vector<std::vector<int>> read_file(const char *path)
{
    std::vector<std::vector<int>> file;

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
        file.push_back(read_line(line));
        getline(input, line);
    }

    return file;
}

int main()
{
    std::vector<std::vector<light>> grid(1000, std::vector<light>(1000, light()));

    std::vector<std::vector<int>> instructions = read_file("input.txt");

    for (std::vector<int> inst : instructions)
    {
        for (int i = inst[1]; i <= inst[3]; i++)
        {
            for (int j = inst[2]; j <= inst[4]; j++)
            {
                if (inst[0] == 0) {grid[i][j].turn_off();}
                if (inst[0] == 1) {grid[i][j].turn_on();}
                if (inst[0] == 2) {grid[i][j].toggle();}
            }
        }
    }

    int luminosity = 0;
    for (std::vector<light> line : grid)
    {
        for (light item : line)
        {
            luminosity += item.light;
        }
    }

    std::cout << luminosity << std::endl;
}