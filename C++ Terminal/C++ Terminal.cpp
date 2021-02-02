#include <iostream>
#include <string>
#include <iterator>
#include <sstream>
#include <vector>
#include <algorithm>


using namespace std;


std::string GetNthWord(std::string s, std::size_t n)
{
    std::istringstream iss(s);
    while (n-- > 0 && (iss >> s));
    return s;
}

void handleArg(const std::string& argument)
{
    string data = argument;
    string beg = data.substr(0, data.find(" "));

    if (data == "--help") {

        cout << endl << "Commands: " << endl << endl << "runsh <path to file>" << endl << "Runs a shell file(.sh)" << endl << endl << "dispf <path to file>" << endl << "Displays the contents of a file" << endl << endl << "open <path to file>" << endl << "Open's a text file." << endl << endl << "list <path to directory>" << endl << "Shows all file's and folders in a directory." << endl;

    }
    else if(beg == "runsh")  {

        string fileNameSh = GetNthWord(data, 2);


        if (fileNameSh != "runsh") {
            system(("sh " + fileNameSh).c_str());
        }
        else {

            cout << "Missing Second Operand!";

        }

    }
    else if (beg == "dispf") {

        string fileNameDispf = GetNthWord(data, 2);

        if (fileNameDispf != "dispf") {
            system(("type " + fileNameDispf).c_str());
        }
        else {

            cout << "Missing Second Operand!";

        }
    }
    else if (beg == "open") {

        string fileNameOpen = GetNthWord(data, 2);


        if (fileNameOpen != "open") {
            system(("notepad " + fileNameOpen).c_str());
        }
        else {

            cout << "Missing Second Operand!";

        }

    }
    else if (beg == "list") {

        string fileNameList = GetNthWord(data, 2);


        if (fileNameList != "list") {
            system(("dir " + fileNameList).c_str());
        }
        else {

            system("dir .");

        }

    }
    else if (beg == "help" || beg == "-help") {

        cout << "Did you mean '--help'?" << endl;

    }
    else if (beg == "" || beg == " ") {


    }
    else {

        cout << "Unrecognized command '" + beg + "'!";

    }

}

int main(void) {

    string arg;

    cout << "This is a terminal, type '--help' for commands" << endl << endl << "Cool Terminal> ";
    while (true) {
        getline(cin, arg);
        handleArg(arg);
        cout << endl << "Cool Terminal> ";
    }

    return 0;
}