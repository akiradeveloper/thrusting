THRUSTING = "thrusting"

def operator_parallel(code="")
"""
namespace #{THRUSTING} {
namespace op {
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
namespace op {
namespace tuple {
#{code}
}
}
}
"""
end


