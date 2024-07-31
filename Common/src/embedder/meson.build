common_src += files(['embed_python.cpp','embed_pybind.cpp'])


# Define the source files

python.extension_module('calc',
    'embed_pybind.cpp',
    install: true,
    dependencies : su2_deps+[python_dep],
    include_directories: include_dirs,
    cpp_args: cpp_args
)




#calc = executable('calc',sources,include_directories: include_dirs,dependencies: su2_deps+[python_dep],cpp_args: cpp_args,link_args:link_args,install: true)
# Set the output directory for the library
# Meson does not have a direct equivalent of CMake's LIBRARY_OUTPUT_DIRECTORY,
# but you can control the output directory via the build options or configure the install directory if needed.


