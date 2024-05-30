#include "Facade.h"

/**
 * Facade implementation
 */


void Facade::execute(BaseCommand &command) {
    command.execute();
}