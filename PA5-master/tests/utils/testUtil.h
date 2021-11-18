#ifndef __TESTUTIL_H__
#define __TESTUTIL_H__

#include <sstream>
#include <vector>
#include <random>
#include <algorithm> //random_shuffle, sort
#include <unordered_set>
#include <unordered_map>
#include <time.h>
#include <string>
#include <exception>
#include <iostream>

#define FUN_TYPE T(*gen)(void)
#define FULLNESS_MAX 1000

int randomInt(){
    return rand() % INT32_MAX;
}

//generate random capital letter
int randomLetter(){
    return (rand() % ('Z' - 'A')) + 'A';
}

//generate random olen string of capital letters
std::string random8CharString(){
    std::string toReturn;
    for(int i =0; i < 8; i++){
        toReturn += randomLetter();
    }
    return toReturn;
}

//predefinition for building a generic graph given parameters and label generator
//  graphs are likely, but not guarenteeed, to be joint
template <class T>
std::stringstream buildRandomGraphGeneric(int numNodes, int fullness, FUN_TYPE, bool forceCycle=false);

//predefinition for building a generic graph given parameters and label generator
template <class T>
std::stringstream buildDisjointGraphGeneric(int numNodes, int fullness, int disjoints, FUN_TYPE);

//build a random graph using string as labels
std::stringstream buildRandomGraphStr(int numNodes, int fullness){
    return buildRandomGraphGeneric<std::string>(numNodes, fullness, random8CharString);
}

//build random graph using in as labels
std::stringstream buildRandomGraphInt(int numNodes, int fullness){
    return buildRandomGraphGeneric<int>(numNodes, fullness, randomInt);
}

//build a random graph with cycles using string labels
std::stringstream buildCyclicalGraphStr(int numNodes, int fullness){
    return buildRandomGraphGeneric<std::string>(numNodes, fullness, random8CharString, true);
}

//build a random graph with cycles using int labels
std::stringstream buildCyclicalGraphInt(int numNodes, int fullness){
    return buildRandomGraphGeneric<int>(numNodes, fullness, randomInt, true);
}

//build disjoint graphs using string labels
std::stringstream buildDisjointGraphStr(int numNodes, int fullness, int disjoints){
    return buildDisjointGraphGeneric<std::string>(numNodes, fullness, disjoints, random8CharString);
}

//build disjoint graphs using int labels
std::stringstream buildDisjointGraphInt(int numNodes, int fullness, int disjoints){
    return buildDisjointGraphGeneric<int>(numNodes, fullness, disjoints, randomInt);
}

//for graph generation
template <class T>
struct GenNode{
    T label;
    std::vector<T> adj;
};

//for graph generation
template <class T>
std::ostream& operator<<(std::ostream& os, GenNode<T>& node){
    os << node.label;
    for(auto a:node.adj){
        os << " " << a;
    }
    os << '\n';
    return os;
}

template <class T>
//fullness is % of 1000 that needs to be used
std::stringstream buildRandomGraphGeneric(int numNodes, int fullness, FUN_TYPE, bool forceCycle){
    if(fullness > FULLNESS_MAX || fullness <= 0){
        std::cout << "Illegal fullness failure, should be in range 0, " + std::to_string(FULLNESS_MAX) << std::endl;
        throw std::exception();
    }

    if(numNodes <= 0){
        std::cout << "numNodes should be greater than 0" << std::endl;
        throw std::exception();
    }

    std::unordered_set<T> uniqueSet;
    std::vector<GenNode<T>> nodeVector;

    while(nodeVector.size() < numNodes){
        //generate unique token

        GenNode<T> n;
        while(true){
            n.label = gen();
            auto p = uniqueSet.insert(n.label);
            if(p.second){break;}
        }
        
        nodeVector.push_back(n);

        //generate the edges
        for(int i =0; i < nodeVector.size()-1; i++){
            int j = rand() % FULLNESS_MAX;
            if(j > fullness){
                nodeVector.at(nodeVector.size()-1).adj.push_back(nodeVector.at(i).label);
            }
        }

        
    }

    if(forceCycle && nodeVector.size() > 1){
        while(true){
            int k = rand() % (nodeVector.size());
            GenNode<T>& cn = nodeVector.at(k);
            if(cn.adj.size() > 0){
                int j = rand() % (cn.adj.size());
                T lbl = cn.adj.at(j);
                for(int i=0; i < nodeVector.size(); i++){
                    if(nodeVector.at(i).label == lbl){
                        nodeVector.at(i).adj.push_back(lbl);
                    }
                }
                break;
            }
        }
    }

    std::stringstream toReturn;
    std::random_shuffle(nodeVector.begin(), nodeVector.end());

    for(auto o: nodeVector){
        toReturn << o;
    }
    return toReturn;
}

template <class T>
std::stringstream buildDisjointGraphGeneric(int numNodes, int fullness, int disjoints, FUN_TYPE){
    std::stringstream toReturn;

    //TODO - this function can technically return a joint graph
    // std::cout << "Warning: Build disjoint can *potentially* generate an invalid graph.\n";
    //Odds are very very low, so we will ignore this


    for(int i =0; i < disjoints; i++){
        auto t = buildRandomGraphGeneric<T>(numNodes/disjoints, fullness, gen, false);
        toReturn << t.str();
    }
    return toReturn;
}

//just check label and adj
//return true if these match
template <class V1, class V2>
bool compareVertexes(const V1& master, const V2& check, std::stringstream& report){
    if(master.label != check.label){
        report << "[TEST CASE ERROR] Label mismatch: expected " << master.label << " got " << check.label << "\n";
        return false;
    }

    bool toReturn = true;

    //copy assignment
    auto adjM = master.adj_list;
    auto checkM = check.adj_list;

    if(adjM.size() != checkM.size()){
        report << "Node labeled " << master.label << " adj list size mismatch ";
        report << "expected " << adjM.size() << ", got " << checkM.size() << "\n";
        toReturn = false;
    }

    std::sort(adjM.begin(), adjM.end());
    std::sort(checkM.begin(), checkM.end());

    auto mIter = adjM.begin();
    auto cIter = checkM.begin();

    while(mIter != adjM.end() && cIter != checkM.end()){
        if(mIter != cIter){
            mIter++;
            cIter++;
            continue;
        }

        if(mIter < cIter){
            report << "In node label " << check.label << " missing node " << *mIter << '\n';
            mIter++;
            toReturn = false;
        } else {
            report << "In node label " << check.label << " extra node " << *cIter << '\n';
            cIter++;
            toReturn = true;
        }
    }

    if(mIter != adjM.end() || cIter != checkM.end()){
        //mismatch in adj list
        if(mIter == adjM.end()){
            //extra items in check
            report << "Extra nodes in adjency list for " << check.label << ":";
            while(cIter != checkM.end()){
                report << *cIter << " ";
                cIter++;
            }
            report << '\n';
        }else{
            //items missing in check
            report << "Missing nodes in adjency list for " << check.label << ":";
            while(mIter != adjM.end()){
                report << *mIter << " ";
                mIter++;
            }
            report << '\n';
        }
        toReturn = false;
    }

    return toReturn;
}

//returns true iff matching label and aj for all nodes
template <template<class> class G1, template<class> class G2, class T>
bool compareGraphs(G1<T> master, G2<T> check){
    std::stringstream reportNotes;
    bool toReturn = true;

    for(auto k: master.node_set){
        auto lbl = k.second.label;
        try {
            auto checkV = check.at(lbl);
            bool vResult = compareVertexes(k.second, checkV, reportNotes);
            if(vResult == false){
                toReturn = false;
            }
        }catch(...){
            reportNotes << "Accessing element at " << lbl << " raised an exception.\n";
            toReturn = false;
        }
    }
    
    if(toReturn == false){
        std::cout << "\n==========DEBUG INFO==========\n" << reportNotes.str() << std::endl;
    }
    return toReturn;
}


//return true if ok
template <class T>
bool buildMap(std::stringstream& inStream, std::unordered_map<T, std::unordered_set<T>>& m, std::stringstream& report){
    std::string rawLine;
    bool toReturn = true;
    while(std::getline(inStream, rawLine)){
        //i hate it but it works

        auto colPos = rawLine.find(':');
        if(colPos == string::npos){
            report << "Missing ':' sparating label and adjacent on line " << rawLine << '\n';
            toReturn = false;
        }
        else{
            rawLine.at(colPos) = ' ';
        }

        std::stringstream line(rawLine);

        T lbl, tkn;
        line >> lbl;

        std::unordered_set<T> tknSet;

        while(line >> tkn){
            auto p = tknSet.insert(tkn);
            if(!p.second){
                report << "In line: '" << rawLine << "' token " << tkn << " appears multiple times.\n";
                toReturn = false;
            }
        }

        auto pp = m.insert(std::make_pair(lbl,tknSet));
        if(!pp.second){
            report << "While printing graph, multiple lines begin with label " << lbl << '\n';
            toReturn = false;
        }
    }
    return toReturn;
}

template <template<class> class G, class T>
bool checkDisplayGraph(G<T> master, std::stringstream& displayStream){
    std::stringstream masterStream;
    master.displayGraph(masterStream);

    std::stringstream reportNotes;

    std::unordered_set<T> displayedNodes;
    bool toReturn = true;

    std::unordered_map<T, std::unordered_set<T>> masterMap;
    std::unordered_map<T, std::unordered_set<T>> displayMap;

    //build TA graph
    if(!buildMap(masterStream, masterMap, reportNotes)){
        reportNotes << "!!!!!!CRITICAL ERROR!!!!!!!\nThe above error is in the TA code, the rest of this test case is invalid.\n";
        toReturn = false;
    }

    if(!buildMap(displayStream, displayMap, reportNotes)){
        toReturn = false;
    }

    if(toReturn){
        //now actually check these graph representation
        for(auto& v:masterMap){
            if(displayMap.count(v.first) == 0){
                reportNotes << "Could not find a node (line) starting with " << v.first << '\n';
                toReturn = false;
                continue;
            }

            std::unordered_set<T>& displaySet = displayMap.at(v.first);

            //check that all the edges appear in the student output
            for(auto& e:v.second){
                if(displaySet.count(e) == 0){
                    reportNotes << "Node " << v.first << " does not contain expected edge to " << e;
                    toReturn = false;
                }
            }

            //check that no extra items appear in the student output
            for(auto& e:displaySet){
                if(v.second.count(e) == 0){
                    reportNotes << "Node " << v.first << " contains an extra edge " << e;
                    toReturn = false;
                }
            }

        }

        for(auto& v:displayMap){
            if(masterMap.count(v.first) == 0){
                reportNotes << "Extra node labeled " << v.first << " in your output\n";
                toReturn = false;
            }
        }
    }else{
        reportNotes << "Skipping checking of remainder due to previous errors\n";
    }

    if(toReturn == false){
        std::cout << "\n==========YOUR OUTPUT==========\n" << displayStream.str();
        std::cout << "\n==========EXPECTED OUTPUT==========\n" << masterStream.str();
        std::cout << "\n==========DEBUG INFO==========\n" << reportNotes.str() << std::endl;
    }
    return toReturn;
}


//just check indegree
//return true if these match
template <class V1, class V2>
bool compareVertexesIndeg(const V1& master, const V2& check, std::stringstream& report){
    if(master.label != check.label){
        report << "[TEST CASE ERROR] Label mismatch: expected " << master.label << " got " << check.label << "\n";
        return false;
    }

    if(master.indegree != check.indegree){
        report << "Indegree mismatch on label "<< master.label <<": expected " << master.indegree << " got " << check.indegree << "\n";
        return false;
    }

    return true;
}

//returns true iff matching indegree for all nodes
//TODO - really should use function pointers and make a generic combination with compareGraphs
template <template<class> class G1, template<class> class G2, class T>
bool compareIndegrees(G1<T> master, G2<T> check){
    std::stringstream reportNotes;
    bool toReturn = true;

    for(auto k: master.node_set){
        auto lbl = k.second.label;
        try {
            auto checkV = check.at(lbl);
            bool vResult = compareVertexesIndeg(k.second, checkV, reportNotes);
            if(vResult == false){
                toReturn = false;
            }
        }catch(...){
            reportNotes << "Accessing element at " << lbl << " raised an exception.\n";
            toReturn = false;
        }
    }
    
    if(toReturn == false){
        std::cout << "\n==========DEBUG INFO==========\n" << reportNotes.str() << std::endl;
    }
    return toReturn;
}


template <template<class> class G1, template<class> class G2, class T>
bool checkTopologicalOrdering(G1<T> master, G2<T> check){
    std::stringstream reportNotes;
    bool toReturn = true;

    for(auto k: master.node_set){
        auto lbl = k.second.label;
        try {
            auto checkV = check.at(lbl);

            for(auto l: checkV.adj_list){
                //TODO = fix
                try{
                    auto lv = check.at(l);
                    if(lv.top_num < checkV.top_num){
                        reportNotes << "Illegal ordering: label " << lbl << " has top_num " << checkV.top_num << " but its descendant " << l << " has top_num " << lv.top_num << "\n";
                    }
                }catch(...){
                    reportNotes << "Accessing element at " << l << " raised an exception.\n";
                    toReturn = false;
                }
            }

        }catch(...){
            reportNotes << "Accessing element at " << lbl << " raised an exception.\n";
            toReturn = false;
        }
    }
    if (toReturn == false)
    {
        std::cout << "\n==========DEBUG INFO==========\n" << reportNotes.str() << std::endl;
    }
    return toReturn;
}

template <template<class> class G, class T>
bool checkPrintTopSort(G<T> master, std::stringstream& displayStream){
    std::stringstream reportNotes;
    bool toReturn = true;

    std::vector<T> ordering;    
    T tkn;
    while(displayStream >> tkn){
        ordering.push_back(tkn);
    }

    if(ordering.size() == 0){
        reportNotes << "Nothing could be extracted from the topological ordering.\n";
        reportNotes << "Is your output empty?\n";
        toReturn = false;
    }else{
        std::reverse(ordering.begin(), ordering.end());
        std::unordered_set<T> visitSet; //stores the nodes that have been visited already
        
        for(auto v:ordering){
            if(visitSet.count(v) != 0){
                reportNotes << "Node label " << v << " appears in topological sort multiple times.\n";
                toReturn = false;
                continue;
            }
            try{
                auto vtx = master.at(v);
                for(auto adj: vtx.adj_list){
                    if(visitSet.count(adj) == 0){
                        reportNotes << "Invalid topological ordering for node " << v << ": " << adj << " apears in its adjency list, but is not visited yet.\n";
                        toReturn = false;
                    }
                }

            }catch(...){
                reportNotes << "Error accessing node labeled " << v << "\nTerminating check.";
                toReturn = false;
                break;
            }
            visitSet.insert(v);
        }
    }

    if(toReturn == false){
        master.compute_indegree();
        master.topological_sort();

        std::stringstream masterStream;
        master.print_top_sort(masterStream);

        std::stringstream displayGraph;
        master.displayGraph(displayGraph);

        std::cout << "\n==========YOUR OUTPUT==========\n" << displayStream.str();
        std::cout << "\n==========EXPECTED OUTPUT==========\n" << masterStream.str();
        std::cout << "\n==========DEBUG INFO==========\n" << reportNotes.str() << std::endl;
        std::cout << "\n==========GRAPH===========" << displayGraph.str() << std::endl;
        std::cout << "NOTE: there can be multiple valid topological orderings for the graph.\n";
        std::cout << "This function will accept any such ordering.\n";
    }
    return toReturn;
}
#endif