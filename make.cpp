#include <iostream>
#include <filesystem>
#include <string>
#include <stdlib.h>

using namespace std;
using namespace std::filesystem;

char c[200];
//Convert string to char*
void sc(string t){
	int i;
	for(i=0;i<t.length();i++){
		c[i]=t[i];
	}
	c[i]='\0';
}
int main() {
	system("clear");
	//path = path to code, oup = what should be executed, t = files in the directory
    std::string path = "../code",oup="g++ -c",t,del="rm";
    for (const auto & entry : directory_iterator(path)){
		t=entry.path();
		if(t.substr(t.length()-4)==".cpp"||t.substr(t.length()-4)==".hpp"||t.substr(t.length()-2)==".h"){
			oup+=" ";oup+=entry.path();}}
	sc(oup);
	system(c);
	oup="g++";
	path=".";
    for (const auto & entry : directory_iterator(path)){
		t=entry.path();
		if(t.substr(t.length()-2)==".o"){
			oup+=" ";oup+=entry.path();del+=" ";del+=entry.path();}}
	oup+=" -o ../output -lsfml-graphics -lsfml-window -lsfml-system";
	sc(oup);	system(c);
	sc(del);	system(c);
	del="rm";
	path = "../code";
    for (const auto & entry : directory_iterator(path)){
		t=entry.path();
		if(t.substr(t.length()-4)==".gch"){
			del+=" ";del+=entry.path();}}

	sc(del);system(c);
	system("../output");
	
}

