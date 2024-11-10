#ifndef BUILDER_HPP
#define BUILDER_HPP
#include <string>
#include <memory>
class Computer
{
public:
    std::string cpu; // 64 
    std::string gpu;
    std::string ram;

    std::string show() const
    {
        return cpu + "_" + gpu + "_" + ram;
    }
};

// Builder 接口
class ComputerBuilder {
public:
    virtual ~ComputerBuilder() = default;
    virtual void BuildCPU() = 0;
    virtual void BuildGPU() = 0;
    virtual void BuildRAM() = 0;
    virtual std::unique_ptr<Computer> GetComputer() = 0; // 生成具体的Computer
};


// ConcreteBuilder: 游戏电脑生成器
class GamingComputerBuilder : public ComputerBuilder {
private:
    std::unique_ptr<Computer> computer;

public:
    GamingComputerBuilder() { Reset(); }
    
    void Reset() { computer = std::make_unique<Computer>(); }
    
    void BuildCPU() override { computer->cpu = "64"; }
    void BuildGPU() override { computer->gpu = "12GB"; }
    void BuildRAM() override { computer->ram = "16GB"; }
    
    std::unique_ptr<Computer> GetComputer() override {
        return std::move(computer);   // std::unique_ptr
    }
};


// ConcreteBuilder: Office电脑生成器
class OfficeComputerBuilder : public ComputerBuilder {
private:
    std::unique_ptr<Computer> computer;

public:
    OfficeComputerBuilder() { Reset(); }
    
    void Reset() { computer = std::make_unique<Computer>(); }
    
    void BuildCPU() override { computer->cpu = "32"; }
    void BuildGPU() override { computer->gpu = "1GB"; }
    void BuildRAM() override { computer->ram = "16GB"; }
    
    std::unique_ptr<Computer> GetComputer() override {
        return std::move(computer);   // std::unique_ptr
    }
};



// Director: 指挥者
class Director {
private:
    ComputerBuilder* builder;

public:
    void SetBuilder(ComputerBuilder* newBuilder) { builder = newBuilder; }

    void BuildGamingComputer() {
        builder->BuildCPU();
        builder->BuildGPU();
        builder->BuildRAM();
    }

    void BuildOfficeComputer() {
        builder->BuildCPU();
        builder->BuildGPU();
        builder->BuildRAM();

    }
};



#endif // BUILDER_HPP