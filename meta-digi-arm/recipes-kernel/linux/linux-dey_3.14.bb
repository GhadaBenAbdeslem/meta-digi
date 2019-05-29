# Copyright (C) 2015 Digi International

require recipes-kernel/linux/linux-dey.inc
require recipes-kernel/linux/linux-dtb.inc

inherit fsl-vivante-kernel-driver-handler

SRC_URI_append_ccimx6 = " \
    file://0001-mmc-remove-check-for-max-EXT_CSD_REV.patch \
"

SRCBRANCH = "v3.14/dey-2.0/maint"
SRCREV = "281cebeffa46a072e5d64c8e75810a7d9d0dd526"

COMPATIBLE_MACHINE = "(ccimx6$)"
