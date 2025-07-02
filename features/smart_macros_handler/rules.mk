#this allows for an override
LINKFLAGS += -Wl,--wrap=dynamic_keymap_macro_set_buffer
#include the file too
SRC += features/smart_macros_handler/dynamic_keymap_macro_set_buffer_override.c