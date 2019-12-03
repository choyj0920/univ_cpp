	#pragma once
	#include<iostream>
	using namespace std;
	class Student
	{
	private:
		
	public:
		string name;

		int score;
		Student() :Student("", 0) {

		}
		Student(string name, int score) :name(name), score(score) {

		}
		Student(string name) :Student(name, 0) {

		}
		friend ostream& operator<<(ostream& out, Student& copy);
		friend ostream& operator<<(ostream& out, const  Student* copy);
		
		bool operator==(string check){
			return this->name == check;
		}
		bool operator==(Student& check) {
			return (this->name == check.name && this->score == check.score);
		}
		bool operator<(const Student& check) {
			return this->score < check.score;
		}
		bool operator>(const Student& check) const {
			return this->score > check.score;
		}
	};

