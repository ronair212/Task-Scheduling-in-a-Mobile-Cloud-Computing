//
//  main.cpp
//  FCE Final Project
//
//  Created by Rohit  Nair on 11/26/22.
//9.1,5.1,3.1,6.1,2.1,1.1,8.1,0.1,7.1,4.1

#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool check = false;
float power_array[4] = {0.5,1,2,4};
float time_t1 = 0;
float energy_e1 = 0;
float time_t2 = 0;
float energy_e2 = 0;
vector<int> tasks_global ;
vector<int> tasks_global3  ;
vector<int> resource_global ;
long ab;

struct compare_index
{
    const vector < float >base_arr;
    compare_index (vector < float >&arr):base_arr (arr)
    {
    }
    
    bool operator   () (int a, int b) const
    {
        return (base_arr[a] < base_arr[b]);
    }
};

//Priority sorting for ques 1 , 2
class my_test_q1
{
public:
    vector<float> test_sorting (float task_priority[10])
    {
        vector < float >arr, idx;
        int n = 10 ;
        
        
        arr.resize (n);
        idx.resize (n);
        
        for (int i = 0; i < n; i++)
        {
            arr[i] =task_priority[i];
        }
        
        
        for (int i = 0; i < n; i++)
        {
            idx[i] = i;
        }
        
        sort (idx.begin (), idx.end (), compare_index (arr));
        
        
        
        cout << "\nPriority order:  ";
        for (int i = 0; i < n; i++)
        {
            cout << idx[i]+1 << " ";
        }
        
        return idx;
    }
};


//Priority sorting for ques3,4,5
class my_test_q3
{
public:
    vector<float> test_sorting (float task_priority[20])
    {
        vector < float >arr, idx;
        int n = 20 ;
        arr.resize (n);
        idx.resize (n);
        
        for (int i = 0; i < n; i++)
        {
            arr[i] =task_priority[i];
        }
        
        
        for (int i = 0; i < n; i++)
        {
            idx[i] = i;
        }
        
        sort (idx.begin (), idx.end (), compare_index (arr));
        
        
        
        cout << "\nPriority order:  ";
        for (int i = n-1; i >= 0; i--)
        {
            cout << idx[i]+1 << ",";
        }
        
        
        return idx;
    }
};





//Code snippet for Final scheduling 3 recussive code
void send_start_end_array3(int start_time[20][4] , int end_time[20][4] , int t_total)
{
    
    int total_time_taken = 0;
    for(int b = 0; b < 4; b++)
    {
        
        for(int a = 0; a < 20; a++)
        {
            if(a == 0  && b ==1 )
            {
                total_time_taken = total_time_taken + 2;
            }
            if(start_time[a][b] != -1 && end_time[a][b] > total_time_taken)
            {
                total_time_taken =end_time[a][b];
                
            }
            
            
        }
    }
    
    
    
    if( total_time_taken < (1.5*t_total)  && total_time_taken > 34)
    {
        cout << "\n\n For Final scheduling, total time should be lesser than  "  << 1.5*t_total << " \n\n";
        //Energy
        float Energy = 0;
        for(int b = 0; b < 4; b++)
        {
            
            for(int a = 0; a < 20; a++)
            {
                if(start_time[a][b] != -1)
                {
                    int time_taken = end_time[a][b] - start_time[a][b];
                    Energy = Energy + (time_taken * power_array[b]);
                    
                }
                
                
            }
        }
        cout <<" Total Energy  = "<< Energy << " \n";
        cout <<" Total Time taken  = "<< total_time_taken << " \n";

        if(energy_e1 < Energy)
        {
            energy_e1 =Energy ;
        }
        
        cout <<"\n\n\n Task Schedule After final scheduling \n\n\n";
        //Printing each core schedule
        for(int b = 0; b < 4; b++)
        {
            if(b==0)
            {
                
                cout <<" Task Schedule on cloud is \n";
            }
            else
            {
                cout <<" Task Schedule on core "<< b << " is \n";
            }
            for(int a = 0; a < 20; a++)
            {
                if(start_time[a][b] != -1)
                {
                    cout <<" Task = "<< a+1 << " \n";
                    cout <<" Schedule = "<< start_time[a][b] << " to " << end_time[a][b] << " \n";
                }
                
                
            }
        }
        check = true;
        //exit(0);
    }
    
    
    
    
}


void final_schedule_recursive_fn3(vector<int> &tasks, int counter, vector<int> &ans_task, vector<int> &ans_resource , int task_pred[20][20] , int task_succ[20][20] , int t_total )
{
    //cout << "\n\n final_schedule_recursive_fn \n\n ";
    
    if (check)
        return;
    
    int task_time[20][3] = {
        { 19, 7, 5 },
        { 8, 6, 5 },
        { 6, 5, 4 },
        { 7, 5, 3 },
        { 5, 4, 2 },
        { 7, 6, 4 },
        { 8, 5, 3 },
        { 6, 4, 2 },
        { 5, 3, 2 },
        { 7, 4, 2 },
        { 19, 7, 5 },
        { 8, 6, 5 },
        { 6, 5, 4 },
        { 7, 5, 3 },
        { 5, 4, 2 },
        { 7, 6, 4 },
        { 8, 5, 3 },
        { 6, 4, 2 },
        { 5, 3, 2 },
        { 7, 4, 2 }
        
        
    };
    
    int start_time[20][4] = {
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 }
        
        
        
    };
    
    int end_time[20][4] = {
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 }
        
        
        
    };
    
    int t_cl_tx = 3;
    
    int pred_end_time = 0;
    int is_cloud = 0;
    
    int last_task_time = 0;
    if (counter >= tasks.size()) {
        for (int Tasks = 0; Tasks < ans_task.size(); Tasks++)
        {
            //cout << "\n\n Task = " << Tasks << " core =  "  <<  ans_resource[Tasks]<< "\n";
            
            for(int pred = 0 ; task_pred[Tasks][pred] != -1 ; pred++ )
            {
                int task = task_pred[Tasks][pred]-1;
                for(int jp = 0 ; jp <4 ; jp++)
                {
                    if(end_time[task][jp] != -1 && pred_end_time<end_time[task][jp])
                    {
                        
                        pred_end_time = end_time[task][jp];
                        
                        if(jp==0)
                        {
                            is_cloud = 1;
                        }
                        else if (jp !=0 )
                        {
                            is_cloud =0;
                        }
                        
                        
                        
                    }
                }
                
            }
            //cout << "\n pred_end_time = " << pred_end_time << "\n";
            int last_index = 0;
            int task_temp_end_time = 0;
            int last_end_time_in_core = pred_end_time;
            int temp_max = 0;
            for(int ind = 19 ; ind >= 0  ; ind-- )
            {
                if(temp_max < end_time[ind][ans_resource[Tasks]])
                {
                    temp_max = end_time[ind][ans_resource[Tasks]];
                    last_index = ind;
                    
                }
                
            }
            
            //cout << "\n last_end_time_in_core = "<< last_end_time_in_core  << "\n";
            if (last_end_time_in_core < end_time[last_index][ans_resource[Tasks]])
            {
                last_end_time_in_core = end_time[last_index][ans_resource[Tasks]];
                
            }
            //cout << "\n last_end_time_in_core = "<< last_end_time_in_core  << "\n";
            
            if(ans_resource[Tasks]!=0)
            {
                //checking if predecessor is a cloud task
                //cout <<"checking if predecessor is a cloud task " << is_cloud << "\n"  ;
                if (is_cloud == 1)
                {
                    if (pred_end_time+2 > last_end_time_in_core)
                    {
                        task_temp_end_time =pred_end_time+task_time[Tasks][ans_resource[Tasks]-1] +2;
                    }
                    else
                    {
                        task_temp_end_time = last_end_time_in_core + task_time[Tasks][ans_resource[Tasks]-1] ;
                    }
                }
                else
                {
                    task_temp_end_time = last_end_time_in_core + task_time[Tasks][ans_resource[Tasks]-1] ;
                }
                end_time[Tasks][ans_resource[Tasks]] = task_temp_end_time;
                start_time[Tasks][ans_resource[Tasks]] =task_temp_end_time - task_time[Tasks][ans_resource[Tasks]-1];
                
                
                
            }
            else if (ans_resource[Tasks] == 0 )
            {
                task_temp_end_time = last_end_time_in_core + t_cl_tx;
                end_time[Tasks][ans_resource[Tasks]] = task_temp_end_time;
                start_time[Tasks][ans_resource[Tasks]] =task_temp_end_time - t_cl_tx;
            }
            
            
            
        }
        ab = ab + 1;
        
        send_start_end_array3(start_time,end_time, t_total );
        
        
        
    } else {
        
        
        for (int j = 0; j < resource_global.size(); j++) {
            ans_task.push_back(tasks[counter]);
            ans_resource.push_back(resource_global[j]);
            
            final_schedule_recursive_fn3(tasks, counter+1, ans_task, ans_resource , task_pred , task_succ, t_total );
            
            ans_task.pop_back();
            ans_resource.pop_back();
        }
    }
    
}





//Code snippet for Final scheduling 1 recussive code
void send_start_end_array(int start_time[10][4] , int end_time[10][4] , int t_total)
{
    
    
    
    //Time
    int total_time_taken = 0;
    for(int b = 0; b < 4; b++)
    {
        
        for(int a = 0; a < 10; a++)
        {
            if(a == 0  && b ==1 )
            {
                total_time_taken = total_time_taken + 2;
            }
            if(start_time[a][b] != -1 && end_time[a][b] > total_time_taken)
            {
                total_time_taken =end_time[a][b];
                
            }
            
            
        }
    }
    
    
    //cout << "\n time_t1 = " << total_time_taken << "\n";
    //total_time_taken > (1.5*t_total -1 ) &&
    if( total_time_taken < (1.5*t_total) )
    {
        cout << "\n\n For Final scheduling, total time should be lesser than  "  << 1.5*t_total << " \n\n";
        //Energy
        float Energy = 0;
        for(int b = 0; b < 4; b++)
        {
            
            for(int a = 0; a < 10; a++)
            {
                if(start_time[a][b] != -1)
                {
                    int time_taken = end_time[a][b] - start_time[a][b];
                    Energy = Energy + (time_taken * power_array[b]);
                    
                }
                
                
            }
        }
        if(energy_e1 < Energy)
        {
            energy_e1 =Energy ;
        }
        cout <<" Total Energy  = "<< Energy << " \n";
        cout <<" Total Time taken  = "<< total_time_taken << " \n";
        cout <<"\n\n\n Task Schedule After final scheduling \n\n\n";
        //Printing each core schedule
        for(int b = 0; b < 4; b++)
        {
            if(b==0)
            {
                
                cout <<" Task Schedule on cloud is \n";
            }
            else
            {
                cout <<" Task Schedule on core "<< b << " is \n";
            }
            for(int a = 0; a < 10; a++)
            {
                if(start_time[a][b] != -1)
                {
                    cout <<" Task = "<< a+1 << " \n";
                    cout <<" Schedule = "<< start_time[a][b] << " to " << end_time[a][b] << " \n";
                }
                
                
            }
        }
        check = true;
        //exit(0);
    }
    
    
    
    
}


void final_schedule_recursive_fn(vector<int> &tasks, int counter, vector<int> &ans_task, vector<int> &ans_resource , int task_pred[10][10] , int task_succ[10][10] , int t_total )
{
    //cout << "\n\n final_schedule_recursive_fn \n\n ";
    
    if (check)
        return;
    
    int task_time[10][3] = {
        { 9, 7, 5 },
        { 8, 6, 5 },
        { 6, 5, 4 },
        { 7, 5, 3 },
        { 5, 4, 2 },
        { 7, 6, 4 },
        { 8, 5, 3 },
        { 6, 4, 2 },
        { 5, 3, 2 },
        { 7, 4, 2 }
        
        
    };
    
    int start_time[10][4] = {
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        
        
        
    };
    
    int end_time[10][4] = {
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        
        
        
    };
    
    int t_cl_tx = 3;
    
    int pred_end_time = 0;
    int is_cloud = 0;
    //int resource_global[Tasks] = 0;
    //int Tasks = 0;
    int last_task_time = 0;
    if (counter >= tasks.size()) {
        for (int Tasks = 0; Tasks < ans_task.size(); Tasks++)
        { //cout << "\n\n Task = " << Tasks << " core =  "  <<  ans_resource[Tasks]<< "\n";
            
            for(int pred = 0 ; task_pred[Tasks][pred] != -1 ; pred++ )
            {
                int task = task_pred[Tasks][pred]-1;
                for(int jp = 0 ; jp <4 ; jp++)
                {
                    if(end_time[task][jp] != -1 && pred_end_time<end_time[task][jp])
                    {
                        
                        
                        pred_end_time = end_time[task][jp];
                        
                        
                        if(jp==0)
                        {
                            is_cloud = 1;
                        }
                        else if (jp !=0 )
                        {
                            is_cloud =0;
                        }
                        
                        
                        
                    }
                }
                
            }
            //cout << "\n pred_end_time = " << pred_end_time << "\n";
            int last_index = 0;
            int task_temp_end_time = 0;
            int last_end_time_in_core = pred_end_time;
            int temp_max = 0;
            for(int ind = 9 ; ind >= 0  ; ind-- )
            {
                if(temp_max < end_time[ind][ans_resource[Tasks]])
                {
                    temp_max = end_time[ind][ans_resource[Tasks]];
                    last_index = ind;
                    
                }
                
                
                
            }
            
            //cout << "\n last_end_time_in_core = "<< last_end_time_in_core  << "\n";
            if (last_end_time_in_core < end_time[last_index][ans_resource[Tasks]])
            {
                last_end_time_in_core = end_time[last_index][ans_resource[Tasks]];
                
            }
            //cout << "\n last_end_time_in_core = "<< last_end_time_in_core  << "\n";
            
            if(ans_resource[Tasks]!=0)
            {
                //checking if predecessor is a cloud task
                //cout <<"checking if predecessor is a cloud task " << is_cloud << "\n"  ;
                if (is_cloud == 1)
                {
                    if (pred_end_time+2 > last_end_time_in_core)
                    {
                        task_temp_end_time =pred_end_time+task_time[Tasks][ans_resource[Tasks]-1] +2;
                    }
                    else
                    {
                        task_temp_end_time = last_end_time_in_core + task_time[Tasks][ans_resource[Tasks]-1] ;
                    }
                }
                else
                {
                    task_temp_end_time = last_end_time_in_core + task_time[Tasks][ans_resource[Tasks]-1] ;
                }
                end_time[Tasks][ans_resource[Tasks]] = task_temp_end_time;
                start_time[Tasks][ans_resource[Tasks]] =task_temp_end_time - task_time[Tasks][ans_resource[Tasks]-1];
                
                
                
            }
            else if (ans_resource[Tasks] == 0 )
            {
                task_temp_end_time = last_end_time_in_core + t_cl_tx;
                end_time[Tasks][ans_resource[Tasks]] = task_temp_end_time;
                start_time[Tasks][ans_resource[Tasks]] =task_temp_end_time - t_cl_tx;
            }
            //cout << "\n task_temp_end_time = "<< task_temp_end_time  << "\n";
            
            
            //cout << "\n start_time[Tasks][ans_resource[Tasks]] = "<< start_time[Tasks][ans_resource[Tasks]]  << "\n";
            
            
        }
        ab = ab + 1;
        
        
        
        
        send_start_end_array(start_time,end_time, t_total );
        //System.out.println();
        //if(ab == 3)
        //{
        //    exit(0);
        //}
        
        
    } else {
        
        
        for (int j = 0; j < resource_global.size(); j++) {
            ans_task.push_back(tasks[counter]);
            ans_resource.push_back(resource_global[j]);
            
            final_schedule_recursive_fn(tasks, counter+1, ans_task, ans_resource , task_pred , task_succ, t_total );
            
            ans_task.pop_back();
            ans_resource.pop_back();
        }
    }
    
}

void Initial_Task_schedule1(int task_pred[10][10] , int task_succ[10][10])
{
    
    
    
    
    int task_time[10][3] = {
        { 9, 7, 5 },
        { 8, 6, 5 },
        { 6, 5, 4 },
        { 7, 5, 3 },
        { 5, 4, 2 },
        { 7, 6, 4 },
        { 8, 5, 3 },
        { 6, 4, 2 },
        { 5, 3, 2 },
        { 7, 4, 2 }
        
        
    };
    
    
    int pred_cloud[10][4] = {
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        
        
        
    };
    
    int start_time[10][4] = {
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        
        
        
    };
    
    int end_time[10][4] = {
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        
        
        
    };
    
    int t_cl_tx = 3;
    int t_cl_comp = 1;
    int t_cl_rx = 1;
    
    int total_cl_time = 5;
    
    
    
    
    int time_min[10];
    for (int i = 0; i < 10; i++)//iterate each row(one loop for the row)
    {
        int t_min = task_time[i][1];
        float sum=0;//reset sum for each row
        for (int j = 0; j < 3; j++)//iterate each column in each row(one loop for the column)
            if (t_min > task_time[i][j])
            {
                t_min =task_time[i][j];
                
            }
        
        time_min[i] = t_min;//give you the average of each row
    }
    
    
    
    int cloud_tasks[10];
    for (int i = 0; i < 10; i++)
    {
        if (total_cl_time < time_min[i] )
        {
            cloud_tasks[i] = 1;
            
        }
        else
        {
            
            cloud_tasks[i] = 0;
        }
    }
    
    
    
    float time_avg[10];
    for (int i = 0; i < 10; i++)
    {
        float sum=0;
        for (int j = 0; j < 3; j++)
            sum += task_time[i][j];
        
        time_avg[i]=sum/3;
    }
  
    
    float task_priority[10];
    
    
    
    for (int i = 9; i >= 0 ; i--)
    {
        
        if (i==9) {
            if (cloud_tasks[i] == 0 )
            {
                
                task_priority [i] = time_avg[i];
                
            }
            else if (cloud_tasks[i] == 1)
            {
                
                task_priority [i] = total_cl_time;
            }
        }
        else
        {
            if (cloud_tasks[i] == 0 )
            {
                float max_pri = 0;
                for (int suc_pr = 0 ; task_succ[i][suc_pr] != -1 ; suc_pr++)
                {
                    
                    if (max_pri < task_priority[task_succ[i][suc_pr]-1]) {
                        max_pri = task_priority[task_succ[i][suc_pr]-1];
                        
                    }
                    
                }
                task_priority[i] = time_avg[i] + max_pri;
                
            }
            else if (cloud_tasks[i] == 1)
            {
                
                float max_pri = 0;
                for (int suc_pr = 0 ; task_succ[i][suc_pr] != -1 ; suc_pr++)
                {
                    
                    
                    if (max_pri < task_priority[task_succ[i][suc_pr]-1]) {
                        max_pri = task_priority[task_succ[i][suc_pr]-1];
                        
                    }
                    
                }
                task_priority[i] = total_cl_time + max_pri;
            }        }
        
        
    }
    
    
    
    my_test_q1 tstobj;
    vector<float> v = tstobj.test_sorting (task_priority);
    int sorted_priority[10];
    for (int i = 0; i < 10; i++)
    {
        sorted_priority[9-i] = v[i];
    }
    
    
    
    
    for (int i = 0; i < 10; i++)
    {
        
        int current_priority_task_index = sorted_priority[i];
        vector<int> tasks_end_time;
        int pred_end_time = 0;
        int is_cloud = 0;
        for(int pred = 0 ; task_pred[current_priority_task_index][pred] != -1 ; pred++ )
        {
            int task = task_pred[current_priority_task_index][pred]-1;
            for(int j = 0 ; j <4 ; j++)
            {
                if(end_time[task][j] != -1 && pred_end_time<end_time[task][j])
                {
                    
                    
                    pred_end_time = end_time[task][j];
                    
                    
                    if(j==0)
                    {
                        is_cloud = 1;
                    }
                    else if (j !=0 )
                    {
                        is_cloud =0;
                    }
                    
                    
                    
                }
            }
            
        }
        
        
        
        
        if (cloud_tasks[current_priority_task_index] == 0) {
            
            
            int mintime = 0;
            for( int core_ind = 0 ; core_ind <4 ; core_ind++)
            {
                //tasks_end_time.push_back(i);
                int last_index = 0;
                int task_temp_end_time = 0;
                int last_end_time_in_core = pred_end_time;
                int temp_max = 0;
                for(int ind = 9 ; ind >= 0  ; ind-- )
                {
                    if(temp_max < end_time[ind][core_ind])
                    {
                        temp_max = end_time[ind][core_ind];
                        last_index = ind;
                        
                    }
                    
                    
                }
                if (last_end_time_in_core < end_time[last_index][core_ind])
                {
                    last_end_time_in_core = end_time[last_index][core_ind];
                    
                }
                
                if(core_ind!=0)
                {
                    //checking if predecessor is a cloud task
                    
                    if (is_cloud == 1)
                    {
                        if (pred_end_time+2 > last_end_time_in_core)
                        {
                            task_temp_end_time =pred_end_time+task_time[current_priority_task_index][core_ind-1] +2;
                        }
                        else
                        {
                            task_temp_end_time = last_end_time_in_core + task_time[current_priority_task_index][core_ind-1] +2;
                        }
                    }
                    else
                    {
                        task_temp_end_time = last_end_time_in_core + task_time[current_priority_task_index][core_ind-1] ;
                    }
                    
                    
                    
                }
                else if (core_ind == 0 )
                {
                    task_temp_end_time = last_end_time_in_core + t_cl_tx;
                }
                tasks_end_time.push_back(task_temp_end_time);
                
                
            }
            mintime =  *min_element(tasks_end_time.begin(), tasks_end_time.end());
            int minElementIndex = std::min_element(tasks_end_time.begin(),tasks_end_time.end()) - tasks_end_time.begin();
            
            //cout << "Vector: ";
            for (int i = 0; i < tasks_end_time.size(); i++)
                //cout << tasks_end_time[i] << " ";
                //cout << endl;
                
                //cout << "minElementIndex: " << minElementIndex << "\n";
                
                end_time[current_priority_task_index][minElementIndex] = mintime;
            start_time[current_priority_task_index][minElementIndex] = mintime - task_time[current_priority_task_index][minElementIndex-1];
            
            if(minElementIndex!=0)
            {
                end_time[current_priority_task_index][minElementIndex] = mintime;
                start_time[current_priority_task_index][minElementIndex] = mintime - task_time[current_priority_task_index][minElementIndex-1];
                
                
            }
            else if (minElementIndex == 0 )
            {
                end_time[current_priority_task_index][minElementIndex] = mintime;
                start_time[current_priority_task_index][minElementIndex] = mintime - t_cl_tx;
            }
            
            
            
        }
        else if (cloud_tasks[current_priority_task_index] == 1){
            for(int check_core = 0 ; check_core < 10 ; check_core++)
            {
                if(end_time[check_core][0] != -1 && end_time[check_core][0]> pred_end_time)
                {
                    pred_end_time =end_time[check_core][0];
                    
                }
                
            }
            start_time[current_priority_task_index][0] =pred_end_time;
            end_time[current_priority_task_index][0] = start_time[current_priority_task_index][0] + t_cl_tx;
        }
        tasks_end_time.clear();
    }
    

    
    cout <<" Task Schedule on cloud processing is \n";
    for(int  i = 0 ; i < 10 ; i ++ )
    {
        if(end_time[i][0] != -1 )
        {
            cout <<" Task = "<< i+1 << " \n";
            cout <<" Schedule = "<< end_time[i][0] << " to " << end_time[i][0]+1 << " \n";
        }
        
    }
    
    //printing  wireless receiving
    cout <<" Task Schedule on wireless receiving  is \n";
    for(int  i = 0 ; i < 10 ; i ++ )
    {
        if(end_time[i][0] != -1 )
        {
            cout <<" Task = "<< i+1 << " \n";
            cout <<" Schedule = "<< end_time[i][0]+1 << " to " << end_time[i][0]+2 << " \n";
        }
        
    }
    
    //Printing each core schedule
    for(int b = 0; b < 4; b++)
    {
        if(b==0)
        {
            
            cout <<" Task Schedule on cloud is \n";
        }
        else
        {
            cout <<" Task Schedule on core "<< b << " is \n";
        }
        for(int a = 0; a < 10; a++)
        {
            if(start_time[a][b] != -1)
            {
                cout <<" Task = "<< a+1 << " \n";
                cout <<" Schedule = "<< start_time[a][b] << " to " << end_time[a][b] << " \n";
            }
            
            
        }
    }
    
    //Energy
    float Energy = 0;
    for(int b = 0; b < 4; b++)
    {
        
        for(int a = 0; a < 10; a++)
        {
            if(start_time[a][b] != -1)
            {
                int time_taken = end_time[a][b] - start_time[a][b];
                Energy = Energy + (time_taken * power_array[b]);
                
            }
               
        }
    }
    cout <<" Total Energy  = "<< Energy << " \n";
    
    int total_time_taken = 0;
    for(int b = 0; b < 4; b++)
    {
        
        for(int a = 0; a < 10; a++)
        {
            if(a == 0 && b ==1 )
            {
                total_time_taken = total_time_taken + 2;
            }
            if(start_time[a][b] != -1 && end_time[a][b] > total_time_taken)
            {
                total_time_taken =end_time[a][b];
                
            }
            

        }
    }
    
    cout <<" Total time taken  = "<< total_time_taken << " \n";
    
    int t_total = total_time_taken;
    vector<int> ans_task;
    vector<int> ans_resource;
    
    check = false;
    final_schedule_recursive_fn(tasks_global, 0, ans_task,  ans_resource ,  task_pred ,  task_succ , t_total );
    //cout<<ab;
    
    
    
}




//function for ques 3,4,5
void Initial_Task_schedule3(int task_pred[20][20] , int task_succ[20][20])
{
    //cout <<"\n\n\n Starting initial algorithm 1 \n\n\n" ;
    
    int task_time[20][3] = {
        { 19, 7, 5 },
        { 8, 6, 5 },
        { 6, 5, 4 },
        { 7, 5, 3 },
        { 5, 4, 2 },
        { 7, 6, 4 },
        { 8, 5, 3 },
        { 6, 4, 2 },
        { 5, 3, 2 },
        { 7, 4, 2 },
        { 19, 7, 5 },
        { 8, 6, 5 },
        { 6, 5, 4 },
        { 7, 5, 3 },
        { 5, 4, 2 },
        { 7, 6, 4 },
        { 8, 5, 3 },
        { 6, 4, 2 },
        { 5, 3, 2 },
        { 7, 4, 2 }
        
        
    };
    
    
    
    int pred_cloud[20][4] = {
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 }
        
        
        
    };
    
    int start_time[20][4] = {
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 }
        
        
        
    };
    
    int end_time[20][4] = {
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 },
        { -1, -1, -1, -1 }
        
        
        
    };
    
    int t_cl_tx = 3;
    int t_cl_comp = 1;
    int t_cl_rx = 1;
    
    int total_cl_time = 5;
    
    
    
    
    int time_min[20];
    for (int i = 0; i < 20; i++) //iterate each row(one loop for the row)
    {
        int t_min = task_time[i][1];
        float sum=0; //reset sum for each row
        for (int j = 0; j < 3; j++)//iterate each column in each row(one loop for the column)
            if (t_min > task_time[i][j])
            {
                t_min =task_time[i][j];
                
            }
        
        time_min[i] = t_min;//give you the average of each row
    }
    
    
    int cloud_tasks[20];
    for (int i = 0; i < 20; i++)
    {
        if (total_cl_time < time_min[i] )
        {
            cloud_tasks[i] = 1;
            
        }
        else
        {
            
            cloud_tasks[i] = 0;
        }
    }
    
    
    
    float time_avg[20];
    for (int i = 0; i < 20; i++)
    {
        float sum=0;
        for (int j = 0; j < 3; j++)
            sum += task_time[i][j];
        
        time_avg[i]=sum/3;
    }
    

    
    float task_priority[20];
    
    
    
    for (int i = 19; i >= 0 ; i--)
    {
        
        if (i==19) {
            if (cloud_tasks[i] == 0 )
            {
                
                task_priority [i] = time_avg[i];
                
            }
            else if (cloud_tasks[i] == 1)
            {
                
                task_priority [i] = total_cl_time;
            }
        }
        else
        {
            if (cloud_tasks[i] == 0 )
            {
                float max_pri = 0;
                for (int suc_pr = 0 ; task_succ[i][suc_pr] != -1 ; suc_pr++)
                {
                    
                    
                    if (max_pri < task_priority[task_succ[i][suc_pr]-1]) {
                        max_pri = task_priority[task_succ[i][suc_pr]-1];
                        
                    }
                    
                }
                task_priority[i] = time_avg[i] + max_pri;
                
            }
            else if (cloud_tasks[i] == 1)
            {
                
                float max_pri = 0;
                for (int suc_pr = 0 ; task_succ[i][suc_pr] != -1 ; suc_pr++)
                {
                    
                    
                    if (max_pri < task_priority[task_succ[i][suc_pr]-1]) {
                        max_pri = task_priority[task_succ[i][suc_pr]-1];
                        
                    }
                    
                }
                task_priority[i] = total_cl_time + max_pri;
            }        }
        
        
    }
    
    
    
    my_test_q3 tstobj3;
    
    vector<float> v = tstobj3.test_sorting (task_priority);
    int sorted_priority[20];
    for (int i = 0; i < 20; i++)
    {
        sorted_priority[19-i] = v[i];
    }
    
    //starting scheduling
    for (int i = 0; i < 20; i++)
    {
        
        int current_priority_task_index = sorted_priority[i];
        vector<int> tasks_end_time;
        int pred_end_time = 0;
        int is_cloud = 0;
        for(int pred = 0 ; task_pred[current_priority_task_index][pred] != -1 ; pred++ )
        {
            int task = task_pred[current_priority_task_index][pred]-1;
            for(int j = 0 ; j <4 ; j++)
            {
                if(end_time[task][j] != -1 && pred_end_time<end_time[task][j])
                {
                    
                    
                    pred_end_time = end_time[task][j];
                    
                    
                    if(j==0)
                    {
                        is_cloud = 1;
                    }
                    else if (j !=0 )
                    {
                        is_cloud =0;
                    }
                    
                    
                    
                }
            }
            
        }
        
        
        if (cloud_tasks[current_priority_task_index] == 0) {
            
            
            int mintime = 0;
            for( int core_ind = 0 ; core_ind <4 ; core_ind++)
            {
                int last_index = 0;
                int task_temp_end_time = 0;
                int last_end_time_in_core = pred_end_time;
                int temp_max = 0;
                for(int ind = 19 ; ind >= 0  ; ind-- )
                {
                    if(temp_max < end_time[ind][core_ind])
                    {
                        temp_max = end_time[ind][core_ind];
                        last_index = ind;
                        
                    }
                    
                    
                }
                if (last_end_time_in_core < end_time[last_index][core_ind])
                {
                    last_end_time_in_core = end_time[last_index][core_ind];
                    
                }
                
                if(core_ind!=0)
                {
                    
                    if (is_cloud == 1)
                    {
                        if (pred_end_time+2 > last_end_time_in_core)
                        {
                            task_temp_end_time =pred_end_time+task_time[current_priority_task_index][core_ind-1] +2;
                        }
                        else
                        {
                            task_temp_end_time = last_end_time_in_core + task_time[current_priority_task_index][core_ind-1] ;
                        }
                    }
                    else
                    {
                        task_temp_end_time = last_end_time_in_core + task_time[current_priority_task_index][core_ind-1] ;
                    }
                    
                    
                    
                }
                else if (core_ind == 0 )
                {
                    task_temp_end_time = last_end_time_in_core + t_cl_tx;
                }
                tasks_end_time.push_back(task_temp_end_time);
                
                
            }
            mintime =  *min_element(tasks_end_time.begin(), tasks_end_time.end());
            int minElementIndex = std::min_element(tasks_end_time.begin(),tasks_end_time.end()) - tasks_end_time.begin();
            
            //cout << "Vector: ";
            for (int i = 0; i < tasks_end_time.size(); i++)
                //cout << tasks_end_time[i] << " ";
                //cout << endl;
                
                //cout << "minElementIndex: " << minElementIndex << "\n";
                
                end_time[current_priority_task_index][minElementIndex] = mintime;
            start_time[current_priority_task_index][minElementIndex] = mintime - task_time[current_priority_task_index][minElementIndex-1];
            
            if(minElementIndex!=0)
            {
                end_time[current_priority_task_index][minElementIndex] = mintime;
                start_time[current_priority_task_index][minElementIndex] = mintime - task_time[current_priority_task_index][minElementIndex-1];
                
                
            }
            else if (minElementIndex == 0 )
            {
                end_time[current_priority_task_index][minElementIndex] = mintime;
                start_time[current_priority_task_index][minElementIndex] = mintime - t_cl_tx;
            }
            
            
            
        }
        else if (cloud_tasks[current_priority_task_index] == 1){
            for(int check_core = 0 ; check_core < 20 ; check_core++)
            {
                if(end_time[check_core][0] != -1 && end_time[check_core][0]> pred_end_time)
                {
                    pred_end_time =end_time[check_core][0];
                    
                }
                
            }
            start_time[current_priority_task_index][0] =pred_end_time;
            end_time[current_priority_task_index][0] = start_time[current_priority_task_index][0] + t_cl_tx;
        }
        tasks_end_time.clear();
    }
    
    //cout << "start_time = \n";
    for(int a = 0; a < 20; a++)
    {
        for(int b = 0; b < 4; b++)
        {
            //cout << start_time[a][b] << " ";
        }
        //cout << endl;
    }
    //cout << "end_time = \n";
    
    for(int a = 0; a < 20; a++)
    {
        for(int b = 0; b < 4; b++)
        {
            //cout << end_time[a][b] << " ";
        }
        //cout << endl;
    }
    
    //printing cloud processing
    cout <<" Task Schedule on cloud processing is \n";
    for(int  i = 0 ; i < 20 ; i ++ )
    {
        if(end_time[i][0] != -1 )
        {
            cout <<" Task = "<< i+1 << " \n";
            cout <<" Schedule = "<< end_time[i][0] << " to " << end_time[i][0]+1 << " \n";
        }
        
    }
    
    //printing  wireless receiving
    cout <<" Task Schedule on wireless receiving  is \n";
    for(int  i = 0 ; i < 20 ; i ++ )
    {
        if(end_time[i][0] != -1 )
        {
            cout <<" Task = "<< i+1 << " \n";
            cout <<" Schedule = "<< end_time[i][0]+1 << " to " << end_time[i][0]+2 << " \n";
        }
        
    }
    
    //Printing each core schedule
    for(int b = 0; b < 4; b++)
    {
        if(b==0)
        {
            
            cout <<" Task Schedule on cloud is \n";
        }
        else
        {
            cout <<" Task Schedule on core "<< b << " is \n";
        }
        for(int a = 0; a < 20; a++)
        {
            if(start_time[a][b] != -1)
            {
                cout <<" Task = "<< a+1 << " \n";
                cout <<" Schedule = "<< start_time[a][b] << " to " << end_time[a][b] << " \n";
            }
            
            
        }
    }
    
    
    
    //Energy
    float Energy = 0;
    for(int b = 0; b < 4; b++)
    {
        
        for(int a = 0; a < 20; a++)
        {
            if(start_time[a][b] != -1)
            {
                int time_taken = end_time[a][b] - start_time[a][b];
                Energy = Energy + (time_taken * power_array[b]);
                
            }
            
            
        }
    }
    cout <<" Total Energy  = "<< Energy << " \n";
    
    int total_time_taken = 0;
    for(int b = 0; b < 4; b++)
    {
        
        for(int a = 0; a < 20; a++)
        {
            if(a == 0 && b ==1 )
            {
                total_time_taken = total_time_taken + 2;
            }
            if(start_time[a][b] != -1 && end_time[a][b] > total_time_taken)
            {
                total_time_taken =end_time[a][b];
                
            }
            
            
        }
    }
    
    cout <<" Total time taken  = "<< total_time_taken << " \n";
    
    int t_total = total_time_taken;
    vector<int> ans_task;
    vector<int> ans_resource;
    
    check = false;
    final_schedule_recursive_fn3(tasks_global3, 0, ans_task,  ans_resource ,  task_pred ,  task_succ , t_total );
    //cout<<ab;
    
    
}


int main(void) {
    tasks_global.push_back(0);
    tasks_global.push_back(1);
    tasks_global.push_back(2);
    tasks_global.push_back(3);
    tasks_global.push_back(4);
    tasks_global.push_back(5);
    tasks_global.push_back(6);
    tasks_global.push_back(7);
    tasks_global.push_back(8);
    tasks_global.push_back(9);

    tasks_global3.push_back(0);
    tasks_global3.push_back(1);
    tasks_global3.push_back(2);
    tasks_global3.push_back(3);
    tasks_global3.push_back(4);
    tasks_global3.push_back(5);
    tasks_global3.push_back(6);
    tasks_global3.push_back(7);
    tasks_global3.push_back(8);
    tasks_global3.push_back(9);
    tasks_global3.push_back(10);
    tasks_global3.push_back(11);
    tasks_global3.push_back(12);
    tasks_global3.push_back(13);
    tasks_global3.push_back(14);
    tasks_global3.push_back(15);
    tasks_global3.push_back(16);
    tasks_global3.push_back(17);
    tasks_global3.push_back(18);
    tasks_global3.push_back(19);

    resource_global.push_back(0);
    resource_global.push_back(1);
    resource_global.push_back(2);
    resource_global.push_back(3);


    int task_pred1[10][10] = {
        { -1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 3, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 2, 4, 6, -1, -1, -1, -1, -1, -1 , -1 },
        { 2, 4, 5, -1, -1, -1, -1, -1, -1 , -1 },
        { 7, 8, 9, -1, -1, -1, -1, -1, -1 , -1 }
        
        
        
    };
    
    int task_succ1[10][10] = {
        { 2, 3, 4, 5, 6, -1, -1, -1, -1 , -1 },
        { 8, 9, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 7, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 8, 9, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 9, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 8, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 10, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 10, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 10, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 10, -1, -1, -1, -1, -1, -1, -1, -1 , -1 }
    };
    cout <<"\n\n\n  Task schedule for task graph 1  \n\n\n";
    
    Initial_Task_schedule1(task_pred1 , task_succ1);
    
    int task_pred2[10][10] = {
        { -1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 2, 3, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 4, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 5, 6, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 6, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 7, 8, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 9, -1, -1, -1, -1, -1, -1, -1, -1 , -1 }
        
        
        
    };
    
    int task_succ2[10][10] = {
        { 2, 3, 4, -1, -1, -1, -1, -1, -1 , -1 },
        { 5, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 5, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 6, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 7, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 7, 8, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 9, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 9, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 10, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { -1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 }
    };
    cout <<"\n\n\n  Task schedule for task graph 2  \n\n\n";
    
    
    Initial_Task_schedule1(task_pred2 , task_succ2);

    
    int task_pred3[20][20] = {
        { -1, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 1, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 2, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 2, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 3, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 3, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 4, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 4, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 5, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 5, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 6, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 6, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 7, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 7, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 8, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 8, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 9, 10, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 11, 12, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 13, 14, 15, 16, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 17, 18, 19, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        
        
        
    };
    
    int task_succ3[20][20] = {
        { 2, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 3, 4, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 5, 6, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 7, 8, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 9, 10, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 11, 12, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 13, 14, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 15, 16, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 17, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 17, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 18, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 18, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 19, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 19, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 19, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 19, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 20, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 20, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 20, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { -1, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
    };
    cout <<"\n\n\n  Task schedule for task graph 3  \n\n\n";
    
    
    Initial_Task_schedule3(task_pred3 , task_succ3);
    
    
    int task_pred4[20][20] = {
        { -1, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { -1, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 1, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 2, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 3, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 3, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 4, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 4, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 5, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 5, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 6, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 6, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 7, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 7, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 8, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 8, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 9, 10, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 11, 12, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 13, 14, 15, 16, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 17, 18, 19, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        
        
        
    };
    
    int task_succ4[20][20] = {
        { 3, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 4, 4, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 5, 6, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 7, 8, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 9, 10, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 11, 12, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 13, 14, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 15, 16, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 17, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 17, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 18, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 18, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 19, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 19, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 19, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 19, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 20, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 20, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 20, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { -1, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
    };
    cout <<"\n\n\n  Task schedule for task graph 4  \n\n\n";
    
    
    Initial_Task_schedule3(task_pred4 , task_succ4);
    
    
    int task_pred5[20][20] = {
        { -1, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { -1, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 1, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 2, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 3, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 3, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 4, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 4, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 5, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 5, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 6, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 6, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 7, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 7, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 8, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 8, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 9, 10, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 11, 12, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 13, 14, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 15, 16, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        
        
        
    };
    
    int task_succ5[20][20] = {
        { 3, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 4, 4, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 5, 6, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 7, 8, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 9, 10, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 11, 12, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 13, 14, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 15, 16, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 17, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 17, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 18, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 18, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 19, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 19, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 20, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { 20, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { -1, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { -1, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { -1, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
        { -1, -1, -1, -1, -1, -1, -1, -1, -1 , -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 },
    };
    cout <<"\n\n\n  Task schedule for task graph 5  \n\n\n";
    
    
    Initial_Task_schedule3(task_pred5 , task_succ5);
    
    
    
    
    
    
}

