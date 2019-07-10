/*	$NetBSD$	*/

/* Public domain */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD$");

#include <sys/param.h>

#include <drm/drm_client.h>

void
drm_client_dev_hotplug(struct drm_device *dev)
{
#ifdef notyet
	struct drm_client_dev *client;

	client = container_of(dev, struct drm_client_dev, dev);

	if (client->funcs->hotplug != NULL)
		client->funcs->hotplug(client);
#endif
}

void
drm_client_dev_unregister(struct drm_device *d)
{
#ifdef notyet
	struct drm_client_dev *client;

	client = container_of(d, struct drm_client_dev, dev);

	if (client->funcs->unregister != NULL)
		client->funcs->unregister(client);
#endif
}

int
drm_client_init(struct drm_device *dev, struct drm_client_dev *client,
    const char *owner, const struct drm_client_funcs *funcs)
{
#ifdef notyet
	client = kmem_zalloc(sizeof(*client), KM_NOSLEEP);
	if (!client)
		return ENOMEM;

	client->dev = dev;
	client->funcs = funcs;
	client->funcs->owner = kmem_strdup(owner, KM_SLEEP);
#endif
	return 0;
}

void
drm_client_add(struct drm_client_dev *dev)
{

}

void
drm_client_release(struct drm_client_dev *dev)
{

}
