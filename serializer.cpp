
#include <iostream> 
#include <vector> 
#include<string>
#include<stdio.h>
using namespace std;

enum DATA_TYPE {INT=1,FLOAT,DEG};

class DataHolder
{
	private:   
		struct Info
		{
			string name;
			int dataType;	
			int dataValue;
		};

		vector<Info> dataBase;
	public:
		DataHolder():dataBase() {}; 
		~DataHolder(){};
		void print() 
		{ 
			/// print the value of vector 
			for (int itr = 0; itr < dataBase.size(); itr++)
			{ 
				std::cout<< dataBase[itr].name << " "; 
				std::cout<< dataBase[itr].dataType << " ";
				std::cout<< dataBase[itr].dataValue <<" "; 
				std::cout<<endl;
			}	
		} 
		// void AddData(string ,int,int);
		void AddData(string Nam, int type, int val)
		{
			Info newData;
			newData.name = Nam;
			newData.dataType =type;
			newData.dataValue = val;

			dataBase.push_back(newData);
		}

		void updateData(string Nam, int type, int val)
		{
			for (vector<Info>::iterator it = dataBase.begin(); it != dataBase.end(); ++it)
			{ 
				if(((*it).name == Nam) && ((*it).dataType == type))
				{
					(*it).dataValue = val;
				}


			}
			cout<<"printing the updated"<<endl;
			print();


		}

};



int main() 
{ 

	DataHolder obj; 
	/*****************Need to do Json parse before this.*********************/
	obj.AddData("temp",INT,30);
	obj.AddData("temp1",FLOAT,30);	
	obj.AddData("temp2",DEG,30);
	obj.AddData("temp3",INT,30);
	obj.print(); 
	obj.updateData("temp3",INT,50);
	return 0; 
} 


