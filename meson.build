project(
  'qdesktop-creator',
  'cpp',
  default_options: ['cpp_std=c++17'],
)

gtkmm_dep = dependency('gtkmm-4.0')

executable(
  'qdesktop-creator',
  'src/main.cc',
  'src/window.cc',
  dependencies: gtkmm_dep,
)