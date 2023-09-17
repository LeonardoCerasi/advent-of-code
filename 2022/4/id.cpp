#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> parse_data(std::string line)
{
    std::vector<int> parsed_line;

    std::stringstream line_stream(line);

    for (int i; line_stream >> i;)
    {
        parsed_line.push_back(i);
        
        if (line_stream.peek() == ',' || line_stream.peek() == '-') {line_stream.ignore();}
    }

    return parsed_line;
}

std::vector<std::vector<int>> read_data(const char *path)
{
    std::ifstream input;
    input.open(path);

    std::vector<std::vector<int>> data;

    std::string line;
    getline(input, line);
    while(!input.eof())
    {
        data.push_back(parse_data(line));
        getline(input, line);
    }

    return data;
}

int main()
{
    std::vector<std::vector<int>> data = read_data("input.txt");

    int counter = 0;
    for (std::vector<int> pair : data)
    {
        if ((pair[1] >= pair[2]) && (pair[0] <= pair[3])) {counter++;}
    }

    std::cout << counter << std::endl;
}