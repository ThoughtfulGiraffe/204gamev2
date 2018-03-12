#include "Engine.h"

int main()
{
    Engine* engine = new Engine(640, 480, 32);
    engine->Go();

    return 0;
}
