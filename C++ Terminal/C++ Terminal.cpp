#include <iostream>
#include <string>
#include <iterator>
#include <sstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include <fstream>  


using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;

std::string GetNthWord(std::string s, std::size_t n)
{
    std::istringstream iss(s);
    while (n-- > 0 && (iss >> s));
    return s;
}


string GetStdoutFromCommand(string cmd) {

    string data;
    FILE* stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    cmd.append(" 2>&1");

    stream = _popen(cmd.c_str(), "r");
    if (stream) {
        while (!feof(stream))
            if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
        _pclose(stream);
    }
    return data;
}


void handleArg(const std::string& argument)
{
    string data = argument;
    string beg = data.substr(0, data.find(" "));

    if (data == "--help") {

        cout << endl << "Commands: " << endl << endl << "runsh <path to file>" << endl << "Runs a shell file(.sh)" << endl << endl << "dispf <path to file>" << endl << "Displays the contents of a file" << endl << endl << "open <path to file>" << endl << "Open's a text file." << endl << endl << "list <path to directory>" << endl << "Shows all file's and folders in a directory." << endl << endl << "get <url>" << endl << "Fetches data from a url." << endl << endl << "remove <path to file>" << endl << "Delets the given file." << endl;

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
    else if (beg == "get") {

        string getUrlData = GetNthWord(data, 2);
        string periods = "...";

        if (getUrlData != "get") {

            cout << "Fetching data from " + getUrlData;

            for (int i = 1; i < 5; i += 1) {

                cout << periods.substr(i - 1, i);
                sleep_for(0.7s);

            }

            cout << endl << "Response: " << endl << endl << GetStdoutFromCommand(("curl --silent " + getUrlData).c_str());

        }
        else {

            cout << "Missing Second Operand!";


        }

 
    }
    else if (beg == "remove") {

        string fileNameRemove = GetNthWord(data, 2);


        if (fileNameRemove != "remove") {

            if (remove(fileNameRemove.c_str()) != 0)
                cout << endl << "Error while deleting file :(, please check if the path is correct!" << endl;
            else {
               cout << endl << "File successfully deleted!" << endl;
            }
        }
        else {

            cout << "Missing Second Operand!";

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

    cout << "This is a terminal, type '--help' for commands" << endl << endl << "Epic Terminal> ";
    while (true) {
        getline(cin, arg);
        handleArg(arg);
        cout << endl << "Epic Terminal> ";
    }

    return 0;
}