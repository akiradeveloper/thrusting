thisdir = File.dirname(__FILE__)
require [thisdir, "def_compile"].join "/"

GTEST_NAME = "all.test"
def compile_gtest(tests)
  system "#{TESTCC} -o #{GTEST_NAME} test_all.cu #{tests.join(" ")}"
end

if __FILE__ == $0
  make_gtest(ARGV)
  run(GTEST_NAME)
end
