#
# (C) Copyright 2000-2007
# Wolfgang Denk, DENX Software Engineering, wd@denx.de.
#
# SPDX-License-Identifier:	GPL-2.0+
#

ifdef CONFIG_VIDEO_ROCKCHIP
obj-y += rk_vop.o
obj-$(CONFIG_ROCKCHIP_RK3288) += rk3288_vop.o
obj-$(CONFIG_ROCKCHIP_RK3399) += rk3399_vop.o
obj-$(CONFIG_DISPLAY_ROCKCHIP_EDP) += rk_edp.o
obj-$(CONFIG_DISPLAY_ROCKCHIP_LVDS) += rk_lvds.o
obj-hdmi-$(CONFIG_ROCKCHIP_RK3288) += rk3288_hdmi.o
obj-hdmi-$(CONFIG_ROCKCHIP_RK3399) += rk3399_hdmi.o
obj-$(CONFIG_DISPLAY_ROCKCHIP_HDMI) += rk_hdmi.o $(obj-hdmi-y)
obj-$(CONFIG_DISPLAY_ROCKCHIP_MIPI) += rk_mipi.o
endif
