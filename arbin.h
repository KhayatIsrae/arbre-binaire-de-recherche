
class noeud{
    int valeur;
    noeud* gauche;
    noeud* droit;
    friend class arbre;
public:
        noeud(int val): valeur(val), gauche(nullptr), droit(nullptr) {}

};

class arbre{
    noeud* racine;
public:
    arbre(): racine(nullptr) {}
    ~arbre();
    void inserer(int val);
    noeud* rechercher(int val);
    void insererRec(noeud* n, int val);
    void supprimer(int val);
    noeud* supprimerRec(noeud* n, int val);
};

void arbre::insererRec(noeud* n, int val) {
    if (val < n->valeur) {
        if (n->gauche == nullptr) {
            n->gauche = new noeud(val);
        } else {
            insererRec(n->gauche, val);
        }
    } else {
        if (n->droit == nullptr) {
            n->droit = new noeud(val);
        } else {
            insererRec(n->droit, val);
        }
    }
}

void arbre::inserer(int val) {
    if (racine == nullptr) {
        racine = new noeud(val);
    } else {
        insererRec(racine, val);
    }
}

noeud* arbre::rechercher(int val){
    if(this->racine==nullptr)
        return nullptr;
    noeud * crt=this->racine;
    while (crt!=nullptr)
    {
        if(val>crt->valeur){
            crt=crt->droit;
        }else if(val<crt->valeur){
            crt=crt->gauche;
        }else
            return crt;
    }
    return nullptr;
}

noeud* arbre::supprimerRec(noeud* n, int val) {
    if (n == nullptr)
        return nullptr;

    if (val < n->valeur)
        n->gauche = supprimerRec(n->gauche, val);
    else if (val > n->valeur)
        n->droit = supprimerRec(n->droit, val);
    else {
        // Cas 1 et 2 : 0 ou 1 fils
        if (n->gauche == nullptr) {
            noeud* temp = n->droit;
            delete n;
            return temp;
        }
        else if (n->droit == nullptr) {
            noeud* temp = n->gauche;
            delete n;
            return temp;
        }

        // Cas 3 : deux fils
        noeud* temp = n->droit;
        while (temp->gauche != nullptr)
            temp = temp->gauche;

        n->valeur = temp->valeur;
        n->droit = supprimerRec(n->droit, temp->valeur);
    }
    return n;
}

void arbre::supprimer(int val) {
    racine = supprimerRec(racine, val);
}

arbre::~arbre() {
    while (racine != nullptr)
        racine = supprimerRec(racine, racine->valeur);
}