#from sets import Set
from itertools import permutations

class Performer:
    def __init__(self,name):
        self.name = name;
    def __eq__(self,other):
        return self.name == other.name;
    def __ne__(self,other):
        return self.name != other.name;
    def __hash__(self):
        return hash(self.name);
class Piece:
    def __init__(self,name,performers):
        self.name = name;
        self.performers = set(performers);
        pass;
    def __eq__(self,other):
        return self.name == other.name;
    def __ne__(self,other):
        return self.name != other.name;
    def __hash__(self):
        return hash(self.name);

class Optimizer:
    def __init__(pieces):
        self.pieces = pieces;
        self.minCost = float('inf');
        pass;
    def dist(p1,p2):
        return len(p1.performers-p2.performers);
    def optimize():


def getCost(opt):
    cost = 0;
    n = len(opt);
    for i in range(n-1):
        cost += len(opt[i+1].performers - opt[i].performers);#newcomers
        #rudimentary cost calculation based on number of new performers
    return cost;

class Path:
    def __init__(head,tail):
        self.head = head;
        self.tail = tail;
        self.body = set(); #list of all the places in between
        self.cost = 0;
    def append(self,other):
        self.tail = other.tail;
        self.body |= other.body;
        self.body.add(other.start);
        self.cost += other.cost;
    def prepend(self,other):
        self.head = other.head;
        self.body |= other.body;
        self.body.add(other.tail);
        self.cost += other.cost;

def optimize(pieces):
    minCost = float('inf');
    optimal = [];
    n = len(pieces);
    #p = permutations(pieces,n);
    #for opt in p:
    #    c = getCost(opt);
    #    if c < minCost:
    #        minCost = c;
    #        optimal = opt;
    #return optimal;

def main():
    Jacob = Performer('Jacob');
    Subhash = Performer('Subhash');
    Jared = Performer('Jared');
    Jonah = Performer('Jonah');
    Duncan = Performer('Duncan');
    Riley =  Performer('Riley');
    Serena =  Performer('Serena');
    Nathan =  Performer('Nathan');
    Alex = Performer('Alex');
    Anne = Performer('Anne');
    Katie = Performer('Katie');
    Julia = Performer('Julia');
    Bryan = Performer('Bryan');
    Forrest =  Performer('Forrest');
    Max = Performer('Max');
    Eric = Performer('Eric');
    Louise = Performer('Louise');
    Claire = Performer('Claire');
    Lydia = Performer('Lydia');
    Linnea = Performer('Linnea');
    Michael = Performer('Michael');
    
    Untitled = Piece('Untitled',[Jacob,Subhash,Jared,Jonah,Duncan,Riley]);
    MonologueOfAMadman = Piece('MonologueOfAMadman',[Serena,Nathan,Alex]);
    ASongOfFriendship = Piece('ASongOfFriendship',[Serena,Anne,Duncan,Katie,Julia]);
    AutomaticBeedo = Piece('AutomaticBeedo',[Nathan,Serena,Duncan,Bryan,Forrest,Max]);
    CornishGameHenWaltz = Piece('CornishGameHenWaltz',[Nathan,Lydia,Serena,Anne,Duncan]);
    Rage = Piece('Rage',[Forrest,Max]);
    TangoAccelerando = Piece('TangoAccelerando',[Nathan]);
    LostWood = Piece('LostWood',[Eric,Louise]);
    VariationsonDSharpDiminished = Piece('VariationsonDSharpDiminished',[Serena,Nathan,Anne,Duncan]);
    ThatSummer = Piece('ThatSummer',[Anne]);
    ToSleep = Piece('ToSleep',[Claire,Lydia,Linnea,Bryan]);
    AFolkSong = Piece('AFolkSong',[Linnea,Bryan,Jonah,Max]);
    IGottaFever = Piece('IGottaFever',[Jared,Alex,Forrest,Linnea,Jonah]);
    Sigh = Piece('Sigh',[Eric,Julia,Anne]);
    Wandering = Piece('Wandering',[Duncan,Eric,Linnea,Anne]);
    GrooveMusic = Piece('GrooveMusic',[Serena,Anne,Jonah,Duncan,Michael,Riley]);

    o = Optimizer([
        Untitled,
        MonologueOfAMadman,
        ASongOfFriendship,
        AutomaticBeedo,
        CornishGameHenWaltz,
        Rage,
        TangoAccelerando,
        LostWood,
        VariationsonDSharpDiminished,
        ThatSummer,
        ToSleep,
        AFolkSong,
        IGottaFever,
        Sigh,
        Wandering,
        GrooveMusic,
        ]);
    o.optimize();

def test():
    j = Performer('j');
    k = Performer('k');
    l = Performer('l');
    m = Performer('m');
    alpha = Piece('alpha',[j,k,l]);
    beta = Piece('beta',[k,m]);
    print(alpha.performers-beta.performers);
def test_2():
    l = ['one','two','three'];
    print(list(permutations(l,3)));
if __name__ == "__main__":
    main();
    #test();
    #test_2();
