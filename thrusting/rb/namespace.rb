THRUSTING = "thrusting"

def operator_parallel(code="")
"""
namespace #{THRUSTING} {
namespace operator {
namespace parallel {
#{code}
}
}
}
"""
end

def operator_tuple(code="")
"""
namespace #{THRUSTING} {
namespace operator {
namespace tuple {
#{code}
}
}
}
"""
end


