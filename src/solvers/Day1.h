#include <vector>
#include <cstdint>

#include "Solver.h"

class Day1 : public Solver
{
private:
    std::vector<int32_t> left;
    std::vector<int32_t> right;

public:
    void parse(const std::string &input) override;
    std::string part1() override;
    std::string part2() override;
};
