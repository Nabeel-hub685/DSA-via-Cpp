#include<iostream>
#include<cstdlib>
using namespace std;

struct Student{
	int SID;
	Student* SNext;
};	

struct Course{
	int CID;
	Course* CNext;
	Student* StuStart;
	};

Course* courseHead=NULL;

 void AddCourse(){
 	
 	int set=1;
 	while (set==1){
	 
 	Course* ptr= (Course*) malloc(sizeof(Course));
 	cout<<"Enter the course ID: "<<endl;
 	cin>>ptr->CID;
 	ptr->CNext=NULL;
 	ptr->StuStart=NULL;
 	
 	if(courseHead==NULL){
 		courseHead=ptr;
	 }
	else {
		Course* current=courseHead;
		while(current->CNext!=NULL){
			current=current->CNext;
		}
		current->CNext=ptr;
	}
	cout<<"enter 1 if you want to insert another course!"<<endl;
	cin>>set;
      }
 }

 
void AddStudentInCourse(){
	//cout<<"Add stuent function was called"<<endl;
    
int sub;
	cout<<"Enter course ID in which a student has to add!"<<endl;
	cin>>sub;
	Course* current=courseHead;
	while(current!=NULL){
		if(current->CID==sub){
			break;
		}
		current=current->CNext;
		
	}
	if(current==NULL){
		cout<<"Sorry the university is not offering this course"<<endl<<endl;
		return;
	}
	
	Student* ptr=(Student*) malloc(sizeof(Student));
	cout<<"Enter the ID of Student : "<<endl;
	cin>>ptr->SID;
	ptr->SNext=NULL;
	
	if (current->StuStart==NULL){
		current->StuStart=ptr;
	}
	 else{
	 	Student* Scurrent=current->StuStart;
	 	while(Scurrent->SNext!=NULL){
	 		Scurrent=Scurrent->SNext;
		 }
		 Scurrent->SNext=ptr;
	 }
}


void deleteCourse(int todelete){
    /*if (courseHead==NULL){
        cout<<"The course list is already empty!"<<endl;
        return;
    }*/
    
    if(courseHead->CID==todelete){
        if(courseHead->CNext==NULL){
            free(courseHead);
            courseHead=NULL;
            cout<<"The given course has been deleted!"<<endl<<endl;
        }
        else{
            Course* current=courseHead;
            courseHead=courseHead->CNext;
            free(current);
            cout<<"The given course has been deleted!"<<endl<<endl;
        }
    }
     else{
         Course* prev=courseHead;
         Course* current=courseHead->CNext;
         while(current!=NULL){
             if (current->CID==todelete){
                 prev->CNext=current->CNext;
                 free(current);
                 cout<<"The given course has been deleted!"<<endl<<endl;
                 return;
             }
             prev=prev->CNext;
             current=current->CNext;
         }
        cout<<"The given course "<<todelete<<" is already not available!"<<endl<<endl;  
     }
}

void searchCourse(int toSearch){
    Course* current=courseHead;
    while(current!=NULL){
        if(current->CID==toSearch){
            cout<<"Yes! The course "<<toSearch<<" is available!"<<endl<<endl;
            return;
        }
        current=current->CNext;
    }
    cout<<"Sorry! the given Course is not available right now!"<<endl<<endl;
}

void printCourseList(){
    if (courseHead==NULL){
        cout<<"The course list is already empty!"<<endl;
        cout<<"No course available right now!"<<endl<<endl;
        return;
    }
    else{
        cout<<endl;
        cout<<"The courses available right now are given below!"<<endl;
        Course* current=courseHead;
        int i=1;
        while(current!=NULL){
            cout<<i<<") "<<"Course "<<current->CID<<endl;
            current=current->CNext;
            i++;
        }
        cout<<endl;
        
    }
}

void searchStudentInCourse(int student, int course){
    Course* current=courseHead;
    while(current!=NULL){
        if(current->CID==course){
            break;
        }
        current=current->CNext;
        
    }
    if(current==NULL){
        cout<<"The given course is not available! so obviously no student as well"<<endl<<endl;
        return;
    }
    
    Student* Scurrent=current->StuStart;
    if (Scurrent==NULL){
        cout<<"No student opted this course "<<course<<" so far! "<<endl<<endl;
        return;
    }
    while(Scurrent!=NULL){
        if(Scurrent->SID==student){
            cout<<"Yes! the given student having ID "<<student<<" has opted that course "<<course<<endl<<endl;
            return;
        }
        Scurrent=Scurrent->SNext;
    }
    cout<<"No! the given student didn't opt that course "<<course<<endl<<endl;
}

void deleteStudent(int student, int course){
    Course* current=courseHead;
    while(current!=NULL){
        if(current->CID==course){
            break;
        }
        current=current->CNext;
    }
    if(current==NULL){
        cout<<"the given course is not present in the course list!"<<endl<<endl;
        return;
    }
    Student* Scurrent=current->StuStart;
    if(Scurrent==NULL){
        cout<<"there is no student in that course "<<course<<" so far!"<<endl<<endl;
        return;
    }
    //cout<<"The university has no course availabe right now! so no student as well at all"<<endl<<endl;
		    
    while(Scurrent!=NULL){
        if(Scurrent->SID==student){
            if(current->StuStart->SID==student){
                if(current->StuStart->SNext==NULL){
                   free(Scurrent);
                    current->StuStart=NULL;
                    cout<<"The given student has been removed from the course!"<<endl<<endl;
                    return;
                }
                else{
               current->StuStart=Scurrent->SNext;
                free(Scurrent);
                    cout<<"The given student has been removed from the course!"<<endl<<endl;
                    return;
                }
            }
            else{
                Student* prev=current->StuStart;
                while(prev->SNext!=Scurrent){
                    prev=prev->SNext;
                }
                prev->SNext=Scurrent->SNext;
                free(Scurrent);
                cout<<"The given student has been removed from the course!"<<endl<<endl;
                    return;
            }
        }
        Scurrent=Scurrent->SNext;
    }
    cout<<"The given student is already not present in that course!"<<endl<<endl;
}


void printStudentList(int course){
    if(courseHead==NULL){
        cout<<"The university is not offering any course right now , so no student list!"<<endl<<endl;
        return;
    }
    Course* current= courseHead;
    while(current!=NULL){
        if(current->CID==course){
            break;
        }
        current=current->CNext;
    }
    if(current==NULL){
        cout<<"The given course is not present in the course list ! so obviously no student list!"<<endl<<endl;
        return;
    }
    Student* Scurrent= current->StuStart;
    if(Scurrent==NULL){
        cout<<"No student opted that course so far! The student list of this course is empty!"<<endl<<endl;
        return;
    }
    int i=1;
    cout<<endl<<"The students list of the given course "<<course<<" is given below"<<endl;
    while(Scurrent!=NULL){
        cout<<i<<") Student with ID: "<<Scurrent->SID<<endl;
        Scurrent=Scurrent->SNext;
        i++;
    }
    cout<<endl;
}


void deleteStudentFromAllCourses(int student){
    
    Course* current=courseHead;
    Student* Scurrent=current->StuStart;
  while(current!=NULL){
      Scurrent=current->StuStart;
      while(Scurrent!=NULL){
          if(Scurrent->SID==student){
              if(current->StuStart->SID==student){
                  if(current->StuStart->SNext==NULL){
                      free(Scurrent);
                      current->StuStart=NULL;
                      break;
                       }
                   else{
                      current->StuStart=Scurrent->SNext;
                      free(Scurrent);
                      break;
                       }
                  }
          else{
                Student* prev=current->StuStart;
                while(prev->SNext!=Scurrent){
                    prev=prev->SNext;
                }
                prev->SNext=Scurrent->SNext;
                free(Scurrent);
                break;
            }
        }
         Scurrent=Scurrent->SNext;
    }
    current=current->CNext;
}
cout<<"The given student of ID "<<student<<" has been removed from all the courses!"<<endl<<endl;
}


void printCoursesOfStudent(int student){
    
    Course* current=courseHead;
    Student* Scurrent=current->StuStart;
    int i=0;
  while(current!=NULL){
      Scurrent=current->StuStart;
      while(Scurrent!=NULL){
          if(Scurrent->SID==student){
              i++;
              break;
          }
          Scurrent=Scurrent->SNext;
      }
      if(i==1){
          cout<<endl<<"The list of courses in which the student having ID "<<student<<" is given below!"<<endl;
      }
      if(Scurrent!=NULL){
          cout<<i<<") Course ID: "<<current->CID<<endl;
      }
      current=current->CNext;
  }
    if(i==0){
        cout<<endl<<"This student has not opted any course so far! no courses to show for this student!"<<endl;
    }
    cout<<endl;
}
      
      
int main(){
	int check;
	cout<<"Enter 1 to insert a course! "<<endl<<"Enter 2 to delete a course! "<<endl<<"Enter 3 to Search a course!"<<endl<<"Enter 4 to print the course list! "<<endl<<"Enter 5 to add a student to a course"<<endl<<"Enter 6 to delete a student from the course! "<<endl<<"Enter 7 to delete a student from all the courses"<<endl<<"Enter 8 to Search a student"<<endl<<"Enter 9 to print list of students in a course"<<endl<<"Enter 10 to print the list of courses in which a student has enrolled: "<<endl<<"Enter 11 to exit the code! "<<endl;
	cin>>check;
	while (check!=11){
	    
		if (check==1){
			AddCourse();
		}
	    
		else if(check ==2){
		    if(courseHead!=NULL){
		    int todelete;
		    cout<<"Enter the course ID you want to delete!"<<endl;
		    cin>>todelete;
			 deleteCourse(todelete);
		    }
		    else{
		        cout<<"The course list is empty at the moment!"<<endl<<endl;
		    }
		}
	    
		else if(check==3){
		    if(courseHead!=NULL){
			    int toSearch;
		    cout<<"Enter course ID of the course to search!"<<endl;
		    cin>>toSearch;
		    searchCourse(toSearch);
		    }
		    else{
		        cout<<"Sorry! we have no course available at the moment!"<<endl<<endl;
		    }
		}
	    
		else if(check==4){
		    printCourseList();
		}
	    
		else if(check==5){
			AddStudentInCourse();
		}
	    
		else if(check==6){
		    if(courseHead!=NULL){
		    int student;
		    int course;
		    cout<<"Enter student ID you want to delete: "<<endl;
		    cin>>student;
		    cout<<"Enter course ID from which you want to delete that student: "<<endl;
		    cin>>course;
			 deleteStudent(student,course);
		    }
		    else{
		        cout<<"The university has no course availabe right now! so no student as well at all"<<endl<<endl;
		    }
		}
	    
		else if(check==7){
		    if (courseHead!=NULL){
		        int student;
			 cout<<"Enter the student ID whom we have to remove from all the courses"<<endl;
		   cin>>student;
		    deleteStudentFromAllCourses(student);
		    }
		    else {
		        cout<<"the uni is not offering any course right now! so students no courses"<<endl<<endl;
		    }
		}
	    
		else if(check==8){
		    if(courseHead!=NULL){
		    int student;
		    cout<<"Enter Student ID to search!"<<endl;
		    cin>>student;
		    int course;
		    cout<<"Enter course ID in which we have to search the student!"<<endl;
		    cin>>course;
		    searchStudentInCourse(student,course);
		    }
		    else{
		        cout<<"The university has no course availabe right now! so no student as well at all"<<endl<<endl;
		    }
		}
	    
		else if(check==9){
		    int course;
		    cout<<"Enter the course ID to print the list of students who opted that course"<<endl;
		    cin>>course;
			 printStudentList(course);
		}
	    
	 else if(check==10){
	     if(courseHead!=NULL){
	     int student;
	     cout<<"Enter Student ID to check the list of courses in which he is enrolled: "<<endl;
	     cin>>student;
	        printCoursesOfStudent(student);
	     }
	     else{
		        cout<<"The university has no course availabe right now! so no courses! no students at all"<<endl<<endl;
		    }
	 }
	    
	    else{
	        cout<<"Enter valied choice within the givem options! or enter 11 to exit the code, Thank you!"<<endl<<endl;
	    }
	    
	    cout<<"Enter 1 to insert a course! "<<endl<<"Enter 2 to delete a course! "<<endl<<"Enter 3 to Search a course!"<<endl<<"Enter 4 to print the course list! "<<endl<<"Enter 5 to add a student to a course"<<endl<<"Enter 6 to delete a student from the course! "<<endl<<"Enter 7 to delete a student from all the courses"<<endl<<"Enter 8 to Search a student"<<endl<<"Enter 9 to print list of students in a course"<<endl<<"Enter 10 to print the list of courses in which a student has enrolled: "<<endl<<"Enter 11 to exit the code"<<endl;
	cin>>check;
   	}
    cout<<"We have exit the code now!"<<endl;
}