#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
std::string display(std::string selectedword);
void guessletter(std::string selectedword, std::string &display);

int main()
{
    srand(time(NULL));
    std::ifstream myfile("words.txt");
    if (myfile.is_open())
    {
        std::cout << "success" << std::endl;
    }
    else
    {
        std::cout << "fail" << std::endl;
    }
    std::vector<std::string> words;
    std::string input;
    std::string selectedword;
    while (myfile >> input)
    {
        words.push_back(input);
    }
    std::cout << "size of vector" << words.size() << std::endl;
    selectedword = words[rand() % words.size()];

    std::cout << "random word:" << selectedword << std::endl;
    display(selectedword);
    std::string guess;
    guess = display(selectedword);
    std::cout << ":" << guess << std::endl;
    while (guess != selectedword)
    {
        std::cout << "guess a letter:" << guess << std::endl;
        guessletter(selectedword, guess);
    }

    myfile.close();
}

std::string display(std::string selectedword)
{
    std::string display1;
    display1 = "";
    for (int i = 0; i < selectedword.length(); i++)
    {
        display1 += "_";
    }
    return display1;
}

void guessletter(std::string selectedword, std::string &display)
{
    char guess;
    std::cin >> guess;
    for (int i = 0; i < selectedword.length(); i++)
    {
        if (selectedword[i] == guess)
        {
            display[i] = guess;
        }
    }
    std::cout << display << std::endl;
}
