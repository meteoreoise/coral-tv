#ifndef CORAL_TEXT_H
#define CORAL_TEXT_H

#include "coral/renderer.h"

int coral_text_width(const char *text, int scale);
int coral_text_height(int scale);
void coral_text_draw(CoralRenderer *renderer, float x, float y, int scale,
                     const char *text, u64 color);

#endif /* CORAL_TEXT_H */
