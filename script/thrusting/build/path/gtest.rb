def use_gtest(cc)
  gtest_home = "#{ENV["HOME"]}/local/gtest/gtest-1.5.0"
  gtest_lib = [gtest_home, "lib"].join "/"
  gtest_include = [gtest_home, "include"].join "/"
  cc += " -Xcompiler -trigraphs "
  cc += " -I #{gtest_include}"
  cc += " -L #{gtest_lib}"
  cc += " -l gtest"

  thisdir = File.expand_path File.dirname __FILE__
  cc += " #{thisdir}/gtest_main.cu"
end
