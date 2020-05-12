#include <iostream>
#include <cstring>

using namespace std;

// Employee 클래스를 선언함
class Employee{

private:
  // char name[100]을 선언함
  // 이 변수에는 Employee의 이름을 저장함
  // 클래스 내 함수에서만 접근할 수 있도록, 
  // private으로 선언함
  char name[100];
 
public:
  
  // Employee 클래스의 생성자를 선언함
  // 생성자의 목적은 객체의 멤버 변수를 초기화해주는 것임 
  // 생성자는 name을 초기화해줌 
  Employee(char *name){
    
    // strcpy(this->name, name)을 통해서
    // name을 this->name에 복사함
    // this 포인터는 객체 자신을 가리키는 용도로 사용되는 포인터임
    strcpy(this->name, name);
  }
  
  // showYourName()을 선언함
  // const 함수 오버로딩은 해당 함수내에서 변수 값의 변경을 제한함
  // 함수 오버로딩은 매개변수의 형태가 다르면, 동일한 이름의 함수를 선언할 수 있는 것을 의미함
  void ShowYourName() const {
    cout << "name: " << name << '\n';
  }
 
};

// PermanentWorker 클래스는 Employee 클래스를 상속함
// 상속은 부모 클래스의 멤버 변수와 멤버 함수를 자식 클래스에서 활용하는 것을 목적으로 함 
class PermanentWorker : public Employee {

private:
  // salary라는 멤버 변수를 선언함
  // 이 변수는 PermanentWorker 클래스의 변수만 접근할 수 있도록
  // private으로 선언함 
  int salary;
public:
  // PermanentWorker 클래스의 생성자를 선언함
  // 단, 이 때 멤버 이니셜라이저를 활용해서, 부모 클래스의 멤버 변수를 초기화해줌
  // 부모 클래스의 멤버 변수(name)를 초기화해줘야 하는 이유는
  // 자식 클래스가 부모 클래스의 멤버 변수인 name을 그대로 활용하기 때문임
  PermanentWorker(char* name, int money) : Employee(name), salary(money){
  }
  
  // GetPay() 멤버 함수를 만들어줌
  // 이 함수는 salary값을 리턴하는 역할을 함 
  int GetPay() const{
    return salary;
  }
  
  // showSalaryInfo() 멤버 함수를 만들어줌
  // 이 함수는 showYourName()와 GetPay()를 호출함
  // showYourName()을 호출할 수 있는 이유는 Employee 클래스를 상속했으며,
  // showYourName()이 public으로 선언되었기 때문임
  // GetPay()는 같은 클래스의 멤버 함수 이므로 호출할 수 있음
  // 결과적으로 showSalaryInfo()가 실행되면
  // Employee의 이름과 salary가 출력됨 
  // 단, Employee의 이름은 Employee 클래스에, salary는 PermanentWorker 클래스에 선언되어 있음
  
  void ShowSalaryInfo() const{
    ShowYourName();
    cout << "salary: " << GetPay() << '\n';
  }

};

// TemporaryWorker 클래스는 마찬가지로 Employee 클래스를 상속함
class TemporaryWorker : public Employee {

private:
  // TemporaryWorker 클래스는 멤버변수 workTime과 payperHour를 가짐 
  // workTime은 근무 시간, payPerHour는 시간당 급여를 의미함 
  // 두 멤버 변수는 private으로 선언함 
  int workTime;
  int payPerHour;

public:
  // TemporaryWorker 클래스의 생성자를 선언함
  // 마찬가지로 멤버 이니셜라이저를 활용해서, 멤버 변수를 초기화함 
  // 여기서는 부모 클래스인 Employee의 멤버 변수인 name과 멤버 변수 workTime, payPerHour를 초기화함 
  TemporaryWorker(char* name, int pay) : Employee(name), workTime(0), payPerHour(pay){
  }
  
  // AddWorkTime() 멤버 함수를 선언함
  // 이 함수는 time값만큼 근무 시간을 더해줌 
  // workTime은 객체 생성 시 0으로 초기화됨
  // 따라서 workTime을 AddWorkTime 함수로 따로 더해줘야 함  
  void AddWorkTime(int time){
    workTime += time;
  }
  
  // GetPay() 멤버 함수를 선언함
  // 여기서는 TemporaryWorker 객체가 받아야 할 임금을 계산해줌
  // 임금은 workTime과 payPerHour의 곱으로 나타내짐 
  int GetPay() const{
    return workTime*payPerHour;
  }
  
  // ShowSalaryInfo() 멤버 함수를 선언함
  // 여기서는 부모 클래스의 멤버 함수인 ShowYourName()을 호출하고,
  // 클래스 내의 멤버 함수인 GetPay()를 호출함
  // 이렇듯, 부모 클래스의 멤버 함수는 계속해서 자식 클래스에서 활용할 수 있음 
  void ShowSalaryInfo() const{
    ShowYourName();
    cout << "salary: " << GetPay() << '\n';
  }
};


class SalesWorker : public PermanentWorker{

private:
  int salesResult;
  double bonusRatio;
  
public:
  SalesWorker(char* name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio){
  }
  
  void AddSalesResult(int value){
    salesResult += value;
  }
  
  int GetPay() const{
    return PermanentWorker::GetPay() + (int)(salesResult*bonusRatio);
  }
  
  void ShowSalaryInfo() const{
    ShowYourName();
    cout << "salary: " << GetPay() << '\n';
  }

}

class EmployeeHandler{

private:
  Employee* empList[50];
  int empNum;
  
public:
  EmployeeHandler() : empNum(0){
  }
  
  void AddEmployee(Employee* emp){
    empList[empNum++] = emp;
  }
  
  void ShowAllSalaryInfo() const{
    
    for(int i=0; i<empNum; i++){
      empList[i]-> ShowSalaryInfo();
    }
  }
  
  void ShowTotalSalary() const{
    
    int sum = 0; 
    
    for(int i=0; i<empNum; i++){
      sum += empList[i]->GetPay();
    }
    cout << "salary sum: " << sum << '\n';
  }
  
  ~EmployeeHandler(){
    for(int i=0; i<empNum; i++){
        delete empList[i];
    }
  }
};


int main(){

  EmployeeHandler handler;
  
  handler.AddEmployee(new PermanentWorker("KIM", 1000));
  handler.AddEmployee(new PermanentWorker("LEE", 1500));
  handler.AddEmployee(new PermanentWorker("JUN", 2000));

  TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
  alba->AddWorkTime(5);
  handler.AddEmployee(alba);
  
  SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
  seller->AddSalesResult(7000);
  handler.AddEmployee(seller);
  
  handler.ShowAllSalaryInfo();
  
  handler.ShowTotalSalary();

  return 0; 
}

