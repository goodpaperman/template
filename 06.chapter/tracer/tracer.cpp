// tracer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "sort_tracer.h" 
#include <algorithm> 

int _tmain(int argc, _TCHAR* argv[])
{
  sort_tracer input[] = { 7, 3, 5, 6, 4, 2, 0, 1, 9, 8 }; 
  for(int i=0; i<10; ++ i)
    std::cerr << input[i].val() << ' '; 

  std::cerr << std::endl; 
  long created_at_start = sort_tracer::creations(); 
  long max_live_at_start = sort_tracer::max_live(); 
  long assigned_at_start = sort_tracer::assignments(); 
  long compared_at_start = sort_tracer::comparisons(); 

  std::cerr << "---[start std::sort()]---\n"; 
  std::sort<>(input, input + 10); 
  std::cerr << "---[end std::sort()]---\n"; 

  for(int i=0; i<10; ++i)
    std::cerr << input[i].val() << ' '; 

  std::cerr << "\n\n"
    << "std::sort() of 10 sort_tracer's was performed by: \n"
    << sort_tracer::creations() - created_at_start
    << " temporary tracers\nup to " 
    << sort_tracer::max_live() 
    << " tracers at the same time ("
    << max_live_at_start << " before)\n"
    << sort_tracer::assignments() - assigned_at_start 
    << " assignments\n" 
    << sort_tracer::comparisons() - compared_at_start
    << " comparisons\n\n"; 

	return 0;
}

