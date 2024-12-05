#include <string>

class Solver
{
private:
public:
    virtual void parse(const std::string &input) = 0;
    virtual std::string part1() = 0;
    virtual std::string part2() = 0;
    virtual ~Solver() = default;
};
