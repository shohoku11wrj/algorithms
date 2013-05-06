#include <iostream>
#include <map>
using namespace std;

int main()
{
	int a[] = {1,9,5,6,3,4,23,456,32,2,41,8,34}; //数组
	map<int,int> m;
	int sum = 10; //给定的整数
	int count = sizeof(a)/sizeof(int);
	for(int i=0; i < count; i++) {
		m.insert(map<int,int>::value_type(sum-a[i], a[i])); //放到hash map中
	}
	for(int i=0, pair=1; i < count; i++) {
		if(m.find(a[i])->second == sum-a[i] 
				&& m.find(a[i])->first < sum-a[i]) {
			cout << "pair " << pair << ": " << a[i] << "," << sum-a[i]  << endl; //hash值查找
			pair++;
		}
	}
	return 0;
}
