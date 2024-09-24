#include "nlohmann/json.hpp"
#include "trielo/trielo.hpp"
#include "submodule/public.hpp"
#include "app.hpp"

/// This function calculates the area of a rectangle.
int run(int width, int height) {
    (void) width;
    (void) height;
    Trielo::trielo<submodule::foo>();
    const nlohmann::json object {
        { "pi", 3.141 },
        { "happy", true },
        { "name", "Niels" },
        { "nothing", nullptr },
        { "answer",
            {
                {"everything", 42}
            }
        },
        { "list", {1, 0, 2} },
        { "object",
            {
                {"currency", "USD"},
                {"value", 42.99}
            }
        }
    };
    std::cout << std::setw(4) << object << std::endl;
    return 0;
}