#include <stddef.h>

#include "coral/logger.h"
#include "coral/renderer.h"

int coral_renderer_init(CoralRenderer *renderer)
{
	renderer->gs = NULL;

	dmaKit_init(D_CTRL_RELE_OFF, D_CTRL_MFD_OFF, D_CTRL_STS_UNSPEC,
	            D_CTRL_STD_OFF, D_CTRL_RCYC_8, 1 << DMA_CHANNEL_GIF);
	dmaKit_chan_init(DMA_CHANNEL_GIF);

	renderer->gs = gsKit_init_global();
	if (renderer->gs == NULL) {
		coral_log_error("gsKit_init_global returned NULL");
		return -1;
	}

	renderer->gs->PrimAlphaEnable = GS_SETTING_ON;

	gsKit_init_screen(renderer->gs);
	gsKit_mode_switch(renderer->gs, GS_PERSISTENT);
	gsKit_set_test(renderer->gs, GS_ZTEST_OFF);

	coral_log_info("GS screen %dx%d, mode %d", renderer->gs->Width,
	               renderer->gs->Height, renderer->gs->Mode);

	return 0;
}

void coral_renderer_shutdown(CoralRenderer *renderer)
{
	if (renderer->gs != NULL) {
		gsKit_deinit_global(renderer->gs);
		renderer->gs = NULL;
	}
}

void coral_renderer_begin_frame(CoralRenderer *renderer, u64 clear_color)
{
	gsKit_clear(renderer->gs, clear_color);
}

void coral_renderer_end_frame(CoralRenderer *renderer)
{
	gsKit_queue_exec(renderer->gs);
	gsKit_sync_flip(renderer->gs);
}

void coral_renderer_fill_rect(CoralRenderer *renderer, float x, float y,
                              float width, float height, u64 color)
{
	gsKit_prim_quad(renderer->gs, x, y, x + width, y, x, y + height,
	                x + width, y + height, 0, color);
}
