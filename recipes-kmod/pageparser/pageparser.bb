LICENSE = "CLOSED"

DESCRIPTION = "Parser for /proc/kpagecount"

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
SRC_URI = " file://pageparser.c \
"
S="${WORKDIR}"
TARGET_CC_ARCH += "${LDFLAGS}"
do_compile() {
    ${CC} ${CCFLAGS} -o ${S}/pageparser ${S}/pageparser.c
}

do_install(){
    install -d -m 755 ${D}${bindir}
    install -m 755 ${S}/pageparser ${D}${bindir}
}

FILES_${PN} += "${bindir}"
