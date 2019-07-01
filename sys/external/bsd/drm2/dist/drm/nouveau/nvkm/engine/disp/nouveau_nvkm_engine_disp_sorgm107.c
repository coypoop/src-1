/*	$NetBSD$	*/

/*
 * Copyright 2016 Red Hat Inc.
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
 * Authors: Ben Skeggs <bskeggs@redhat.com>
 */
#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD$");

#include "ior.h"

static int
g84_pcie_version_supported(struct nvkm_pci *pci)
{
	/* g84 and g86 report wrong information about what they support */
	return 1;
}

int
g84_pcie_version(struct nvkm_pci *pci)
{
	struct nvkm_device *device = pci->subdev.device;
	return (nvkm_rd32(device, 0x00154c) & 0x1) + 1;
}

void
g84_pcie_set_version(struct nvkm_pci *pci, u8 ver)
{
	struct nvkm_device *device = pci->subdev.device;
	nvkm_mask(device, 0x00154c, 0x1, (ver >= 2 ? 0x1 : 0x0));
}

static void
g84_pcie_set_cap_speed(struct nvkm_pci *pci, bool full_speed)
{
	struct nvkm_device *device = pci->subdev.device;
	nvkm_mask(device, 0x00154c, 0x80, full_speed ? 0x80 : 0x0);
}

enum nvkm_pcie_speed
g84_pcie_cur_speed(struct nvkm_pci *pci)
{
	u32 reg_v = nvkm_pci_rd32(pci, 0x88) & 0x30000;
	switch (reg_v) {
	case 0x30000:
		return NVKM_PCIE_SPEED_8_0;
	case 0x20000:
		return NVKM_PCIE_SPEED_5_0;
	case 0x10000:
	default:
		return NVKM_PCIE_SPEED_2_5;
	}
}

enum nvkm_pcie_speed
g84_pcie_max_speed(struct nvkm_pci *pci)
{
	u32 reg_v = nvkm_pci_rd32(pci, 0x460) & 0x3300;
	if (reg_v == 0x2200)
		return NVKM_PCIE_SPEED_5_0;
	return NVKM_PCIE_SPEED_2_5;
}

void
g84_pcie_set_link_speed(struct nvkm_pci *pci, enum nvkm_pcie_speed speed)
{
	u32 mask_value;

	if (speed == NVKM_PCIE_SPEED_5_0)
		mask_value = 0x20;
	else
		mask_value = 0x10;

	nvkm_pci_mask(pci, 0x460, 0x30, mask_value);
	nvkm_pci_mask(pci, 0x460, 0x1, 0x1);
}

int
g84_pcie_set_link(struct nvkm_pci *pci, enum nvkm_pcie_speed speed, u8 width)
{
	g84_pcie_set_cap_speed(pci, speed == NVKM_PCIE_SPEED_5_0);
	g84_pcie_set_link_speed(pci, speed);
	return 0;
}

void
gm107_sor_dp_pattern(struct nvkm_ior *sor, int pattern)
{
	struct nvkm_device *device = sor->disp->engine.subdev.device;
	const u32 soff = nv50_ior_base(sor);
	const u32 data = 0x01010101 * pattern;
	if (sor->asy.link & 1)
		nvkm_mask(device, 0x61c110 + soff, 0x0f0f0f0f, data);
	else
		nvkm_mask(device, 0x61c12c + soff, 0x0f0f0f0f, data);
}

<<<<<<< HEAD:sys/external/bsd/drm2/dist/drm/nouveau/nvkm/subdev/pci/nouveau_nvkm_subdev_pci_g84.c
int
g84_pcie_init(struct nvkm_pci *pci)
{
	bool full_speed = g84_pcie_cur_speed(pci) == NVKM_PCIE_SPEED_5_0;
	g84_pcie_set_cap_speed(pci, full_speed);
	return 0;
}

static const struct nvkm_pci_func
g84_pci_func = {
	.init = g84_pci_init,
	.rd32 = nv40_pci_rd32,
	.wr08 = nv40_pci_wr08,
	.wr32 = nv40_pci_wr32,
	.msi_rearm = nv46_pci_msi_rearm,

	.pcie.init = g84_pcie_init,
	.pcie.set_link = g84_pcie_set_link,

	.pcie.max_speed = g84_pcie_max_speed,
	.pcie.cur_speed = g84_pcie_cur_speed,

	.pcie.set_version = g84_pcie_set_version,
	.pcie.version = g84_pcie_version,
	.pcie.version_supported = g84_pcie_version_supported,
=======
static const struct nvkm_ior_func
gm107_sor = {
	.state = gf119_sor_state,
	.power = nv50_sor_power,
	.clock = gf119_sor_clock,
	.hdmi = {
		.ctrl = gk104_hdmi_ctrl,
	},
	.dp = {
		.lanes = { 0, 1, 2, 3 },
		.links = gf119_sor_dp_links,
		.power = g94_sor_dp_power,
		.pattern = gm107_sor_dp_pattern,
		.drive = gf119_sor_dp_drive,
		.vcpi = gf119_sor_dp_vcpi,
		.audio = gf119_sor_dp_audio,
		.audio_sym = gf119_sor_dp_audio_sym,
		.watermark = gf119_sor_dp_watermark,
	},
	.hda = {
		.hpd = gf119_hda_hpd,
		.eld = gf119_hda_eld,
	},
>>>>>>> linux-drm:sys/external/bsd/drm2/dist/drm/nouveau/nvkm/engine/disp/sorgm107.c
};

int
gm107_sor_new(struct nvkm_disp *disp, int id)
{
	return nvkm_ior_new_(&gm107_sor, disp, SOR, id);
}
