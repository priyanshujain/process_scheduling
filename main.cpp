#include <iostream>
#include <vector>
#include <algorithm>
#include "Process.h"
#include "Result.h"
#include "FCFS.h"
using namespace std;

int main()
{
    int n;
    int t1, t2, t3;
    cout<<"Enter number of processes : ";
    cin>>n;
    vector<Process> processes;
    for(int i = 0; i < n; i++)
    {
        cout<<"Enter burst time, arrival time and priority for Process "<<i+1<<" : ";
        cin>>t1>>t2>>t3;

        processes.push_back(*(new Process(i+1, t1, t2, t3)));
    }
    sort(processes.begin(), processes.end(), Process::byArrivalTime);
    Result result = FCFS::calculate(processes);
    cout<<"ATAT : "<<result.avgTurnAroundTime<<endl;
    cout<<"AWT/ART : "<<result.avgWaitingTime<<endl;
    return 0;
}