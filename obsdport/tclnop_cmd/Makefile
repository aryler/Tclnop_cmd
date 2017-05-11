# $OpenBSD$

COMMENT =		no-operation command for Tcl

DISTNAME =		tclnop_cmd-0.1
CATEGORIES =		devel
HOMEPAGE =		http://www3.bell.net/stwo/
MAINTAINER =		Stuart Cassoff <stwo@users.sourceforge.net>

# ISC
PERMIT_PACKAGE_CDROM =	Yes

GH_ACCOUNT =		aryler
GH_PROJECT =		Tclnop_cmd
GH_TAGNAME =		0.1

MODULES =		lang/tcl
BUILD_DEPENDS =		${MODTCL_BUILD_DEPENDS}
RUN_DEPENDS =		${MODTCL_RUN_DEPENDS}
SEPARATE_BUILD =	Yes
CONFIGURE_STYLE =	simple
CONFIGURE_ARGS +=	--tcl=${MODTCL_VERSION}

.include <bsd.port.mk>
