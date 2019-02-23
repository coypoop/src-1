#	$NetBSD: driver.mk,v 1.1 2014/12/18 06:24:28 mrg Exp $

# stuff both dri and gallium drivers need.

# util
.PATH:		${X11SRCDIR.MesaLib}/src/util
.PATH:		${X11SRCDIR.MesaLib}/src/gallium/auxiliary/pipe-loader

SRCS.util=	\
	hash_table.c \
	build_id.c \
	crc32.c \
	disk_cache.c \
	fast_idiv_by_const.c \
	half_float.c \
	format_srgb.c \
	mesa-sha1.c \
	os_time.c \
	MESAralloc.c \
	rand_xor.c \
	rb_tree.c \
	register_allocate.c \
	rgtc.c \
	set.c \
	slab.c \
	string_buffer.c \
	strtod.c \
	u_math.c \
	u_queue.c \
	u_vector.c \
	vma.c

SRCS.pipe-loader= \
	pipe_loader.c \
	pipe_loader_drm.c \
	pipe_loader_sw.c

.for _f in ${SRCS.pipe-loader}
CPPFLAGS.${_f}+=	-I${X11SRCDIR.MesaLib}/src/gallium/winsys \
			-I${X11SRCDIR.MesaLib}/src/gallium/auxiliary \
			-I${X11SRCDIR.MesaLib}/src/loader
.endfor

CPPFLAGS+=		-DGALLIUM_STATIC_TARGETS \
			-DHAVE_PIPE_LOADER_DRI \
			-DHAVE_PIPE_LOADER_KMS

CPPFLAGS.format_srgb.c+=	-I${X11SRCDIR.MesaLib}/src/util
CPPFLAGS.hash_table.c+=		-I${X11SRCDIR.MesaLib}/src/util
CPPFLAGS.MESAralloc.c+=		-I${X11SRCDIR.MesaLib}/src/util

BUILDSYMLINKS+=	${X11SRCDIR.MesaLib}/src/util/ralloc.c MESAralloc.c

SRCS+=	${SRCS.util} ${SRCS.pipe-loader}

# also need to pull in libdricommon.la libmegadriver_stub.la
.PATH: ${X11SRCDIR.MesaLib}/src/mesa/drivers/dri/common
SRCS+=	utils.c dri_util.c xmlconfig.c
SRCS+=	megadriver_stub.c
