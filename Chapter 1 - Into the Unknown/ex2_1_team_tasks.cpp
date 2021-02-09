/*
Task
You should define a class with the three public methods:
1) "GetPersonTasksInfo(person)": outputs the amount of person's tasks by status;
2) "AddNewTask(person)": adds a task in status NEW to the person's tasks;
3) "PerformPersonTasks(person, task_count)": upgrades the task_count number of
the person's most recent tasks to the next status (NEW → IN PROGRESS → TESTING → DONE) and
returns a tuple of two elements: info on upgraded tasks and info on unchanged tasks:
    a) If task_count is bigger than number of tasks, assume that they are equal;
    b) If there's no person with the specified name, return a tuple with empty task infos.
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>

using std::min;
using std::cout;
using std::map;
using std::tuple;
using std::string;
using std::vector;


enum class TaskStatus {
    NEW,
    IN_PROGRESS,
    TESTING,
    DONE
};


using TasksInfo = map<TaskStatus, int>;


void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
    ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
    ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
    ", " << tasks_info[TaskStatus::DONE] << " tasks are done\n";
}


TaskStatus NextStatus(TaskStatus task_status) {
    return static_cast<TaskStatus>(static_cast<int>(task_status) + 1);
}


void RemoveZeros(TasksInfo& tasks_info) {
    vector<TaskStatus> statuses_to_remove;
    for (const auto& [status, count] : tasks_info) {
        if (count == 0) {
            statuses_to_remove.push_back(status);
        }
    }
    for (const TaskStatus status : statuses_to_remove) {
        tasks_info.erase(status);
    }
}


class TeamTasks {
private:
    map<string, TasksInfo> person_tasks;
public:
    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        return person_tasks.at(person);
    };
    void AddNewTask(const string& person) {
        ++person_tasks[person][TaskStatus::NEW];
    }
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
        TasksInfo updated_tasks, unchanged_tasks;
        TasksInfo& tasks = person_tasks[person];
        for (TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = NextStatus(status)) {
            updated_tasks[NextStatus(status)] = min(task_count, tasks[status]);
            task_count -= updated_tasks[NextStatus(status)];
        }
        for (TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = NextStatus(status)) {
            unchanged_tasks[status] = tasks[status] - updated_tasks[NextStatus(status)];
            tasks[status] += updated_tasks[status] - updated_tasks[NextStatus(status)];
        }
        tasks[TaskStatus::DONE] += updated_tasks[TaskStatus::DONE];
        RemoveZeros(updated_tasks);
        RemoveZeros(unchanged_tasks);
        RemoveZeros(person_tasks.at(person));
        return {updated_tasks, unchanged_tasks};
    }
};
