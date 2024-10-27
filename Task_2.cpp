#include <iostream>
#include<string>

int nameIndex = 0;

class Worker {
    char* hisWork = nullptr;   
public:
    std::string name = "Name#";
    Worker() {
        name += std::to_string(nameIndex++);
    }
    void giveWork(char* work) {
        if (hisWork == nullptr) {
            hisWork = work;
            std::cout << "\nWorker  " << name << " start work on " << *hisWork << std::endl;
        }
        else {
            std::cout << "\nAlredy work" << std::endl;
        }
    }
};

class Manager : public Worker {
    int lastIndex = 0;
    int totalAddet = 0;
    int groopIndex = 0;
    int countWorkers = 0;
    char** teamWorks = nullptr;
    Worker** hisWorker = nullptr;
public:
    Manager(int inCountWorkers,int inGroopIndex) {
        countWorkers = inCountWorkers;
        groopIndex = inGroopIndex;
        teamWorks = new char* [inCountWorkers];
        hisWorker = new Worker * [inCountWorkers];
        for (int i = 0; i < inCountWorkers; ++i) {
            hisWorker[i] = new Worker();
        }
    }
    void addWork(int workVector) {
        if (countWorkers <= totalAddet + 1) return;
        std::cout << '\n' + std::string(30, '-') + '\n';
        std::cout << "\nManager name " << name << " start working" << std::endl;
        srand(groopIndex + workVector);
        int temp = (rand() % countWorkers) + 1;
        for (int i = lastIndex; i < temp + totalAddet && i < countWorkers; ++i) {
            int tempFoChar = rand() % 3;
            if (tempFoChar == 0) {
                teamWorks[i] = new char('A');
            }
            else if (tempFoChar == 1) {
                teamWorks[i] = new char('B');
            }
            else {
                teamWorks[i] = new char('C');
            }
            hisWorker[i]->giveWork(teamWorks[i]);
            lastIndex++;
        }
        totalAddet += temp;
    }
    bool allWorkManager() {
        if (lastIndex + 1 >= countWorkers) return true;
        else return false;
    }
};

class Director : public Worker {
    Manager** hisManager = nullptr;
    int countManagers = 0;
    int vectorWork = 0;
public:
    Director(int inCountManagers,int inCountWorkers) {
        countManagers = inCountManagers;
        hisManager = new Manager * [inCountManagers];
        for (int i = 0; i < inCountManagers;++i) {
            hisManager[i] = new Manager(inCountWorkers,i);
        }
    }
    void defineVector() {
        int temp = 0;
        std::cout << "\nEnter vector of work : ";
        std::cin >> temp;
        for (int i = 0; i < countManagers; ++i) {
            hisManager[i]->addWork(temp);
        }
    }
    bool allOnWork() {
        for (int i = 0; i < countManagers; ++i) {
            if (!hisManager[i]->allWorkManager()) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Director first(10, 10);
    while (first.allOnWork()) {
        first.defineVector();
    }
}
