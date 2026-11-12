#ifndef CORAL_RENDERER_H
#define CORAL_RENDERER_H

#include <gsKit.h>

typedef struct {
	GSGLOBAL *gs;
} CoralRenderer;

#define CORAL_COLOR_BG \
	GS_SETREG_RGBAQ(0x0E, 0x0E, 0x12, 0x80, 0x00)
#define CORAL_COLOR_SURFACE \
	GS_SETREG_RGBAQ(0x1C, 0x1C, 0x22, 0x80, 0x00)
#define CORAL_COLOR_ACCENT \
	GS_SETREG_RGBAQ(0xFF, 0x7F, 0x50, 0x80, 0x00)
#define CORAL_COLOR_TEXT \
	GS_SETREG_RGBAQ(0xF2, 0xF2, 0xF2, 0x80, 0x00)
#define CORAL_COLOR_MUTED \
	GS_SETREG_RGBAQ(0x8A, 0x8A, 0x92, 0x80, 0x00)

int coral_renderer_init(CoralRenderer *renderer);
void coral_renderer_shutdown(CoralRenderer *renderer);
void coral_renderer_begin_frame(CoralRenderer *renderer, u64 clear_color);
void coral_renderer_end_frame(CoralRenderer *renderer);
void coral_renderer_fill_rect(CoralRenderer *renderer, float x, float y,
                              float width, float height, u64 color);

#endif /* CORAL_RENDERER_H */
