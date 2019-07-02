/*	$NetBSD$	*/

/* Public domain */

#ifndef _DRM_CLIENT_H_
#define _DRM_CLIENT_H_

#include <sys/kmem.h>

struct drm_client_dev {
	struct drm_device *dev;
};

struct drm_client_funcs {
	int owner;
	void (*unregister)(struct drm_client_dev *);
	int (*restore)(struct drm_client_dev *);
	int (*hotplug)(struct drm_client_dev *);
};

struct drm_client_buffer {
	struct drm_framebuffer *fb;
};

static inline struct drm_client_buffer *
drm_client_framebuffer_create(struct drm_client_dev *client,
    uint32_t surface_width, uint32_t surface_height, uint32_t format)
{
	struct drm_client_buffer * buffer;

	buffer = kmem_zalloc(sizeof(*buffer), KM_NOSLEEP);
	buffer->fb = NULL;

	return buffer;
}

static inline void
drm_client_framebuffer_delete(struct drm_client_buffer * buffer)
{

	kmem_free(buffer, sizeof(*buffer));
}

#endif
