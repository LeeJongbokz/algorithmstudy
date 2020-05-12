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

// SalesWorker 클래스를 만들고 PermanentWorker 클래스를 상속한다
class SalesWorker : public PermanentWorker{

private:
  // SalesWorker 클래스에는 2개의 멤버 변수가 존재한다
  // 첫번째는 salesResult 멤버 변수
  // 두번째는 bonusRatio 멤버 변수 이다 
  // 그리고 두 멤버 변수의 곱은 SaleWorker에게 지급되는 영업 수당을 의미한다. 
  int salesResult;
  double bonusRatio;
  
public:
  // SalesWorker 클래스의 생성자를 선언한다
  // 생성자는 name, money, saleResult, bonusRatio 4개의 멤버 변수를 초기화한다
  // 이 중 name, money 이 2개의 멤버 변수는 PermanentWorker 클래스에서 상속한 멤버 변수이며,
  // salesResult 와 bonusRatio는 SalesWorker 클래스의 멤버 변수이다. 
  SalesWorker(char* name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio){
  }
  
  // AddSalesResult() 멤버 함수를 선언한다
  // 이 함수는 value라는 매개변수를 활용해, salesResult 멤버 변수에 그 값을 더해준다. 
  void AddSalesResult(int value){
    salesResult += value;
  }
  
  // GetPay() 멤버 함수를 선언한다.
  // 이 함수에서는 부모 클래스인 PermanentWorker 클래스의 GetPay() 멤버 함수를 호출하고,
  // 그 리턴 값(기본 수당)에 영업 수당인 saleResult*bonusRatio를 더해준다. 
  int GetPay() const{
    return PermanentWorker::GetPay() + (int)(salesResult*bonusRatio);
  }
  
  // ShowSalaryInfo() 멤버 함수를 선언한다
  // ShowSalaryInfo() 멤버 함수는 부모 클래스인 ShowYourName() 멤버 함수를 호출하고,
  // SalesWorker 클래스의 멤버 함수인 GetPay()를 호출한다. 
  // 그 결과 SalesWorker 객체의 이름과 급여가 출력된다. 
  void ShowSalaryInfo() const{
    ShowYourName();
    cout << "salary: " << GetPay() << '\n';
  }

}

// EmployeeHandler 클래스를 만든다

// 멤버함수 ShowAllSalaryInfo()와 ShowTotalSalary()를 정의한다.  
// ShowAllSalaryInfo()는 Employee 객체들의 각각의 급여를 출력할 수 있는 멤버 함수와
// ShowTotalSalary()는 Employee 객체들의 전체 급여를 합해서 출력할 수 있는 멤버 함수이다. 
class EmployeeHandler{

private:
  Employee* empList[50];
  int empNum;
  
public:
  // EmployeeHandler 클래스의 생성자를 정의한다.
  // 이 때, 멤버 이니셜라이저를 활용해서 멤버 변수인 empNum을 0으로 초기화한다. 
  EmployeeHandler() : empNum(0){
  }
  
  // AddEmployee() 멤버 함수를 활용해서 전체 Employee 객체들을 배열에 저장한다
  void AddEmployee(Employee* emp){
    empList[empNum++] = emp;
  }
  
  // ShowAllSalaryInfo() 멤버 함수는 Employee 객체들의 각각의 급여를 출력할 수 있다. 
  void ShowAllSalaryInfo() const{
    
    for(int i=0; i<empNum; i++){
      empList[i]-> ShowSalaryInfo();
    }
  }
  
  // showTotalSalary() 멤버 함수는 Employee 객체들의 전체 급여를 합해서 출력한다. 
  void ShowTotalSalary() const{
    
    int sum = 0; 
    
    for(int i=0; i<empNum; i++){
      sum += empList[i]->GetPay();
    }
    cout << "salary sum: " << sum << '\n';
  }
  
  // EmployeeHandler의 소멸자를 정의한다.
  // 소멸자를 정의해주는 이유는 empList에 저장된 객체들을 삭제해주기 위함이다. 
  ~EmployeeHandler(){
    for(int i=0; i<empNum; i++){
        delete empList[i];
    }
  }
};


int main(){

  // EmployeeHandler 클래스의 객체인 handler를 선언한다.
  EmployeeHandler handler;
  
  // handler 객체에 새로운 PermanentWorker 객체를 추가한다
  // 이 때, new를 통해서 객체를 동적 메모리 할당을 한다 
  handler.AddEmployee(new PermanentWorker("KIM", 1000));
  handler.AddEmployee(new PermanentWorker("LEE", 1500));
  handler.AddEmployee(new PermanentWorker("JUN", 2000));

  // TempararyWorker 클래스의 객체인 alba를 선언한다.
  // 이 때, new를 통해서 객체를 동적 메모리 할당을 한다.
  // TemporaryWorker 클래스의 멤버 변수인 name과 pay를 초기화한다 
  TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
  
  // alba 객체의 AddWorkTime 멤버 함수를 통해서 
  // 멤버 변수인 workTime에 5를 더해준다.
  alba->AddWorkTime(5);
  
  // handler 객체에 alba 객체를 추가한다. 
  handler.AddEmployee(alba);
  
  // SalesWorker 클래스의 객체인 seller를 선언한다
  // 이 때, new를 통해서 객체를 동적 메모리 할당을 한다
  // 또한, 멤버 변수인 name, salary, bonusRatio를 초기화한다 
  SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
  
  // seller 객체의 AddSalesResult 멤버 함수를 실행해서
  // saleResult 멤버 변수에 7000을 더해준다.
  seller->AddSalesResult(7000);
  
  // handler 객체에 seller 객체를 추가한다. 
  handler.AddEmployee(seller);
  
  // handler 객체의 ShowAllSalaryInfo 함수를 통해서
  // 각 객체들의 showSalaryInfo 멤버 함수를 실행한다
  // 이것이 가능한 이유는    
  // PermanentWorker 클래스, TemporaryWorker 클래스, SalesWorker 클래스 각각에
  // showSalaryInfo() 멤버 함수를 선언했기 때문이다. 
  // 이 때, 중요한 점은 SalesWorker 클래스에 선언된 
  // ShowSalaryInfo()는 부모 클래스인 PermanentWorker 클래스에 선언된 ShowSalaryInfo()를 
  // 오버라이딩한다는 점이다. 
  handler.ShowAllSalaryInfo();
  
  // handler 객체의 showTotalSalary()를 실행함
  // 이를 통해서 handler 객체에 저장된 모든 객체들의 salary를 합산한 값을
  // 출력할 수 있음
  handler.ShowTotalSalary();
          
  return 0; 
}             

