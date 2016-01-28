#include <vector>
#include <set>
#include <list>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <ctime>
#include <memory>

class _Piece;
using Piece = std::shared_ptr<_Piece>;

std::map<std::pair<_Piece,_Piece>,int> dMap; //memoize distance


class _Piece{
	public:
		std::string name;
		std::set<std::string> perfs;
	public:
		int operator-(_Piece& other){ // cost of transition = distance between nodes
			auto p = std::make_pair(*this,other);
			if(dMap.find(p) != dMap.end())
				return dMap[p];
			else{
				std::set<std::string> v;
				std::set_difference(perfs.begin(),perfs.end(), other.perfs.begin(),other.perfs.end(),std::inserter(v,v.begin()));
				return dMap[p] = v.size();
			}
		}
		_Piece(std::string name, std::initializer_list<std::string> perfs):name{name},perfs{perfs}{
			
		};
		_Piece(){};
		bool operator==(const _Piece& other) const{
			return name == other.name;
		}
		bool operator<(const _Piece& other) const{
			return name < other.name;
		}
};


class Key{
	public:
		std::list<Piece> mid;
		Piece front,back;
		class hash{
			public:
			std::size_t operator()(const Key& k) const{
				std::size_t res = 0;
				for(auto& l : k.mid){
					res ^= std::hash<std::string>{}(l->name);
				}
				if (k.front)
					res ^= std::hash<std::string>{}(k.front->name);
				if (k.back)
					res ^= std::hash<std::string>{}(k.back->name);
				return res;
			}
		};
		bool operator==(const Key& other) const{
			if((front == other.front && back == other.back) ||
					(front == other.back && back == other.front)){
				return mid == other.mid;
			}
			return false;
		}
		Key(std::list<Piece> route){
			this->front = nullptr;
			this->back = nullptr;
			if(route.size() >= 2){
				front = route.front();
				back = route.back();
				route.pop_back();
				route.pop_front();
				route.sort();
			} //else 0 or 1
			this->mid.swap(route);
		}
};

std::unordered_map<Key,int,Key::hash> mins;
int maxFind(Key& k){
	auto i = mins.find(k);
	if (i == mins.end())
		return INT32_MAX;
	else
		return i->second;
}
struct QueueItem{
	std::list<Piece> pcs;
	std::list<Piece> route;
	int cost;
	QueueItem(std::list<Piece> pcs, std::list<Piece> route, int cost):cost{cost}{
	this->route.swap(route);
	this->pcs.swap(pcs);
	};
	bool operator<(const QueueItem& other){
		return cost < other.cost;
	}
};


std::list<QueueItem> Queue;
bool confirm(std::list<Piece>& route, int cost){ //just copy, to sort & compare.
	auto k = Key(route);
	if (maxFind(k) >= cost){
		mins[k] = cost;
		return true;
	}
	return false;
}


int minCost = INT32_MAX;
std::list<Piece> minRoute;

void enqueue(std::list<Piece>& pcs, std::list<Piece>& route, int cost){
	auto k = Key(route);
	if (maxFind(k) > cost){
		mins[k] = cost;
		Queue.push_back(QueueItem(pcs,route,cost));
	}
}

void HeldKarp(QueueItem& item){
	auto& pcs = item.pcs;
	auto& route = item.route;
	auto& cost = item.cost;

	if(!confirm(route, cost) || minCost < cost)
		return;
	if(pcs.size() == 0 && minCost > cost){
		minCost = cost;
		minRoute.swap(route);
		return;
	}
	//compare signature
	//if not lower cost than existing signature, return.
	for(auto i = pcs.begin(); i!=pcs.end();){
		auto p = *i;
		int c = cost + (*p - *route.back());
		
		route.push_back(p);
		i = pcs.erase(i);
		enqueue(pcs,route,c);		
		
		pcs.insert(i,p);
		route.pop_back();
	}
}

int main(){
	std::list<Piece> pcs;
	std::string Jacob = ("Jacob");
    std::string Subhash = ("Subhash");
    std::string Jared = ("Jared");
    std::string Jonah = ("Jonah");
    std::string Duncan = ("Duncan");
    std::string Riley =  ("Riley");
    std::string Serena =  ("Serena");
    std::string Nathan =  ("Nathan");
    std::string Alex = ("Alex");
    std::string Anne = ("Anne");
    std::string Katie = ("Katie");
    std::string Julia = ("Julia");
    std::string Bryan = ("Bryan");
    std::string Forrest =  ("Forrest");
    std::string Max = ("Max");
    std::string Eric = ("Eric");
    std::string Louise =("Louise");
    std::string Claire = ("Claire");
    std::string Lydia = ("Lydia");
    std::string Linnea = ("Linnea");
    std::string Michael = ("Michael");
	pcs.push_back(Piece(new _Piece("Untitled",{Jacob,Subhash,Jared,Jonah,Duncan,Riley})));
    pcs.push_back(Piece(new _Piece("MonologueOfAMadman",{Serena,Nathan,Alex})));
    pcs.push_back(Piece(new _Piece("ASongOfFriendship",{Serena,Anne,Duncan,Katie,Julia})));
    pcs.push_back(Piece(new _Piece("AutomaticBeedo",{Nathan,Serena,Duncan,Bryan,Forrest,Max})));
    pcs.push_back(Piece(new _Piece("CornishGameHenWaltz",{Nathan,Lydia,Serena,Anne,Duncan})));
    pcs.push_back(Piece(new _Piece("Rage",{Forrest,Max})));
    pcs.push_back(Piece(new _Piece("TangoAccelerando",{Nathan})));
    pcs.push_back(Piece(new _Piece("LostWood",{Eric,Louise})));
    pcs.push_back(Piece(new _Piece("VariationsonDSharpDiminished",{Serena,Nathan,Anne,Duncan})));
    pcs.push_back(Piece(new _Piece("ThatSummer",{Anne})));
    pcs.push_back(Piece(new _Piece("ToSleep",{Claire,Lydia,Linnea,Bryan})));
    pcs.push_back(Piece(new _Piece("AFolkSong",{Linnea,Bryan,Jonah,Max})));
    pcs.push_back(Piece(new _Piece("IGottaFever",{Jared,Alex,Forrest,Linnea,Jonah})));
    pcs.push_back(Piece(new _Piece("Sigh",{Eric,Julia,Anne})));
    pcs.push_back(Piece(new _Piece("Wandering",{Duncan,Eric,Linnea,Anne})));
    pcs.push_back(Piece(new _Piece("GrooveMusic",{Serena,Anne,Jonah,Duncan,Michael,Riley})));
	//initialize pcs
	for(auto i = pcs.begin(); i != pcs.end();){
		auto p = *i;
		i = pcs.erase(i);
		auto l  = std::list<Piece>{};
		l.push_back(p);
		Queue.push_back(QueueItem(pcs,l,0));
		pcs.insert(i,p);
	}
	auto start = std::clock();
	int index = 0;	
	while (!Queue.empty()){
		HeldKarp(Queue.front());
		Queue.pop_front();
		++index;
	}
	
	for(auto p : minRoute){
		std::cout << p->name << ' ';
	}
	std::cout << std::endl;
	std::cout << "Took " << double(std::clock() - start)/CLOCKS_PER_SEC << "Seconds" << std::endl;
	std::cout << "Translation Cost : " << minCost << std::endl;
	std::cout << "Took " << index << "Operations" << std::endl;
}
