#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#define vec vector<string>
 
using namespace std;
 
ifstream in("quack.in");
ofstream out("quack.out");
 
class Interpreter {
private:
    queue <unsigned short> QUEUE;    //очередь
    map <string,int> labels;    // переменные
    map <char,int> registers;    //алфавит
    vec commands;               //команды
    ofstream out;
 
public:
    void start() {
        int i = 0;
        while (i < commands.size()) {
            string command = commands[i];
            unsigned short a;
            unsigned short b;
            if (command.empty()) continue;
            switch (command[0]) {
                case '+':
                    a = deque();
                    b = deque();
                    QUEUE.push(a + b);
                    i++;
                    break;
                case '-':
                    a = deque();
                    b = deque();
                    QUEUE.push(a - b);
                    i++;
                    break;
                case '*':
                    a = deque();
                    b = deque();
                    QUEUE.push(a * b);
                    i++;
                    break;
                case '/':
                    a = deque();
                    b = deque();
                    if (b != 0) QUEUE.push(a / b);
                    else QUEUE.push(0);
                    i++;
                    break;
                case '%':
                    a = deque();
                    b = deque();
                    if (b != 0) QUEUE.push(a % b);
                    else QUEUE.push(0);
                    i++;
                    break;
                case '>':
                    registers[command[1]] = deque();
                    i++;
                    break;
                case'<':
                    QUEUE.push(registers[command[1]]);
                    i++;
                    break;
                case 'P':
                    if (command.size() == 1) out << deque() << '\n';
                    else out << registers[command[1]] << '\n';
                    i++;
                    break;
                case 'C':
                    if (command.size() == 1) out << char(deque() % 256);
                    else out << char(registers[command[1]] % 256);
                    i++;
                    break;
                case 'Z':
                    if (registers[command[1]] == 0) i = labels[command.substr(2)];
                    else i++;
                    break;
                case 'J':
                    i = labels[command.substr(1)];
                    break;
                case 'E':
                    if (registers[command[1]] == registers[command[2]]) i = labels[command.substr(3)];
                    else i++;
                    break;
                case 'G':
                    if (registers[command[1]] > registers[command[2]]) i = labels[command.substr(3)];
                    else i++;
                    break;
                case ':':
                    i++;
                    break;
                case 'Q':
                    return;
                default:
                    QUEUE.push(stoi(command));
                    i++;
                    break;
            }
        }
    }
 
    void regs_init() {
        for (int i = 0; i < 26; i++) registers[i] = 0;
        out.open("quack.out");
    }
 
    unsigned short deque() {
        unsigned short first=QUEUE.front();
        QUEUE.pop();
        return first;
    }
 
    void command_get() {
        while (!in.eof()) {
            string command;
            getline(in, command);
            if (!command.empty()) commands.push_back(command);
        }
    }
 
    void label_set() {
        for (int i = 0; i < commands.size(); i++) {
            string command = commands[i];
            if (command[0] == ':') labels[command.substr(1)] = i;
        }
    }
};
 
int main() {
    Interpreter inter;
    inter.regs_init();
    inter.command_get();
    inter.label_set();
    inter.start();
    return 0;
}
