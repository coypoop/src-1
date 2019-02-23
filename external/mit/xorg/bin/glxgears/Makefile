#	$NetBSD: Makefile,v 1.4 2014/12/18 06:24:28 mrg Exp $

NOMAN=	# defined

.include <bsd.own.mk>

PROG=	glxgears

CPPFLAGS+=${X11FLAGS.THREADS}

LDADD+=	-lGL -lglapi -ldrm -lexpat -lXfixes -lxcb-glx -lxcb-dri2 -lXext -lX11 \
	-lX11-xcb -lXxf86vm -lXdamage -lpthread -lm
DPADD+=	${LIBGL} ${LIBGLAPI} ${LIBDRM} ${LIBEXPAT} ${LIBXFIXES} ${LIBXCB_GLX} \
	${LIBXCB_DRI2} ${LIBXEXT} ${LIBX11} ${LIBX11_XCB} ${LIBXXF86VM} \
	${LIBXDAMAGE} ${LIBPTHREAD} ${LIBM}

.PATH:	${X11SRCDIR.mesa-demos}/src/xdemos

.include <bsd.x11.mk>
.include <bsd.prog.mk>
