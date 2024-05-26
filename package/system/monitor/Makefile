include $(TOPDIR)/rules.mk

PKG_NAME := monitor
PKG_VERSION := 1.0
PKG_RELEASE := 1

include $(INCLUDE_DIR)/package.mk

define Package/monitor
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=monitor
endef

define Package/monitor/description
	Ether.wu side project
endef

PROCESS1_DIR := $(PKG_BUILD_DIR)/monitor
PROCESS2_DIR := $(PKG_BUILD_DIR)/infra
PROCESS3_DIR := $(PKG_BUILD_DIR)/upgrade

define Build/Prepare
	mkdir -p $(PROCESS1_DIR)
	$(CP) ./src/monitor/* $(PROCESS1_DIR)/
	mkdir -p $(PROCESS2_DIR)
	$(CP) ./src/infra/*   $(PROCESS2_DIR)/
	mkdir -p $(PROCESS3_DIR)
	$(CP) ./src/upgrade/* $(PROCESS3_DIR)/
endef

define Build/Compile
	$(MAKE) -C $(PROCESS1_DIR) $(TARGET_CONFIGURE_OPTS) all
	$(MAKE) -C $(PROCESS2_DIR) $(TARGET_CONFIGURE_OPTS) all
	$(MAKE) -C $(PROCESS3_DIR) $(TARGET_CONFIGURE_OPTS) all
endef

define Package/monitor/install
	$(INSTALL_DIR) $(1)/app
	$(INSTALL_BIN) $(PROCESS1_DIR)/monitor $(1)/app
	$(INSTALL_BIN) $(PROCESS2_DIR)/infra   $(1)/app
	$(INSTALL_BIN) $(PROCESS3_DIR)/upgrade $(1)/app
endef

$(eval $(call BuildPackage,monitor))
