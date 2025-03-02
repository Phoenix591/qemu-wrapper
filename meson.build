project('Qemu-wrapper', 'c',
	version: '1.0',
	meson_version: '>=0.60.0',  # Minimum Meson version (arbitrary, adjust as needed)
	default_options: ['buildtype=debugoptimized', 'c_std=c23'])  # Optional: sets C standard
# Define the CPU variable (configurable via meson -Dcpu=...)
cpu = get_option('cpu')
if cpu == ''
	cpu = 'cortex-a72'  # Default value if not specified
endif
# Common source file
src = ['qemu-wrapper.c']
# First executable: qemu-aarch64-wrapper
executable('qemu-aarch64-wrapper',
	sources: src,
	c_args: ['-DCPU="' + cpu + '"', '-DARCH="aarch64"'],
	install: true)
# Second executable: qemu-arm-wrapper
executable('qemu-arm-wrapper',
	sources: src,
	c_args: ['-DCPU="' + cpu + '"', '-DARCH="arm"'],
	install: true)
