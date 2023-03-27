#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	string dataset_name = argv[1];
	string fname1 = dataset_name + "/all_graph_file.txt";
	string fname2 = dataset_name + "/result.txt";
	float sim_threshold = stof(argv[2]);
	int ged_threshold = stoi(argv[3]);

	cout<<"dataset is "<<dataset_name<<endl;
	int size1 = 0, size2 = 0;
	ifstream f1(fname1);
	ifstream f2(fname2);
	string line;
	unordered_map<int, vector<int>> mp;
	int count = 0;
	while(f1)
	{
		getline(f1, line);
        if(line == "") break;
        vector <string> tokens;
        stringstream ss(line);
        string temp;
        while(getline(ss, temp, ' '))
        {
            tokens.push_back(temp);
        }
        float simScore = stof(tokens[2]);
        if(simScore < sim_threshold) continue;
        size1++;

        mp[stoi(tokens[0])].push_back(stoi(tokens[1]));
        mp[stoi(tokens[1])].push_back(stoi(tokens[0]));
	}

	while(f2)
	{
		getline(f2, line);
        if(line == "") break;
        vector <string> tokens;
        stringstream ss(line);
        string temp;
        while(getline(ss, temp, ' '))
        {
            tokens.push_back(temp);
        }
        int gedScore = stoi(tokens[2]);
        if(gedScore > ged_threshold) continue;
        size2++;
        auto vec = mp[stoi(tokens[0])];
        if(find(vec.begin(), vec.end(), stoi(tokens[1])) != vec.end())
        	count++;
	}
	f1.close();
	f2.close();
	cout<<"count is "<<count<<" size1 is "<<size1<<" size2 is "<<size2<<endl;
	cout<<"precision = "<<count*1.0/size1<<endl;
	cout<<"recall = "<<count*1.0/size2<<endl;
	
	return 0;
}
