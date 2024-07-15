
# Find Python
py3 = import('python').find_installation('python3')

# Include directories for Python
#python3_inc_dir = py3.get_include_dir()
#python3_lib_dir = py3.get_library_dir()

# Print paths for debugging
#message('Python include directories: ' + python3_inc_dir)
#message('Python library directories: ' + python3_lib_dir)

# Add Pybind11 subproject
pybind11_dep = dependency('pybind11', fallback: ['pybind11', 'pybind11_dep'])

# Define the executable or library
executable('module',
  sources: ['embed_pybind.cpp'],
  dependencies: [pybind11_dep, py3.dependency()],
  install: true
)



common_src += files(['embed_python.cpp','embed_pybind.cpp'])
