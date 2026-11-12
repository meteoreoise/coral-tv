#include <stddef.h>

#include "coral/logger.h"
#include "coral/renderer.h"
#include "coral/text.h"
#include "coral/version.h"

static void draw_centered_text(CoralRenderer *renderer, int scale,
                               const char *text, float y, u64 color)
{
	int width = coral_text_width(text, scale);
	float x = ((float)renderer->gs->Width - (float)width) / 2.0f;

	coral_text_draw(renderer, x, y, scale, text, color);
}

static void draw_home(CoralRenderer *renderer)
{
	GSGLOBAL *gs = renderer->gs;
	float width = (float)gs->Width;
	float height = (float)gs->Height;
	int title_scale = gs->Width / 80;
	int coral_width;
	int tv_width;
	int title_width;
	float title_x;
	float title_y;
	float underline_y;
	const char *status = "SYSTEM READY";
	int status_scale = 2;
	int status_width = coral_text_width(status, status_scale);
	float pill_width = (float)(status_width + 54);
	float pill_height = 40.0f;
	float pill_x;
	float pill_y;
	float divider_y;
	int version_width;

	if (title_scale < 4)
		title_scale = 4;
	if (title_scale > 10)
		title_scale = 10;

	coral_renderer_fill_rect(renderer, 0.0f, 0.0f, width, 6.0f,
	                         CORAL_COLOR_ACCENT);

	coral_width = coral_text_width("CORAL", title_scale);
	tv_width = coral_text_width("TV", title_scale);
	title_width = coral_width + 2 * title_scale + tv_width;
	title_x = (width - (float)title_width) / 2.0f;
	title_y = height * 0.30f;

	coral_text_draw(renderer, title_x, title_y, title_scale, "CORAL",
	                CORAL_COLOR_ACCENT);
	coral_text_draw(renderer, title_x + coral_width + 2 * title_scale,
	                title_y, title_scale, "TV", CORAL_COLOR_TEXT);

	underline_y = title_y + (float)coral_text_height(title_scale) + 14.0f;
	coral_renderer_fill_rect(renderer, title_x, underline_y,
	                         (float)title_width, 3.0f, CORAL_COLOR_ACCENT);

	draw_centered_text(renderer, 2, "PLAYSTATION 2 HOMEBREW LAUNCHER",
	                   underline_y + 28.0f, CORAL_COLOR_MUTED);

	pill_x = (width - pill_width) / 2.0f;
	pill_y = height * 0.56f;
	coral_renderer_fill_rect(renderer, pill_x, pill_y, pill_width,
	                         pill_height, CORAL_COLOR_SURFACE);
	coral_renderer_fill_rect(renderer, pill_x + 16.0f, pill_y + 16.0f,
	                         8.0f, 8.0f, CORAL_COLOR_ACCENT);
	coral_text_draw(renderer, pill_x + 38.0f, pill_y + 13.0f, status_scale,
	                status, CORAL_COLOR_TEXT);

	divider_y = height - 64.0f;
	coral_renderer_fill_rect(renderer, 48.0f, divider_y, width - 96.0f, 1.0f,
	                         CORAL_COLOR_SURFACE);
	coral_text_draw(renderer, 48.0f, height - 44.0f, 2, CORAL_PHASE_STRING,
	                CORAL_COLOR_MUTED);

	version_width = coral_text_width("V" CORAL_VERSION_STRING, 2);
	coral_text_draw(renderer, width - 48.0f - (float)version_width,
	                height - 44.0f, 2, "V" CORAL_VERSION_STRING,
	                CORAL_COLOR_MUTED);
}

int main(int argc, char *argv[])
{
	CoralRenderer renderer;

	(void)argc;
	(void)argv;

	coral_log_init();
	coral_log_info("CORAL TV %s starting", CORAL_VERSION_STRING);

	if (coral_renderer_init(&renderer) != 0) {
		coral_log_error("renderer initialisation failed, halting");
		return 1;
	}

	coral_log_info("entering render loop");

	for (;;) {
		coral_renderer_begin_frame(&renderer, CORAL_COLOR_BG);
		draw_home(&renderer);
		coral_renderer_end_frame(&renderer);
	}

	coral_renderer_shutdown(&renderer);
	return 0;
}
