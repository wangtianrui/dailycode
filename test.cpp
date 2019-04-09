#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<sstream>
using namespace std;
void showVector(vector<string> v)
{
	for(int i = 0 ; i < v.size() ; i++)
	{
		cout << v.at(i) << endl ;
	}
}

void showSet(set<string> s)
{
	set<string>::iterator it ;
	for(it = s.begin() ; it != s.end() ; it++)
	{
		cout << *it << endl ;
	}
}

void showMap(map<int,string> m)
{
	map<int,string>::iterator iter ;
	for(iter = m.begin();iter!=m.end();iter++)
	{
		cout<<iter->first<<":"<<iter->second<<endl;
	}
}


int main()
{
	vector<string> v1 ;

	string str2 = "xixi";
	string str1 (str2) ;
	str2 = str2.substr(1,3);
	//cout << str2 << endl ;
	//cout << str1 <<endl;
	str1 += "haha";
	//cout << str1 << endl ;
	v1.push_back(str1);
	v1.push_back(str2);
	//showVector(v1);
	set<string> s ;
	s.insert(str1);
	s.insert(str2);
	s.insert(str1);
	s.insert(str1);
	s.insert("str1");
	//showSet(s);
	map<int,string> m;
	for(int i = 0 ; i < 10 ; i++)
	{
		stringstream os;
		os << i ;
		string temp = os.str();
		//m.insert(pair<int,string>(i,"student"+temp));
		
		os << i *100 ;
		temp = os.str();
		m.insert(pair<int,string>(i,"student"+temp));
	}
	showMap(m);
	return 0;
}