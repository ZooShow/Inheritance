#include <iostream>
#include <string>
// раннее связывание - сопоставление функции во время компиляции, позднее  связование - во время исполнение
using namespace std;

enum SEX {
    U, M, F
};

class Human {
private:
    int age;
    SEX sex;
public:
    Human(int age, SEX sex) {
        this->age = age;
        this->sex = sex;
    };

    int getAge() const {
        return age;
    }

    SEX getSex() const {
        return sex;
    };

    void setAge(int age) {
        this->age = age;
    }

    void setSex(SEX sex) {
        this->sex = sex;
    }
};

class Student : public Human {
    string numberOfZachetka;
public:
    Student(int age, SEX sex, const string &numberOfZachetka) : Human(age, sex) {
        this->numberOfZachetka = numberOfZachetka;
    }

    string getNumberOfZachetka() const {
        return numberOfZachetka;
    }

    SEX getSex() const {
        return Human::getSex();
    }

    int getAge() const {
        return Human::getAge();
    }

    void setSex(SEX sex) {
        Human::setSex(sex);
    }

    void setNumberOfZachetka(const string &numberOfZachetka) {
        this->numberOfZachetka = numberOfZachetka;
    }

    void setAge(int age) {
        Human::setAge(age);
    }

    ~Student();
};

class GoodStudent : public Student {
    int countOfGoodMarks;
public:
    GoodStudent(int age, SEX sex, const string &numberOfZachetka, int countOfGoodMarks) : Student(age, sex,
                                                                                                  numberOfZachetka) {
        this->countOfGoodMarks = countOfGoodMarks;
    };

    int getCountOfGoodMarks() const {
        return countOfGoodMarks;
    }

    int getAge (){
        return Student::getAge();
    }

    SEX getSex (){
        return Student::getSex();
    }

    string getNumberOfZachetka() const {
        return Student::getNumberOfZachetka();
    }

    void setCountOfGoodMarks(int countOfGoodMarks) {
        this->countOfGoodMarks = countOfGoodMarks;
    }

    void setSex(SEX sex){
        Student::setSex(sex);
    }

    void setAge(int age){
        Student::setAge(age);
    }

    void setNumberOfZachetka(string NumberOfZachetka){
        Student::setNumberOfZachetka(NumberOfZachetka);
    }

};

class BadStudent : public Student {
    int countOfMissingLessons;
public:

    BadStudent(int age, SEX sex, const string &numberOfZachetka, int countOfMissingLessons) : Student(age, sex,
                                                                                                      numberOfZachetka) {
        this->countOfMissingLessons = countOfMissingLessons;
    }

    int getCountOfMissingLessons() const {
        return countOfMissingLessons;
    }

    int getAge (){
        return Student::getAge();
    }

    SEX getSex (){
        return Student::getSex();
    }

    string getNumberOfZachetka() const {
        return Student::getNumberOfZachetka();
    }


    void setCountOfMissingLessons(int countOfMissingLessons) {
        this->countOfMissingLessons = countOfMissingLessons;
    }

    void setSex(SEX sex){
        Student::setSex(sex);
    }

    void setAge(int age){
        Student::setAge(age);
    }

    void setNumberOfZachetka(string NumberOfZachetka){
        Student::setNumberOfZachetka(NumberOfZachetka);
    }
};

class Magistrant : public GoodStudent, public BadStudent {
    string dateOfEndingBakalavriat;
public:
    Magistrant(int age, SEX sex, string numberOfZachetka, int countOfGoodMarks, int countOfMissingLessons, string dateOfEndingBakalavriat)
            : GoodStudent(age, sex, numberOfZachetka, countOfGoodMarks),
              BadStudent(age, sex, numberOfZachetka, countOfMissingLessons),
              dateOfEndingBakalavriat(dateOfEndingBakalavriat) {}

    string getDateOfEndingBakalavriat() const {
        return dateOfEndingBakalavriat;
    }

    int getAge (){
        return GoodStudent::getAge();
    }

    SEX getSex (){
        return GoodStudent::getSex();
    }

    string getNumberOfZachetka() const {
        return GoodStudent::getNumberOfZachetka();
    }


    void setDateOfEndingBakalavriat(const string &dateOfEndingBakalavriat) {
        this->dateOfEndingBakalavriat = dateOfEndingBakalavriat;
    }

    int getCountOfMissingLessons() {
        return BadStudent::getCountOfMissingLessons();
    }

    string getDateOfEndingBakalavriat() {
        return dateOfEndingBakalavriat;
    }
};


int main() {
    Human oleg(24, SEX::U);
    Student irishka(25, SEX::F, "asdasdads");
    Magistrant kolya(23, SEX::M, "123", 2, 1, "123123");
//    cout << kolya.GoodStudent::getAge() << endl;
//    cout << kolya.GoodStudent::getSex() << endl;
//    cout << kolya.BadStudent::getNumberOfZachetka() << endl;
//    cout << kolya.GoodStudent::getCountOfGoodMarks() << endl;
//    cout << kolya.getDateOfEndingBakalavriat();
    irishka.setAge(23);
    cout << irishka.getAge();
    return 0;

}
