#pragma once

template <typename T>
class ObjectCounter
{
protected:
  ObjectCounter(void)
  {
    ++ count; 
  }

  ObjectCounter(ObjectCounter<T> const&)
  {
    ++ count; 
  }

  ~ObjectCounter(void)
  {
    -- count; 
  }

public:
  static size_t live()
  {
    return count; 
  }


private:
  static size_t count; 
};
