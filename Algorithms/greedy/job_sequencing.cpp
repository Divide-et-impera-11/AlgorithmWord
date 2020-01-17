using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#inlcude <algorithm>
//---------------------Job Sequencing---------------------
class Job {
public:
        Job(string job_name, int32_t dead_line, uint32_t money) :
                job_name(job_name),
                dead_line(dead_line),
                money(money) {
                ;
        }
        ~Job() = default;
        string job_name;
        int32_t dead_line;
        uint32_t money;
};
inline void dead_line(deque<Job*> &job_sequenc, vector<Job>& jobs,vector<Job>::iterator &iter) {
        job_sequenc.push_back(iter._Ptr);
        for (vector<Job>::iterator dl_iter = jobs.begin(); dl_iter != jobs.end(); ++dl_iter) {
                if (dl_iter->dead_line)
                        dl_iter->dead_line--;
        }
}
deque<Job*> job_sequencing(vector<Job> &jobs) {
        deque<Job*> job_sequenc;
        vector<Job>::iterator job_iter;
        vector<Job>::iterator previous_job_iter;
        sort(jobs.begin(), jobs.end(), [](Job &arg1, Job &arg2) -> bool {return arg1.money > arg2.money;});
        while ((job_iter = find_if(jobs.begin(), jobs.end(), [](Job &job) -> bool {return job.dead_line;})) != jobs.end())
        {
                for (; job_iter != jobs.end(); ++job_iter) {
                        if (job_iter->dead_line == 1) {
                                dead_line(job_sequenc, jobs, job_iter);
                                previous_job_iter._Ptr = NULL;
                                break;
                        }
                        else if (job_iter->dead_line > 1) {
                                if (previous_job_iter._Ptr != nullptr
                                        && job_iter->dead_line == previous_job_iter->dead_line
                                        && --job_iter->dead_line == 1) {
                                        dead_line(job_sequenc, jobs, job_iter);
                                        previous_job_iter._Ptr = NULL;
                                        break;
                                }
                                previous_job_iter = job_iter;
                        }
                }
                if (previous_job_iter._Ptr) {
                        dead_line(job_sequenc, jobs, previous_job_iter);
                }
        }
        while (!job_sequenc.empty())
        {
                cout << job_sequenc.at(0)->money << endl;
                job_sequenc.pop_front();
        }
        return job_sequenc;
}
// Parameter List:
// vector<Job> &jobs = jobs

// Return Value Cases:
// deque<Job*> = sequence of the jobs(what sequence in, we may to do it)

// Function Call Example
// job_sequencing(vector<Job>(3) = {Job("do caffe",3,10),Job("taxi",1,40),Job("do animation",2,34)});
