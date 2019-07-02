/* Public domain */

#ifndef _DRM_GEM_CMA_HELPER_H_
#define _DRM_GEM_CMA_HELPER_H_

#include <drm/drm_gem.h>

struct drm_gem_cma_object {
	bus_dma_tag_t dmat;
	bus_dma_segment_t *dmasegs;
	size_t dmasize;
	void *vaddr;
	bus_dmamap_t dmamap;
	struct drm_gem_object *base;
	struct sg_table *sgt;
};

#endif
