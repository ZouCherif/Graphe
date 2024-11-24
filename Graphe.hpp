#pragma once
#include "Sommet.hpp"
#include "Arete.hpp"

template <typename S, typename T>
class Graphe {
public:
    std::vector<Sommet<T>*> lSommets;
    std::vector<Arete<S, T>*> lAretes;
    int prochaineClef;
    Graphe() : prochaineClef(0) {}
    ~Graphe() {
        for (auto sommet : lSommets) {
            delete sommet;
        }
        for (auto arete : lAretes) {
            delete arete;
        }
    }

    Sommet<T>* creeSommet(const T& info){
        Sommet<T>* sommet = new Sommet<T>(prochaineClef++, info);
        lSommets.push_back(sommet);
        return sommet;
    }


    Arete<S, T>* creeArete(const S& info, Sommet<T>* debut, Sommet<T>* fin){
        Arete<S, T>* arete = new Arete<S, T>(prochaineClef++, info, debut, fin);
        lAretes.push_back(arete);
        return arete;
    }



    int nombreSommets() const { return lSommets.size(); }


    int nombreAretes() const { return lAretes.size(); }


    operator std::string() const {
        std::ostringstream oss;
        oss << "Graphe - Sommets : " << nombreSommets() << ", Arêtes : " << nombreAretes();
        return oss.str();
    }


    friend std::ostream& operator<<(std::ostream& os, const Graphe<S, T>& graphe){
        os << static_cast<std::string>(graphe);
        return os;
    }


    std::vector<std::pair<Sommet<T>*, Arete<S, T>*>> adjacences(const Sommet<T>* sommet) const{
        std::vector<std::pair<Sommet<T>*, Arete<S, T>*>> adjacents;
        for (auto& arete : lAretes) {
            if (arete->estEgal(sommet, arete->debut)) {
                adjacents.push_back({ arete->fin, arete });
            } else if (arete->estEgal(sommet, arete->fin)) {
                adjacents.push_back({ arete->debut, arete });
            }
        }
        return adjacents;
    }


    std::vector<Arete<S, T>*> aretesAdjacentes(const Sommet<T>* sommet) const{
        std::vector<Arete<S, T>*> aretes;
        for (auto& arete : lAretes) {
            // if (arete->estEgal(sommet, arete->debut) || arete->estEgal(sommet, arete->fin)) {
            //     aretes.push_back(arete);
            // }
            if (arete->debut == sommet || arete->fin == sommet){
                aretes.push_back(arete);
            }
        }
        return aretes;
    }


    std::vector<Sommet<T>*> voisins(const Sommet<T>* sommet) const{
        std::vector<Sommet<T>*> voisins;
        for (auto& adj : adjacences(sommet)) {
            voisins.push_back(adj.first);
        }
        return voisins;
    }


    Arete<S, T>* getAreteParSommets(const Sommet<T>* s1, const Sommet<T>* s2) const{
        for (auto& arete : lAretes) {
        if (arete->estEgal(s1, s2)) {
            return arete;
        }
        }
        return nullptr;
    }


    Graphe(const Graphe<S, T>& g) : prochaineClef(g.prochaineClef) {
        for (auto sommet : g.lSommets) {
            lSommets.push_back(new Sommet<T>(*sommet));
        }
        for (auto arete : g.lAretes) {
            lAretes.push_back(new Arete<S, T>(*arete));
        }
    }


    const Graphe<S, T>& operator=(const Graphe<S, T>& g){
        
    }
};


