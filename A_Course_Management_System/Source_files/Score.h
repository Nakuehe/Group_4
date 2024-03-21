#include <string>
#include "LinkedList.h"
#include "Student.h"

// Each student has a list of score
struct Score{
   std::string id_student;
   std::string fullName;
   float mid_mark;
   float final_mark;
   float GPA; 
};
