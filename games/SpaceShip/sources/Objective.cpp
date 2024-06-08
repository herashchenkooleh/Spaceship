#include "Objective.hpp"

#include "sol/sol.hpp"

namespace SpaceShipGame
{
    Objective::Objective()
    {
        struct vars {
            int boop = 0;
        };

        sol::state lua;
        lua.open_libraries();
        lua.new_usertype<vars>("vars", "boop", &vars::boop);
        lua.script("beep = vars.new()\n"
               "beep.boop = 1\n"
               "print(\"FUCK\")");
        assert(lua.get<vars>("beep").boop == 1);
    }

    Objective::~Objective()
    {
    }
}