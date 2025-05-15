#include<iostream>
#include<vector>

using namespace std;

class Schedule {
  public:
    Schedule(string name) {
      this->name = name;
    };
    void addTask(char* time){
      list.push_back(time);
    }
    void printSchedule(){
      cout << "====== " << name << "'s tasks =======\n";
      for (int i = 0; i < list.size(); i++)
      {
        cout << list[i] << "\n";
      }
    }
  private:
    vector<char*> list;
    string name;
};

int main(){
  Schedule ritik("rrr");
  auto rk = new Schedule("jjjj");
  ritik.printSchedule();
  ritik.addTask("00:00");
  ritik.addTask("20:30");
  ritik.printSchedule();
  cout << &ritik << endl;
  cout << &rk << endl;
  delete rk;
  rk->printSchedule();
  return 0;
}