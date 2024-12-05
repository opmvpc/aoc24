#include "Solver.h"

class Day1 : public Solver
{
private:
    /* data */
public:
    virtual void parse(const std::string_view &input);
    virtual std::string part1();
    virtual std::string part2();
    virtual ~Day1()
    {
    }
};
