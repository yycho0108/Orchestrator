#include <vector>
#include <set>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <iterator>

class Piece{
	public:
		std::string name;
		std::set<std::string> perfs;
	public:
		int operator-(Piece& other){ // cost of transition = distance between nodes
			std::set<std::string> v;
			std::set_difference(perfs.begin(),perfs.end(), other.perfs.begin(),other.perfs.end(),std::inserter(v,v.begin()));
			return v.size();
		}
		Piece(std::string name, std::initializer_list<std::string> perfs):name{name},perfs{perfs}{
		};
		bool operator==(const Piece& other) const{
			return name == other.name;
		}
		bool operator<(const Piece& other) const{
			return name < other.name;
		}
};

class Path{
	public:
		std::list<Piece> path;
		class hash{
			public:
			std::size_t operator()(const Path& p) const{
				std::size_t res = 0;
				for(auto l : p.path){
					res ^= std::hash<std::string>{}(l.name);
				}
				//do not call this on empty path!!
				return res;
			}
		};
		bool operator==(const Path& other) const{
			if (size() == other.size()){ //same size
				if (size() == 0)
					return true;
				if ((front() == other.front() && back() == other.back()) //same poles
					|| (front() == other.back() && back() == other.front())){
						if (size() >= 2){
							std::vector<Piece> v_1(++path.begin(),--path.end()); //same middle
							std::vector<Piece> v_2(++other.path.begin(), --other.path.end());
							
							std::sort(v_1.begin(),v_1.end());
							std::sort(v_2.begin(),v_2.end());
							return v_1 == v_2;
						}else{
							return true;
						}
					}
			}
			return false;
		}
		Path(std::list<Piece>& path):path{path}{};
		int size() const {return path.size();}
		const Piece& front() const {return path.front();}
		const Piece& back() const {return path.back();}

};

std::unordered_map<Path,int,Path::hash> mins;

bool confirm(std::list<Piece> pcs, int cost){ //just copy, to sort & compare.
	pcs.sort();
	auto p = Path(pcs);
	auto i = mins.find(p);
	if (i == mins.end()){
		mins.insert(std::pair<Path,int>(pcs,cost));
		return true;
	}else if (i->second > cost){
	   i->second = cost;
		return true;
	}
	return false;
}

struct QueueItem{
	std::list<Piece> pcs;
	std::list<Piece> route;
	int cost;
	QueueItem(std::list<Piece> pcs, std::list<Piece> route, int cost):cost{cost}{
	this->route.swap(route);
	this->pcs.swap(pcs);
	};
};

std::list<QueueItem> Queue;
int minCost = INT32_MAX;
std::list<Piece> minRoute;

void HeldKarp(std::list<Piece>& pcs,std::list<Piece>& route, int cost){
	if(!confirm(pcs, cost))
		return;
	if(pcs.size() == 0){
		if(minCost> cost){
		   minCost = cost;
		   minRoute.swap(route);
		}
	}
	//compare signature
	//if not lower cost than existing signature, return.
	for(auto i = pcs.begin(); i!=pcs.end();){
		auto p = *i;
		int c = cost + (p - route.back());
		
		route.push_back(p);
		i = pcs.erase(i);
		
		Queue.push_back(QueueItem(pcs,route,c)); //BFS
		
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
	pcs.push_back(Piece("Untitled",{Jacob,Subhash,Jared,Jonah,Duncan,Riley}));
    pcs.push_back(Piece("MonologueOfAMadman",{Serena,Nathan,Alex}));
    pcs.push_back(Piece("ASongOfFriendship",{Serena,Anne,Duncan,Katie,Julia}));
    pcs.push_back(Piece("AutomaticBeedo",{Nathan,Serena,Duncan,Bryan,Forrest,Max}));
    pcs.push_back(Piece("CornishGameHenWaltz",{Nathan,Lydia,Serena,Anne,Duncan}));
    pcs.push_back(Piece("Rage",{Forrest,Max}));
    pcs.push_back(Piece("TangoAccelerando",{Nathan}));
    pcs.push_back(Piece("LostWood",{Eric,Louise}));
    pcs.push_back(Piece("VariationsonDSharpDiminished",{Serena,Nathan,Anne,Duncan}));
    pcs.push_back(Piece("ThatSummer",{Anne}));
    pcs.push_back(Piece("ToSleep",{Claire,Lydia,Linnea,Bryan}));
    pcs.push_back(Piece("AFolkSong",{Linnea,Bryan,Jonah,Max}));
    pcs.push_back(Piece("IGottaFever",{Jared,Alex,Forrest,Linnea,Jonah}));
    pcs.push_back(Piece("Sigh",{Eric,Julia,Anne}));
    pcs.push_back(Piece("Wandering",{Duncan,Eric,Linnea,Anne}));
    pcs.push_back(Piece("GrooveMusic",{Serena,Anne,Jonah,Duncan,Michael,Riley}));

	//initialize pcs
	for(auto i = pcs.begin(); i != pcs.end();){
		auto p = *i;
		i = pcs.erase(i);
		auto l  = std::list<Piece>{};
		l.push_back(p);
		Queue.push_back(QueueItem(pcs,l,0));
		pcs.insert(i,p);
	}

	/*
	 * for(auto q : Queue){
		std::cout << q.route.size() << " --> "<< std::endl;
		for(auto p : q.route){
			std::cout << p.name << ' ';
		}
		std::cout << std::endl;
	}
	*/

	while (!Queue.empty()){
		auto q = Queue.front();
		HeldKarp(q.pcs,q.route,q.cost);

		/*for(auto p : q.route){
			std::cout << p.name << ' ';
		}

		std::cout << std::endl;*/
		Queue.pop_front();
	}
	
	for(auto p : minRoute){
		std::cout << p.name << ' ';
	}
	std::cout << std::endl;

	std::cout << minCost << std::endl;
	
	//initialize Queue
	//while queue is not empty perform heldkarp
	//get mincost
}
