#include <list>
#include <set>
#include <unordered_map>
#include <memory>
#include <algorithm>
#include <utility>

//class node;
class _node;
class path;
//typedef std::shared_ptr<node> node;
using node = std::shared_ptr<_node>;

class _node{
	public:
		std::string name;
		std::set<std::string> perfs; //performers
		_node(std::string& name, std::set<std::string>& perfs):name(name),perfs(perfs){
		}
		~_node(){
		}
		int operator -(_node& other){
			std::vector<std::string> v(std::max(perfs.size(),other.perfs.size()));
			auto it = std::set_difference(perfs.begin(),perfs.end(), other.perfs.begin(),other.perfs.end(),v.begin());
			v.resize(it - v.begin());
			return v.size();
		}
};

class path{
	friend class _dMap;
	class hash{
		std::size_t operator()(const path& p){
			std::size_t res = 0;
			for(auto l : p.nodes){
				res ^= std::hash<std::string>{}(l->name);
			}
			//do not call this on empty path!!
			return res;
		}
	};
	std::vector<node> nodes;
	int cost;
	path(node begin, node end){
		nodes.push_back(begin);
		nodes.push_back(end); 
		cost = *end - *begin;
	}
	bool operator==(path& other){
		if (size() == other.size()){ //same size
			if ((front() == other.front() && back() == other.back()) //same poles
				|| (front() == other.back() && back() == other.front())){
				std::vector<node> v_1(nodes.begin()+1,nodes.end()-1); //same middle
				std::vector<node> v_2(other.nodes.begin()+1, other.nodes.end()-1);
				std::sort(v_1.begin(),v_1.end());
				std::sort(v_2.begin(),v_2.end());
				return v_1 == v_2;
				}
		}
		return false;
	
	node& front(){return nodes.front();}
	node& back(){return nodes.back();}
	std::size_t size(){return nodes.size();}
};

class _dMap{
	std::unordered_map<path,int,path::hash> distMap;
	public:
		void set(path& p){
			distMap[p] = p.cost;
		}
		bool set(path& p,int cost){
			//check if exists prior?
			if (distMap[p] > cost){ //only when greater (to avoid repetition)
				distMap[p] = cost;
				return true;
			}
			return false;
		}
		int get(path& p){
			return distMap[p];
		}
} dMap;


int main(){
	// initialize path
	return 0;
}
