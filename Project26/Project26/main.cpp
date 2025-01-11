#include <iostream>
#include <vector>
#include <memory> 

class Employer {
public:
    virtual void Print() const = 0; 
    virtual ~Employer() {} 
};

class President : public Employer {
public:
    void Print() const override {
        std::cout << "I am the President of the company." << std::endl;
    }
};

class Manager : public Employer {
public:
    void Print() const override {
        std::cout << "I am a Manager in the company." << std::endl;
    }
};

class Worker : public Employer {
public:
    void Print() const override {
        std::cout << "I am a Worker in the company." << std::endl;
    }
};

int main() {
    std::vector<std::unique_ptr<Employer>> employees;
    employees.push_back(std::make_unique<President>());
    employees.push_back(std::make_unique<Manager>());
    employees.push_back(std::make_unique<Worker>());

    for (const auto& employee : employees) {
        employee->Print();
    }

    return 0;
}
