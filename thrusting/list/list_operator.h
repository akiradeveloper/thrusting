#pragma once

template<typename A>
std::ostream &operator<<(std::ostream &os, const list<A> &a){
  std::stringstream ss;
  ss << "[";
  for(size_t i=0; i<a.length()-1; i++){
    ss << *(a.head()+i);
    ss << ", ";
  }
  ss << *(a.head()+a.length()-1);
  ss << "]";
  os << ss.str();
  return os;
}

bool operator==(const list<A> &with) const {
  if(length() != with.length()){ return false; }
  return thrust::equal(head(), head()+length(), with.head());
}

bool operator!=(const list<A> &with) const {
  return !( (*this) == with );
}

