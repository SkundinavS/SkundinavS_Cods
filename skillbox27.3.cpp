#include <vector>
#include <iostream>
#include <string>
using namespace std;

class team {
    vector<string> workers;
    vector<string> task;
public:
    void AddWorkers() {
        while (true) {
            cout << "Input workers name" << endl;
            string name;
            cin >> name;
            if (name == "stop") {
                break;
            }
            else {
                workers.push_back(name);
            }
        }
        workers.push_back("Manager");
        for (int i = 0; i < workers.size(); i++) {
            task.push_back(" ");
        }
    }
    void AddTask(int taskCount,vector<string> taskList) {
        for (int i = 0; i < task.size(); i++) {
            if (task[i] == " ") {
                task[i] = taskList[rand() % (taskList.size())];
                taskCount--;
            }
            if (taskCount == 0) {
                break;
            }
        }
        for (int i = 0; i < workers.size(); i++) {
            cout << workers[i] << " " << task[i] << endl;
        }
    }
    bool IsEmptyWorkers() {
        for (int i = 0; i < task.size();i++) {
            if (task[i] == " ") {
                return true;
            }
        }
        return false;
    }
    int GetEmptyPos() {
        int count = 0;
        for (int i = 0; i < task.size(); i++) {
            if (task[i] == " ") {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    vector<string> taskList{ "A","B","C" };
    vector<team> company;
    cout << "How many teams in company?" << endl;
    int teamscount;
    cin >> teamscount;
    for (int i = 0; i < teamscount; i++) {
        team Team;
        Team.AddWorkers();
        company.push_back(Team);
    }
    int TaskCount = 0;
    for(int g = 0; true; g++) {
        if(g>0) {
            int cou = 0;
            for (int i = 0; i < company.size(); i++) {
                if (company[i].IsEmptyWorkers()) {
                    cou++;
                }
            }
            if (cou == 0) {
                cout << "All workers have work" << endl << "Tasks without worker:" << TaskCount << endl;
                break;
            }
        }
        if (TaskCount == 0) {
            cout << "Input task count" << endl;
            cin >> TaskCount;
        }
        for (int i = 0; i < company.size(); i++) {
            if(company[i].IsEmptyWorkers()) {
                int taskforteam = rand() % (company[i].GetEmptyPos()+1);
                TaskCount -= taskforteam;
                company[i].AddTask(taskforteam, taskList);
            }
        }
    }
}