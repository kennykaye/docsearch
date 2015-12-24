def FlagsForFile(filename, **kwargs):
  flags = [
    '-g',
    '-Wall',
    '-Wextra',
    '-Werror',
    '-pedantic',
    '-ansi',
    '-std=c++11',
    '-x',
    'c++',
    '-I./src',
    '-I./include',
    '-I./include/Catch/single_include',
    '-isystem',
    '../llvm/include',
    '-isystem',
    '../llvm/tools/clang/include'
  ]

  return {
    'flags':    flags,
    'do_cache': True
  }
