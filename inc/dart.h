#ifndef DART_H
#define DART_H

#include <stdbool.h>

#include "inc/dart_struct.h"
#include "inc/point.h"
#include "inc/game_enums.h"
#include "inc/game_structs.h"


void DartCreate(Game *game);
//===================================================================

void DartManager(Game *game);
//===================================================================

void DartReset(const Point *point, Dart *dart);
//===================================================================

void DestroyDart(Dart *dart);
//===================================================================

Dart *NewDart(const Point *point);
//===================================================================


#endif // DART_H
