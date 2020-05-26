#include <bits/stdc++.h>

using namespace std;

class Component {
public:
    Component() {}
    virtual ~Component(){}
    virtual void print(int) = 0;
};

class Directory : public Component {
public:
    ~Directory() {}
    Directory() {}
    Directory(string id) : m_id(id) {}
    void add(Component *input) {
        m_comp.push_back(input);
    }

    void print(int tap = 0) {
        for(int i = 0; i < tap; i++) print("\t");
        printf("directory : %s\n", m_id.c_str());

        for(auto dir : m_comp) {
            dir->print(tap + 1);
        }
    }

private:
    vector<Component*> m_comp;
    string m_id;
};

class File : public Component {
public:
    ~File() {}
    File() {}
    File(string id) : m_id(id) {}
    void print(int tap = 0) {
        for(int i = 0; i < tap; i++) printf("\t");
        printf("file : %s\n", m_id.c_str());
    }

private:
    string m_id;
};

int main()
{
    Directory *dir_engineering = new Directory("Engineering");
    Directory *dir_computer_science = new Directory("Computer Science");
    Directory *dir_algorithm = new Directory("Algorithm");
    Directory *dir_AI = new Directory("AI");

    dir_algorithm->add(new File("Binary Search"));
    dir_algorithm->add(new File("BFS"));
    dir_algorithm->add(new File("Dinic Algorithm"));
    dir_computer_science->add(dir_algorithm);

    dir_AI->add(new File("ReinForcement Learning"));
    dir_AI->add(new File("CNN"));
    dir_computer_science->add(dir_AI);

    dir_engineering->add(dir_computer_science);
    dir_engineering->print();
    return 0;
}