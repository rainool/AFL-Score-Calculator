#include "splashkit.h"

/**
 * @param goals number of goals scored
 * @param behinds number of behinds 
 * @return total score = goals*6 + behinds
 */
int score_calc(int goals, int behinds)
{
    return goals*6 + behinds;
}

/**
 * @param team1 Name of first team
 * @param score1 team1's score
 * @param team2 Name of second team
 * @param score2 team2's score
 * @return String indicating which team is winning, or is they are in a draw
 */
string determine_winner(const string &team1, int score1, const string &team2, int score2)
{
    if (score1>score2)
        return team1 + " is winning";
    else if (score1<score2)
        return team2 + " is winning";
    else
        return "It is currently a draw !!";
}

/**
 * @param team1 The name of the first team
 * @param goals1 The number of goals for the first team
 * @param behinds1 The number of behinds for the first team
 * @param team2 The name of the second team
 * @param goals2 The number of goals for the second team
 * @param behinds2 The number of behinds for the second team
 */
void output_details(const string &team1, int goals1, int behinds1, const string &team2, int goals2, int behinds2)
{
    int score1 = score_calc(goals1, behinds1);
    int score2 = score_calc(goals2, behinds2);

    write_line("Calculating...");
    write_line(determine_winner(team1, score1, team2, score2));
    write_line(team1 + ": " + to_string(goals1) + ", " + to_string(behinds1) + ", " + to_string(score1));
    write_line(team2 + ": " + to_string(goals2) + ", " + to_string(behinds2) + ", " + to_string(score2));
}

/**
 * @param team1 The name of the first team
 * @param team2 The name of the second team
 */
void print_menu(const string &team1, const string &team2)
{
    write_line("Menu:");
    write_line("1: Update " + team1 + " goals");
    write_line("2: Update " + team1 + " behinds");
    write_line("3: Update " + team2 + " goals");
    write_line("4: Update " + team2 + " behinds");
    write_line("5: Print details");
    write_line("6: Quit");
}

/**
 * @return Valid menu options from 1-6
 */
int get_menu_option()
{
    int option;

    while (true)
    {
        option = read_integer("Option: ");

        if (option >= 1 && option <= 6)
            return option;
        else    
            write_line("Please enter a number between 1-6");
    }
}

int main()
{
    string team1, team2;
    int goals1 = 0, goals2 = 0, behinds1 = 0, behinds2 = 0;
    int option;
    bool quit = false;

    write_line("Welcome to the AFL Score calculator");
    write_line("This is a program written by Ryan Liu (s224476007)");

    //Team 1 details
    write_line("Enter team1 details:");
    team1 = read_string("Team 1 name: ");
    goals1 = read_integer("Team 1 goals: ");
    behinds1 = read_integer("Team 1 behinds: ");

    //Team 2 details
    write_line("Enter team 2 details:");
    team2 = read_string("Team 2 name:");
    goals2 = read_integer("Team 2 goals:");
    behinds2 = read_integer("Team 2 behinds:");

    //initial output
    output_details(team1, goals1, behinds1, team2, goals2, behinds2);

    //loop
    while (!quit)
    {
        print_menu(team1, team2);
        option = get_menu_option();

        switch (option)
        {
            case 1:
                goals1 = read_integer("Goals: ");
                break;
            case 2:
                behinds1 = read_integer("Behinds: ");
                break;
            case 3:
                goals2 = read_integer("Goals: ");
                break;
            case 4:
                behinds2 = read_integer("Behinds: ");
                break;
            case 5:
                output_details(team1, goals1, behinds1, team2, goals2, behinds2);
                break;
            case 6:
                if (read_bool("Are you sure you want to quit? [y/n]: "))
                {
                    write_line("Bye!!!");
                    quit = true;
                }
                break;
            
        }

    }
    return 0;
}