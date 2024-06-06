#include "Facade.hpp"

/**
 * Facade implementation
 */


void Facade::execute(BaseCommand &command) {
    command.execute();
}