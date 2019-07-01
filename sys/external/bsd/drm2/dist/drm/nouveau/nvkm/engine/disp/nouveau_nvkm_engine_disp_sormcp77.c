/*	$NetBSD$	*/

/*
 * Copyright 2017 Red Hat Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */
#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD$");

#include "ior.h"

<<<<<<< HEAD:sys/external/bsd/drm2/dist/drm/nouveau/nvkm/engine/fifo/nouveau_nvkm_engine_fifo_gk208.c
#include <nvif/class.h>

void
gk208_fifo_init_pbdma_timeout(struct gk104_fifo *fifo)
{
	struct nvkm_device *device = fifo->base.engine.subdev.device;
	int i;

	for (i = 0; i < fifo->pbdma_nr; i++)
		nvkm_wr32(device, 0x04012c + (i * 0x2000), 0x0000ffff);
}

static const struct gk104_fifo_func
gk208_fifo = {
	.init_pbdma_timeout = gk208_fifo_init_pbdma_timeout,
	.fault.access = gk104_fifo_fault_access,
	.fault.engine = gk104_fifo_fault_engine,
	.fault.reason = gk104_fifo_fault_reason,
	.fault.hubclient = gk104_fifo_fault_hubclient,
	.fault.gpcclient = gk104_fifo_fault_gpcclient,
	.runlist = &gk110_fifo_runlist,
	.chan = {{0,0,KEPLER_CHANNEL_GPFIFO_A}, gk104_fifo_gpfifo_new },
=======
static const struct nvkm_ior_func
mcp77_sor = {
	.state = g94_sor_state,
	.power = nv50_sor_power,
	.clock = nv50_sor_clock,
	.hdmi = {
		.ctrl = g84_hdmi_ctrl,
	},
	.dp = {
		.lanes = { 2, 1, 0, 3},
		.links = g94_sor_dp_links,
		.power = g94_sor_dp_power,
		.pattern = g94_sor_dp_pattern,
		.drive = g94_sor_dp_drive,
		.audio_sym = g94_sor_dp_audio_sym,
		.activesym = g94_sor_dp_activesym,
		.watermark = g94_sor_dp_watermark,
	},
>>>>>>> linux-drm:sys/external/bsd/drm2/dist/drm/nouveau/nvkm/engine/disp/sormcp77.c
};

int
mcp77_sor_new(struct nvkm_disp *disp, int id)
{
	return nvkm_ior_new_(&mcp77_sor, disp, SOR, id);
}
