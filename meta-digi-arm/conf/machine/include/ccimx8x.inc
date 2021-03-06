#@TYPE: Machine
#@NAME: ConnectCore 8X module.
#@DESCRIPTION: Machine configuration for Digi's ConnectCore 8X module.

DIGI_FAMILY = "ccimx8x"
MACHINEOVERRIDES =. "mx8:mx8x:mx8qxp:mx8dxp:mx8dx:${DIGI_FAMILY}:"

include conf/machine/include/imx-digi-base.inc
include conf/machine/include/arm/arch-arm64.inc

# Platform u-boot settings
UBOOT_PREFIX = "imx-boot"
UBOOT_SUFFIX = "bin"

# The bootloader image that gets flashed consists of U-Boot and several fw binaries
EXTRA_IMAGEDEPENDS = "imx-boot"
BOOTLOADER_IMAGE_RECIPE = "imx-boot"
# BOOTLOADER_SEEK is 33 for step A of the silicon and 32 for step B
BOOTLOADER_SEEK = "32"
BOOTABLE_FILENAME = "${UBOOT_PREFIX}-${MACHINE}.bin"
SDIMG_BOOTLOADER = "${DEPLOY_DIR_IMAGE}/${BOOTABLE_FILENAME}"

# RAM variants
# This determines the number of different DCD files, and thus the number of
# different U-Boot binaries required.
# Last one is the default (the one the symlinks point at)
RAM_CONFIGS = "1.2GHz_512MB_16bit 1.2GHz_1GB_16bit 1.2GHz_1GB_32bit 1.2GHz_2GB_32bit"

# Linux kernel configuration
KERNEL_DEFCONFIG ?= "arch/arm64/configs/ccimx8x_defconfig"

# Wireless external module
WIRELESS_MODULE ?= ""

# Firmware
MACHINE_FIRMWARE ?= "firmware-imx-vpu-imx8 firmware-imx-sdma"

MACHINE_EXTRA_RDEPENDS += " \
    e2fsprogs-mke2fs \
    e2fsprogs-resize2fs \
    mca-tool \
    parted \
    u-boot-fw-utils \
    xbee-init \
"

MACHINE_EXTRA_RRECOMMENDS += " \
    ${MACHINE_FIRMWARE} \
    ${WIRELESS_MODULE} \
    cryptodev-module \
    cryptoauthlib \
"

MACHINE_FEATURES += "accel-graphics accel-video wifi bluetooth cryptochip pci"

# AARCH64 doesn't support self-extracting zImage
KERNEL_IMAGETYPE = "Image.gz"

VIRTUAL-RUNTIME_init_manager ?= "systemd"
VIRTUAL-RUNTIME_initscripts ?= "initscripts"

# Adding 'wayland' along with 'x11' enables the xwayland backend
# Vulkan is necessary for wayland to build
DISTRO_FEATURES_append = " wayland vulkan systemd pam"
DISTRO_FEATURES_BACKFILL_CONSIDERED = "sysvinit"
