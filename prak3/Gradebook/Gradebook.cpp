#include "Gradebook.hpp"

void Gradebook::addOrUpdateStudent(const string &studentName, double grade)
{
    studentGrades[studentName] = grade;
}

bool Gradebook::removeStudent(const string &studentName)
{
    if (studentExists(studentName))
    {
        studentGrades.erase(studentGrades.find(studentName));
        return true;
    }
    else
    {
        return false;
    }
}

bool Gradebook::getGrade(const string &studentName, double &grade) const
{
    if (studentExists(studentName))
    {
        grade = studentGrades.at(studentName);
        return true;
    }
    else
    {
        return false;
    }
}

bool Gradebook::studentExists(const string &studentName) const
{
    return studentGrades.find(studentName) != studentGrades.end();
}

void Gradebook::printGrades() const
{
    if (studentGrades.empty())
    {
        cout << "Gradebook kosong" << endl;
        return;
    }

    int idx = 1;
    for (auto it = studentGrades.begin(); it != studentGrades.end(); it++)
    {
        cout << idx << ". " << it->first << ": " << it->second << endl;
        idx++;
    }
}

void Gradebook::printGradesRank() const
{
    vector<pair<string, double>> v;
    for (auto it = studentGrades.begin(); it != studentGrades.end(); it++)
    {
        v.push_back(*it);
    }

    sort(v.begin(), v.end(), [](pair<string, double> a, pair<string, double> b)
         {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second; });

    for (int idx = 0; idx < v.size(); idx++)
    {
        cout << idx + 1 << ". " << v[idx].first << ": " << v[idx].second << endl;
    }
}

vector<string> Gradebook::getStudentsWithGradeAbove(double threshold) const
{
    vector<string> ans;

    for (auto it = studentGrades.begin(); it != studentGrades.end(); it++)
    {
        if (it->second > threshold)
        {
            ans.push_back(it->first);
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}

double Gradebook::getAverageGrade() const
{
    if (studentGrades.empty())
    {
        return 0.0;
    }

    double sum = 0;
    int count = 0;
    for (auto it = studentGrades.begin(); it != studentGrades.end(); it++)
    {
        sum += it->second;
        count++;
    }

    return (1.0 * sum) / (1.0 * count);
}

size_t Gradebook::getNumberOfStudents() const
{
    return studentGrades.size();
}
