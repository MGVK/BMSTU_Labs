#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

string FILE_NAME = "rk.students";


class Student{
private:
	string name="";
	int* points = new int[3];
	int pointsSum=0;
	void calcSum(){
		pointsSum = points[0]+points[1]+points[2];
	}
public:
	Student(string name, int a,int b,int c){
		this->name = name;
		points[0] = a;
		points[1] = b;
		points[2] = c;
		calcSum();
		}
		
	int* getPoints(){
		return points;
		}
	string getName(){
		return name;
		}
		
	int getPointsSum(){
		return pointsSum;
		}
	};
	
	vector<Student> students;
	
void putInFile(int count){
	fstream file(FILE_NAME,ios::out);
	for(int i=0;i<count;i++){
		file<<students.at(i).getName()<<" "
		<<students.at(i).getPoints()[0]<<" "
		<<students.at(i).getPoints()[1]<<" "
		<<students.at(i).getPoints()[2]<<"\n";
		}
	file.close();
	}
	
	
void inputStudents(int count){
	for(int i=0;i<count;i++){
		cout<<"Введите имя и баллы\n";
					
		string name;
		int a,b,c;
		cin>>name>>a>>b>>c;
		Student *s = new Student(name,a,b,c); 
		students.push_back(*s);
		}
	}
	
Student getStudentWithMaxPoints(int count){
	int max=0,index=0;
	for(int i=0;i<count;i++){
		students.at(i).getPointsSum()>max?max = students.at(index=i).getPointsSum():false;
		}
		
	return students.at(index);
	}
	
void printNameOfBest(int count){
	Student best = getStudentWithMaxPoints(count);
	cout<<"Лучшим по набранным баллам является: "
	<<best.getName()<<" "
	<<"(сумма баллов = "<<best.getPointsSum()<<")\n";
	}
	
	
int inputCount(){
	cout<<"Введите количество: \n";
	int count;
	cin>>count;
	return count;
	}
	
int main(int argc, char *argv[]){
	int count = inputCount();
	inputStudents(count);
	putInFile(count);
	printNameOfBest(count);
	
	return 0;
}
