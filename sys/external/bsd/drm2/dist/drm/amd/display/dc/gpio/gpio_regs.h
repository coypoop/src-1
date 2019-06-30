/*	$NetBSD$	*/

/*
<<<<<<< HEAD:sys/external/bsd/drm2/dist/drm/nouveau/dispnv50/nouveau_dispnv50_sor907d.c
 * Copyright 2018 Red Hat Inc.
=======
 * Copyright 2012-16 Advanced Micro Devices, Inc.
>>>>>>> linux-drm:sys/external/bsd/drm2/dist/drm/amd/display/dc/gpio/gpio_regs.h
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
<<<<<<< HEAD:sys/external/bsd/drm2/dist/drm/nouveau/dispnv50/nouveau_dispnv50_sor907d.c
 */
#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD$");

#include "core.h"
=======
 *
 * Authors: AMD
 *
 */
>>>>>>> linux-drm:sys/external/bsd/drm2/dist/drm/amd/display/dc/gpio/gpio_regs.h

#ifndef DRIVERS_GPU_DRM_AMD_DC_DEV_DC_GPIO_GPIO_REGS_H_
#define DRIVERS_GPU_DRM_AMD_DC_DEV_DC_GPIO_GPIO_REGS_H_

<<<<<<< HEAD:sys/external/bsd/drm2/dist/drm/nouveau/dispnv50/nouveau_dispnv50_sor907d.c
static void
sor907d_ctrl(struct nv50_core *core, int or, u32 ctrl,
	     struct nv50_head_atom *asyh)
{
	u32 *push;
	if ((push = evo_wait(&core->chan, 2))) {
		evo_mthd(push, 0x0200 + (or * 0x20), 1);
		evo_data(push, ctrl);
		evo_kick(push, &core->chan);
	}
}

const struct nv50_outp_func
sor907d = {
	.ctrl = sor907d_ctrl,
=======
struct gpio_registers {
	uint32_t MASK_reg;
	uint32_t MASK_mask;
	uint32_t MASK_shift;
	uint32_t A_reg;
	uint32_t A_mask;
	uint32_t A_shift;
	uint32_t EN_reg;
	uint32_t EN_mask;
	uint32_t EN_shift;
	uint32_t Y_reg;
	uint32_t Y_mask;
	uint32_t Y_shift;
>>>>>>> linux-drm:sys/external/bsd/drm2/dist/drm/amd/display/dc/gpio/gpio_regs.h
};


#endif /* DRIVERS_GPU_DRM_AMD_DC_DEV_DC_GPIO_GPIO_REGS_H_ */
