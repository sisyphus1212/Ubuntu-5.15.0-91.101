human_arch	= 32 bit x86
build_arch	= i386
header_arch	= $(build_arch)
defconfig	= defconfig
flavours        = generic
build_image	= bzImage
kernel_file	= arch/$(build_arch)/boot/bzImage
install_file	= vmlinuz
vdso		= vdso_install
no_dumpfile	= true
do_flavour_image_package = false
do_tools	= false
do_tools_common	= false
do_extras_package = false
do_source_package = false
do_doc_package	= false
do_flavour_header_package = false
do_common_headers_indep = false
