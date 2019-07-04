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
	struct drm_gem_object base;
	struct sg_table *sgt;
};

struct sg_table * drm_gem_cma_prime_get_sg_table(struct drm_gem_object *);
struct drm_gem_object * drm_gem_cma_prime_import_sg_table(struct drm_device *,
    struct dma_buf_attachment *, struct sg_table *);
void * drm_gem_cma_prime_vmap(struct drm_gem_object *);
void drm_gem_cma_prime_vunmap(struct drm_gem_object *, void *);
struct drm_gem_cma_object * drm_gem_cma_create(struct drm_device *, size_t);
void drm_gem_cma_free_object(struct drm_gem_object *);

static inline struct drm_gem_cma_object *
to_drm_gem_cma_obj(struct drm_gem_object *gobj)
{
	return container_of(gobj, struct drm_gem_cma_object, base);
}

int drm_gem_cma_dumb_create(struct drm_file *, struct drm_device *,
    struct drm_mode_create_dumb *);
#endif
