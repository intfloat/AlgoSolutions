/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> id_to_emp;
        for (auto& employee : employees) {
            id_to_emp[employee->id] = employee;
        }
        int res = 0;
        queue<Employee*> q;
        if (id_to_emp.find(id) != id_to_emp.end()) {
            q.push(id_to_emp[id]);
        }

        while (!q.empty()) {
            Employee* tp = q.front();
            q.pop();
            res += tp->importance;
            for (auto& sub_id : tp->subordinates) {
                q.push(id_to_emp[sub_id]);
            }
        }
        return res;
    }
};
