/*	$NetBSD$	*/

/*
<<<<<<< HEAD:sys/external/bsd/drm2/dist/drm/nouveau/nvkm/subdev/mc/nouveau_nvkm_subdev_mc_gp10b.c
 * Copyright (c) 2017, NVIDIA CORPORATION. All rights reserved.
=======
 * Copyright 2018 Advanced Micro Devices, Inc.
>>>>>>> linux-drm:sys/external/bsd/drm2/dist/drm/amd/display/dc/dce/dce_i2c.c
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
 *
<<<<<<< HEAD:sys/external/bsd/drm2/dist/drm/nouveau/nvkm/subdev/mc/nouveau_nvkm_subdev_mc_gp10b.c
=======
 * Authors: AMD
 *
>>>>>>> linux-drm:sys/external/bsd/drm2/dist/drm/amd/display/dc/dce/dce_i2c.c
 */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD$");

#include "dce_i2c.h"
#include "reg_helper.h"

<<<<<<< HEAD:sys/external/bsd/drm2/dist/drm/nouveau/nvkm/subdev/mc/nouveau_nvkm_subdev_mc_gp10b.c
void
gp10b_mc_init(struct nvkm_mc *mc)
{
	struct nvkm_device *device = mc->subdev.device;
	nvkm_wr32(device, 0x000200, 0xffffffff); /* everything on */
	nvkm_wr32(device, 0x00020c, 0xffffffff); /* everything out of ELPG */
}

static const struct nvkm_mc_func
gp10b_mc = {
	.init = gp10b_mc_init,
	.intr = gp100_mc_intr,
	.intr_unarm = gp100_mc_intr_unarm,
	.intr_rearm = gp100_mc_intr_rearm,
	.intr_mask = gp100_mc_intr_mask,
	.intr_stat = gf100_mc_intr_stat,
	.reset = gk104_mc_reset,
};

int
gp10b_mc_new(struct nvkm_device *device, int index, struct nvkm_mc **pmc)
{
	return gp100_mc_new_(&gp10b_mc, device, index, pmc);
=======
bool dce_i2c_submit_command(
	struct resource_pool *pool,
	struct ddc *ddc,
	struct i2c_command *cmd)
{
	struct dce_i2c_hw *dce_i2c_hw;
	struct dce_i2c_sw *dce_i2c_sw;

	if (!ddc) {
		BREAK_TO_DEBUGGER();
		return false;
	}

	if (!cmd) {
		BREAK_TO_DEBUGGER();
		return false;
	}

	/* The software engine is only available on dce8 */
	dce_i2c_sw = dce_i2c_acquire_i2c_sw_engine(pool, ddc);

	if (!dce_i2c_sw) {
		dce_i2c_hw = acquire_i2c_hw_engine(pool, ddc);

		if (!dce_i2c_hw)
			return false;

		return dce_i2c_submit_command_hw(pool, ddc, cmd, dce_i2c_hw);
	}

	return dce_i2c_submit_command_sw(pool, ddc, cmd, dce_i2c_sw);

>>>>>>> linux-drm:sys/external/bsd/drm2/dist/drm/amd/display/dc/dce/dce_i2c.c
}
