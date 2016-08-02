#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>

#include <vu/rectangle.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

int main()
{
	vita2d_init();
	vita2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));

	vita2d_pgf *pgf = vita2d_load_default_pgf();

	SceCtrlData pad;
	memset(&pad, 0, sizeof(pad));

        vu_rectangle *r = vu_rectangle_new();
        vu_rectangle_set_color(r, (vec4){0xFF, 0x00, 0x00, 0xFF});
        vu_rectangle_resize(r, (vec2){200, 200});

	while (1) {
		sceCtrlPeekBufferPositive(0, &pad, 1);

		if (pad.buttons & SCE_CTRL_START)
			break;

		vita2d_start_drawing();
		vita2d_clear_screen();

                vu_rectangle_render(r);

		vita2d_pgf_draw_text(pgf, 20, 30, RGBA8(0xFF,0xFF,0xFF,0xFF), 1.0f, "PS Vita Package Manager");

		vita2d_end_drawing();
		vita2d_swap_buffers();
	}

	vita2d_free_pgf(pgf);
	//vita2d_fini(); crashes

	sceKernelExitProcess(0);
	return 0;
}
