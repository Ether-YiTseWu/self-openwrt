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

PROCESSES := $(shell find ./src -maxdepth 1 -type d ! -path ./src ! -path ./src/.)
PROCESS_DIR := $(PKG_BUILD_DIR)

define Build/Prepare
	$(foreach process,$(PROCESSES), \
		mkdir -p $(PROCESS_DIR)/$(notdir $(process)); \
		$(CP) $(process)/* $(PROCESS_DIR)/$(notdir $(process))/; \
	)
endef

define Build/Compile
	$(foreach process,$(PROCESSES), \
		$(MAKE) -C $(PROCESS_DIR)/$(notdir $(process)) $(TARGET_CONFIGURE_OPTS) all; \
	)
endef

define Package/monitor/install
	$(INSTALL_DIR) $(1)/app
	$(foreach process,$(PROCESSES), \
		$(INSTALL_BIN) $(PROCESS_DIR)/$(notdir $(process))/$(notdir $(process)) $(1)/app; \
	)
endef

$(eval $(call BuildPackage,monitor))

