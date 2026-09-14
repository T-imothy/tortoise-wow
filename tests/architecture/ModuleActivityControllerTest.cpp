#include "BotActivityController.h"
#include <cstdlib>
#include <iostream>
#include <limits>
void Check(bool ok, char const* why) { if (!ok) { std::cerr << why << '\n'; std::exit(1); } }
int main()
{
    using TortoiseBots::BotActivityController;
    BotActivityController c;
    Check(c.Percentage() == 100, "full activity before first measurement");
    Check(std::abs(c.Update(100, 150, 1) - 44.95) < 0.0001, "preserved PID defaults and sign");
    c.Configure(0, 1, 0);
    for (int n=0; n<1000; ++n) Check(c.Update(100, 1000, 1) == 0, "overload saturates");
    Check(c.Update(100, 100, 1) == 50, "saturation cannot accumulate integral windup");
    c.Configure(0, 1, 0);
    Check(c.Update(100, 90, 0.5) == 55 && c.Update(100, 90, 0.5) == 60,
        "integral uses elapsed seconds across cadence variants");
    Check(!c.Configure(std::numeric_limits<double>::infinity(), 0, 0), "infinite tuning rejected");
    Check(c.Update(100, 90, 0) == 60, "zero elapsed does not divide");
    Check(c.Update(100, std::numeric_limits<double>::quiet_NaN(), 1) == 60, "bad sample retains last percentage");
    c.Configure(std::numeric_limits<double>::max(), 0, 0);
    Check(c.Update(100, 0, 1) == 60, "overflow cannot poison controller state");
    c.Configure(1, 0, 0);
    Check(c.Update(100, 0, 1) == 100 && c.Update(100, 1000, 1) == 0, "both bounds recover after retuning");
    std::cout << "Native activity PID cadence, saturation, recovery and invalid-input checks passed\n";
}
