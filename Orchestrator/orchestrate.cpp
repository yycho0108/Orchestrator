#include "orchestrate.h"

std::map<std::pair<_Piece,_Piece>,int> dMap; //memoize distance
std::unordered_map<Key,int,Key::hash> mins;
std::list<QueueItem> Queue;
int minCost = INT32_MAX;
std::list<Piece> minRoute;


// Piece

int _Piece::operator-(_Piece& other){ // cost of transition = distance between nodes
    auto p = std::make_pair(*this,other);
    if(dMap.find(p) != dMap.end())
        return dMap[p];
    else{
        std::set<std::string> v;
        std::set_difference(perfs.begin(),perfs.end(), other.perfs.begin(),other.perfs.end(),std::inserter(v,v.begin()));
        return dMap[p] = v.size();
    }
}
_Piece::_Piece(std::string name, std::string composer, std::initializer_list<std::string> perfs):name{name},perfs{perfs}{
};
_Piece::_Piece(std::string name, std::string composer, std::list<std::string> perfs):name{name},perfs{perfs.begin(),perfs.end()}{
};

_Piece::_Piece(){};
bool _Piece::operator==(const _Piece& other) const{
    return name == other.name;
}
bool _Piece::operator<(const _Piece& other) const{
    return name < other.name;
}


//Key

std::size_t Key::hash::operator()(const Key& k) const{
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

bool Key::operator==(const Key& other) const{
    if((front == other.front && back == other.back) ||
            (front == other.back && back == other.front)){
        return mid == other.mid;
    }
    return false;
}

Key::Key(std::list<Piece> route){
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


int maxFind(Key& k){
    auto i = mins.find(k);
    if (i == mins.end())
        return INT32_MAX;
    else
        return i->second;
}

//Queue
QueueItem::QueueItem(std::list<Piece> pcs, std::list<Piece> route, int cost):cost{cost}{
    this->route.swap(route);
    this->pcs.swap(pcs);
}

bool QueueItem::operator<(const QueueItem& other){
    return cost < other.cost;
}

bool confirm(std::list<Piece>& route, int cost){ //just copy, to sort & compare.
    auto k = Key(route);
    if (maxFind(k) >= cost){
        mins[k] = cost;
        return true;
    }
    return false;
}

void enqueue(std::list<Piece>& pcs, std::list<Piece>& route, int cost){
    auto k = Key(route);
    if (maxFind(k) > cost){
        mins[k] = cost;
        Queue.push_back(QueueItem(pcs,route,cost));
    }
}


//Custom Held-Karp for TSP
void HeldKarp(QueueItem& item){
    auto& pcs = item.pcs;
    auto& route = item.route;
    auto& cost = item.cost;

    if(!confirm(route, cost))
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


void Orchestrator::push(std::string& pName, std::string& cName, std::list<std::string>& perfs){
    pcs.push_back(Piece(new _Piece(pName,cName,perfs)));
    //not yet dealing with composer names
}

std::list<std::string> Orchestrator::orchestrate(){
    minRoute.clear();
    dMap.clear();
    mins.clear();
    Queue.clear();
    minCost = INT32_MAX;

    for(auto i = pcs.begin(); i != pcs.end();){
        auto p = *i;
        i = pcs.erase(i);
        auto l  = std::list<Piece>{};
        l.push_back(p);
        Queue.push_back(QueueItem(pcs,l,0));
        pcs.insert(i,p);
    }
    int index = 0;
    while (!Queue.empty()){
        HeldKarp(Queue.front());
        Queue.pop_front();
        ++index;
    }


    std::list<std::string> l;
    for(auto p : minRoute){
        l.push_back(p->name);
    }
    return l;
}
