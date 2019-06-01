#pragma once

template <typename Base, typename Member>
class BaseMemberPair : private Base
{
private:
  Member member; 

public:
  BaseMemberPair(Base const& b, Member const& m)
    : Base(b)
    , member(m)
  {
  }

  Base const& first() const { return (Base const&)*this; } 
  Base& first() { return (Base&)*this; }

  Member const& second() const { return this->member; } 
  Member& second() { return this->member; } 
};
