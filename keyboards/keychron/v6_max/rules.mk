include keyboards/keychron/common/wireless/wireless.mk
include keyboards/keychron/common/keychron_common.mk

#NOTE: disabling factory test also disables factory reset
OPT_DEFS += -UFACTORY_TEST_ENABLE

VPATH += $(TOP_DIR)/keyboards/keychron
