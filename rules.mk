MIDI_ENABLE      = no   # disable midi to keep size down
COMMAND_ENABLE   = no   # Disable shift combination, which conflicts with shift-parens
TAP_DANCE_ENABLE = yes  # Enable tap dance

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
