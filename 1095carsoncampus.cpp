#include <iostream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

struct record
{
    string plate;
    int timestamp;
    bool status;
    bool flag; //表示是否是有效的位。
}r[10000];

map<string, int> str2i;

struct car
{
    string plate;
    int in;
    int out;
    int duration;
    int last_in;
    bool state;
}c[10000];
int car_num = 0;

set<string> lazy_cars;

bool comp(record a, record b)
{
    return a.timestamp < b.timestamp;
}

int main()
{
    int N, K;
    scanf("%d%d", &N, &K);
    getchar();
    string status;
    int hh, mm, ss;
    for(int i=0; i<N; i++)
    {
        cin>>r[i].plate;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        getchar();
        r[i].timestamp = hh*3600 + mm*60 + ss;
        cin>>status;
        if(status[0] == 'i')
        {
            r[i].status = true;
        }
        else
        {
            r[i].status = false;
        }
    }

    sort(r, r+N, comp);

    for(int i=0; i<N; i++)
    {
        if(str2i.find(r[i].plate) == str2i.end())
        {
            if(r[i].status == false)
            {
                r[i].flag = false;
                continue;
            }
            str2i[r[i].plate] = car_num;
            c[car_num].plate = r[i].plate;
            c[car_num].in = r[i].timestamp;
            c[car_num].last_in = i;
            c[car_num].state = true;
            car_num++;
            r[i].flag = true;
        }
        else
        {
            int index = str2i[r[i].plate];
            if(r[i].status == false)//out
            {
                if(c[index].state == false)//car has outed;
                {
                    r[i].flag = false;
                    continue;
                }
                else//car has in, change state to out;
                {
                    c[index].state = false;
                    c[index].out = r[i].timestamp;
                    c[index].duration += c[index].out - c[index].in;
                    r[i].flag = true;
                }
            }
            else//in
            {
                if(c[index].state == false)
                {
                    r[i].flag = true;
                    c[index].state = true;
                    c[index].last_in = i;
                    c[index].in = r[i].timestamp;
                }
                else
                {
                    c[index].state = true;
                    r[c[index].last_in].flag = false;
                    c[index].in = r[i].timestamp;
                    c[index].last_in = i;
                    r[i].flag = true;
                }
            }
        }
    }

    int max_duration = 0;
    for(int i=0; i<car_num; i++)
    {
        if(c[i].state == true)
        {
            r[c[i].last_in].flag = false;
        }
        if(c[i].duration > max_duration)
        {
            max_duration = c[i].duration;
            lazy_cars.clear();
            lazy_cars.insert(c[i].plate);
        }
        else if(c[i].duration == max_duration)
        {
            lazy_cars.insert(c[i].plate);
        }
    }

    int c_record = 0;
    int c_car = 0;
    for(int i=0; i<K; i++)
    {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int timepoint = hh*3600 + mm*60 + ss;
        for(int j=c_record; j<N; j++, c_record++)
        {
            if(r[j].flag == false)
            {
                continue;
            }
            if(timepoint < r[j].timestamp)
            {
                break;
            }
            int index = str2i[r[j].plate];
            if(r[j].status == true)
            {
                c_car++;
//                c[index].in = r[j].timestamp;
//                c[index].state = true;
            }
            else if(r[j].status == false)
            {
                c_car--;
//                c[index].state = false;
//                c[index].duration += r[j].timestamp-c[index].in;
//                if(c[index].duration > max_duration)
//            	{
//                	max_duration = c[index].duration;
//                	lazy_cars.clear();
//                	lazy_cars.insert(c[index].plate);
//            	}
//            	else if(c[index].duration == max_duration)
//            	{
//                	lazy_cars.insert(c[index].plate);
//            	}
                
            }
        }
        printf("%d\n", c_car);
    }

    for(set<string>::iterator i=lazy_cars.begin(); i!=lazy_cars.end(); i++)
    {
        cout<<*i<<" ";
    }
    printf("%02d:%02d:%02d", max_duration/3600, max_duration/60%60, max_duration%60);

    
}
