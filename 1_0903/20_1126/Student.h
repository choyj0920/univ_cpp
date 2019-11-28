	#pragma once
	#include<iostream>
	using namespace std;
	class Student
	{
	private:
		string name;
		int score;
	public:
		Student() :Student("", 0) {

		}
		Student(string name, int score) :name(name), score(score) {

		}
		Student(string name) :Student(name, 0) {

		}
		friend ostream& operator<<(ostream& out, Student& copy);
		
		bool operator==(string check){
			return this->name == check;
		}
		bool operator==(Student& check) {
			return (this->name == check.name && this->score == check.score);
		}
	};

