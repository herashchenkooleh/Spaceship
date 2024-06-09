#include "ssg/Objective.hpp"

#include "sol/sol.hpp"

namespace ssg
{
    Objective::Objective()
    {
        struct vars {
            int boop = 0;
        };

        sol::state lua;
        lua.open_libraries();

        void* handler = reinterpret_cast<void*>(&lua);

        sol::state* lua_ptr = reinterpret_cast<sol::state*>(handler);

        lua_ptr->new_usertype<vars>("vars", "boop", &vars::boop);
        lua_ptr->script("beep = vars.new()\n"
               "beep.boop = 1\n"
               "print(\"FUCK\")");
        assert(lua_ptr->get<vars>("beep").boop == 1);
    }

    Objective::~Objective()
    {
    }
}