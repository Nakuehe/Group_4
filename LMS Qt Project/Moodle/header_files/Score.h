#include <string>
#include "LinkedList.h"

// Each student has a list of score
struct Score{
   std::string id_student;
   std::string fullName;
   std::string courseID;
   std::string courseName;
   float mid_mark{-1};
   float final_mark{-1};
   float other_mark{-1};
   float total_mark{-1};
   float GPA{-1}; 

   //build constructor
   Score(){}
   Score(std::string id_student, std::string fullName, std::string courseID, std::string courseName, float mid_mark, float final_mark, float other_mark, float GPA)
   : id_student(id_student), fullName(fullName), courseID(courseID), courseName(courseName), mid_mark(mid_mark), final_mark(final_mark), other_mark(other_mark), GPA(GPA) {}
   
};
float ReadFloat(std::string number);
