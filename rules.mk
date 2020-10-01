OLED_DRIVER_ENABLE = yes   # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = no       # Disable keyboard RGB underglow
SPLIT_TRANSPORT = mirror   # Allow to have information sent on both sides
TAP_DANCE_ENABLE = yes     # Activate tap dance
UNICODEMAP_ENABLE = yes    # Enable unicode map
COMBO_ENABLE = yes 				 # Enable combos
NKRO_ENABLE = yes 				 # Enable NKRO: any number of key-presses at once
LTO_ENABLE = yes  				 # Enable Link Time Optimization

SRC += combos.c            # Source combos.c 

EXTRFLAGS += -flto         # Save space 

WPM_ENABLE = no     	     # Disable WPM measurement
MOUSEKEY_ENABLE = no       # Disable mouse keys
<<<<<<< HEAD
BACKLIGHT_ENABLE = no      # Disable keyboard backlight (not RGB)
=======
BACKLIGHT_ENABLE = no      # Enable keyboard backlight (not RGB)
>>>>>>> 5ec5132dfc9b3225970d5d628a5c5b8e853a3023
