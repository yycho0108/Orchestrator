#include <list>
#include <string>
#include <iostream>
#include <sstream>

std::list<std::string> split(std::string&& s){
    std::stringstream ss(s);
    std::string item;
    std::list<std::string> l;
    while(std::getline(ss,item,';')){
        l.push_back(item);
    }
    return l;
}

int main(int argc, char* argv[]){
	auto str = split(argv[1]);
	for(auto s:str){
		std::cout << s << ',';
	}
	std::cout << std::endl;

}
