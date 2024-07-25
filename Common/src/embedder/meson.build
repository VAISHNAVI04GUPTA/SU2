common_src += files(['embed_python.cpp','embed_pybind.cpp'])

# Define the executable or library
executable('module',
  sources: ['embed_pybind.cpp'],
  include_directories: include_dirs,
  dependencies: su2_deps + [python_dep],
  cpp_args: cpp_args,
  link_args: link_args,
  install: true
)
