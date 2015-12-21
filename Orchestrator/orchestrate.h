#ifndef ORCHESTRATE_H
#define ORCHESTRATE_H

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
class Key;

using Piece = std::shared_ptr<_Piece>;


class _Piece{
public:
    std::string name;
    std::set<std::string> perfs;
public:
    int operator-(_Piece& other);
    _Piece(std::string name, std::initializer_list<std::string> perfs);
    _Piece(std::string name, std::list<std::string> perfs);

    _Piece();
    bool operator==(const _Piece& other) const;
    bool operator<(const _Piece& other) const;
};

class Key{
public:
    class hash{
    public:
        std::size_t operator()(const Key& k) const;
    };

    std::list<Piece> mid;
    Piece front,back;
    bool operator==(const Key& other) const;
    Key(std::list<Piece> route);
};

class Orchestrator{
private:
    std::list<Piece> pcs;
public:
    void push(std::string& pName, std::list<std::string>& perfs);
    std::list<std::string> orchestrate();
    //Orchestrator();
};

struct QueueItem{
    std::list<Piece> pcs;
    std::list<Piece> route;
    int cost;
    QueueItem(std::list<Piece> pcs, std::list<Piece> route, int cost);
    bool operator<(const QueueItem& other);
};


extern std::map<std::pair<_Piece,_Piece>,int> dMap; //memoize distance
extern std::unordered_map<Key,int,Key::hash> mins;

#endif // ORCHESTRATE_H
