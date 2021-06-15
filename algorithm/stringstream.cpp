// #include <bits/stdc++.h>

// using namespace std;
// int main(){
//   float num;
//   stringstream stream1;
//   string string1 = "25 1 3 .235\n1111111\n222222";
//   stream1.str(string1);
//   while( stream1 >> num )cout << "num: " << num << endl;
// }

// #include <bits/stdc++.h>

// using namespace std;
// int main(){
//   string str1 = "23 259 .326 22 a 15"; 
//   string str2 = "1 263avj 3135df 3235 baij af9i39a fklk30"; 

//   stringstream ss(str1); 
//   string k; 

//   while(ss >> k) cout << k << endl; 

//   ss.clear(); 
//   ss.str(str2); 

//   while(ss >> k) cout << k << endl;
// }

// #include <bits/stdc++.h>

// using namespace std;
// int main(){
//   vector <string> input(3, "");	// given input
//   input[0] = "1 Kim 89";
//   input[1] = "2 Moon 100";
//   input[2] = "3 Chan 78";

//   for(int i = 0; i < input.size(); i++)
//   {
//     int num, score;
//     string name;

//     stringstream ss;	
//     ss.str(input[i]);

//     ss >> num;
//     ss >> name;
//     ss >> score;

//     cout << num << " " << name << " " << score << endl;
//   }
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//   istringstream iss("test 123 123hah ahha");
//   string str, str1, str2;
//   int inta;

//   cout<< iss.str() <<endl;
//   iss >> str >> str1 >> str2 >> inta;
//   cout<<"str  : "<< str  <<endl;
//   cout<<"str1 : "<< str1 <<endl;
//   cout<<"str2 : "<< str2 <<endl;
//   cout<<"inta : "<< inta <<endl;
// }

#include<iostream>
#include<sstream>

int main() {
  std::ostringstream oss;
  int inta = 10;
  std::string str = " test_string";
  oss << "test " << inta << str <<std::endl;
  std::cout<< oss.str();
}