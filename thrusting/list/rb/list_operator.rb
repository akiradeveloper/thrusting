require ["thrusting/rb", "namespace"].join "/"

def code()
"""
template<typename A>
std::ostream &operator<<(std::ostream &os, const list<A> &a){
  std::stringstream ss;
  ss << \"[\";
  for(size_t i=0; i<a.length()-1; i++){
    ss << *(a.head()+i);
    ss << \", \";
  }
  ss << *(a.head()+a.length()-1);
  ss << \"]\";
  os << ss.str();
  return os;
}

template<typename A>
bool operator==(const List<A> &xs, const list<A> &ys){
  if(xs.length() != ys.length()){ return false; }
  return thrust::equal(xs.head(), xs.head()+xs.length(), ys.head());
}

template<typename A>
bool operator!=(const List<A> &xs, const list<A> &ys){
  return !( xs == ys );
}
"""
end

def all()
"""
#pragma once
#{operator_list(code())}
"""
end

if __FILE__ ==$0
  $stdout << all()
end
