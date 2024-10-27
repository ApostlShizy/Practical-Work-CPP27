#include <iostream>
#include <vector>

int neighbours = 0;

class BranchHome {
    bool branchHome = true;
public:
    int count = 0;
    std::string* name = nullptr;
    void setName() {
        std::string temp;
        std::cout << "\nEnter elf name in house or none to not admit it : ";
        std::cin >> temp;
        if (temp != "none") {
            name = new std::string(temp);
        }
        else {
            std::cout << "\nNo one will live here" << std::endl;
        }
    }
    std::string getName() {
        if (name == nullptr) return "";
        neighbours++;
        return *name;
    }
};

class MiddleBranch {
    bool middleBranch = true;
    BranchHome* onMidBranch = nullptr;
    int count = 0;
    public:
        MiddleBranch() {
            onMidBranch = new BranchHome();
            onMidBranch->setName();
        }
        bool findHomeMidle(std::string findName) {
            if (findName == onMidBranch->getName()) return true;
            return false;
        }        
};

class BigBranch  {
    bool bigBranch = true;
    int count = 0;
    MiddleBranch** onBigBranch = nullptr;
public:
    BigBranch() {
        count = (rand() % 2) + 2;        
        onBigBranch = new MiddleBranch * [count];
        for (int i = 0; i < count; ++i) {
            onBigBranch[i] = new MiddleBranch();
        }
    }

    bool findHomeBig(std::string findName) {
        for (int i = 0; i < count; ++i) {
            if(onBigBranch[i]->findHomeMidle(findName)) return true;
        }
        return false;
    }
};

class Tree {
    int count = 0;
public:
    BigBranch** onTree = nullptr;
    Tree() {
        count = (rand() % 3) + 3;
        onTree = new BigBranch * [count];        
        for (int i = 0; i < count; ++i) {
            std::cout << '\n' + std::string(10, '-') + '\n';
            std::cout << "\nBig branch " << i + 1<<std::endl;
            onTree[i] = new BigBranch();
        }
    }
    bool findHomeTree(std::string findName) {
        for (int i = 0; i < count; ++i) {
            if (onTree[i]->findHomeBig(findName)) {
                countOnBranch(i);
                return true;
            }
        }
        std::cout << "\nNot found on this tree." << std::endl;
        return false;
    }
    void countOnBranch(int i) {      
        neighbours = 0;
        onTree[i]->findHomeBig("");
        std::cout << "\nHe has " << neighbours - 1 << " neighbours";
    }
};

class Forest {
    int count = 0;
    Tree** newForest = nullptr;

public:
    Forest(int inCount) : count(inCount) {
        newForest = new Tree * [inCount];
        for (int i = 0; i < inCount; ++i) {
            std::cout << '\n' + std::string(30, '-') + '\n';
            std::cout << "\nIts " << i + 1 << " tree" << std::endl;
            newForest[i] = new Tree();
        }
    }
    void findElf(std::string name) {
        for (int i = 0; i < count; ++i) {
            if (newForest[i]->findHomeTree(name)) {
                return;
            }
        }
        std::cout << "\nNot found this elf" << std::endl;
    }
};

int main()
{
    srand(std::time(nullptr));
    Forest* first = new Forest (5);
    std::string name;
    std::cout << '\n' + std::string(30, '-') + '\n';
    std::cout << "\nEnter name that need find : ";
    std::cin >> name;   
    first->findElf(name);
    delete first;
}

